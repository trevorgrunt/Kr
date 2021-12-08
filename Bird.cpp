#include "Bird.hpp"

namespace Pogosian
{
	Bird::Bird(GameDataRef data) : _data(data)
	{
		_animationIterator = 0; // Обнуляем текущий кадр

		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 1")); // Делам push.back для всех 4х ассетов, чтобы анимировать
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 2"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 3"));
		_animationFrames.push_back(_data->assets.GetTexture("Bird Frame 4"));

		_birdSprite.setTexture(_animationFrames.at(_animationIterator)); // Ставим текстуры

		_birdSprite.setPosition((_data->window.getSize().x / 4) - (_birdSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_birdSprite.getGlobalBounds().width / 2)); // Ставим позицию птицы, иначе она будет находится в левом верхнем углу экрана

		_birdState = BIRD_STATE_STILL; // Изначальное состояние

		sf::Vector2f origin = sf::Vector2f(_birdSprite.getGlobalBounds().width / 2, _birdSprite.getGlobalBounds().height / 2);
		
		_birdSprite.setOrigin(origin);

		_rotation = 0; // Угол вращения по умолчанию 
	}

	void Bird::Draw()
	{
		_data->window.draw(_birdSprite);
	}

	void Bird::Animate(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size()) // Если время больше длительности анимации поделить на кадры анимации
		{
			if (_animationIterator < _animationFrames.size() - 1) // Если есть хотя бы одна анимации которую мы можем сменить
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0; // Обнуляем текущий кадр
			}

			_birdSprite.setTexture(_animationFrames.at(_animationIterator)); // Ставим новую текстуру
			_clock.restart(); // Перезапускаем время
		}
	}

	void Bird::Update(float dt)
	{
		if (BIRD_STATE_FALLING == _birdState) // Если состояние птицы это падение вниз
		{
			_birdSprite.move(0, GRAVITY * dt); // Двигаем птицу по оси Y вниз гравитацией, dt для все той же цели - чтобы игра не зависела от частоты кадров

			_rotation += ROTATION_SPEED * dt; // Прибавляем к вращению скорость вращения умноженую на дельта время

			if (_rotation > 25.0f) // Эта проверка нужна, чтобы вращение не было слишком сильным и шло вверх
			{
				_rotation = 25.0f; 
			}

			_birdSprite.setRotation(_rotation); // Задаем вращение 
		}
		else if (BIRD_STATE_FLYING == _birdState) // Если состояние птицы это подъем вверх (полет)
		{
			_birdSprite.move(0, -FLYING_SPEED * dt); // Двигаем птицу по Y вверх

			_rotation -= ROTATION_SPEED * dt; // Вычитаем от вращения скорость вращения умноженую на дельта время

			if (_rotation < -25.0f) // Эта проверка нужна, чтобы вращение не было слишком слабым и шло вниз
			{
				_rotation = -25.0f;
			}

			_birdSprite.setRotation(_rotation); // Задаем вращение  
		}

		if (_movementClock.getElapsedTime().asSeconds() > FLYING_DURATION) // Если прошло больше времени чем длительность полета
		{
			_movementClock.restart(); // Перезапускаем таймер
			_birdState = BIRD_STATE_FALLING; // Ставим состояние падения
		}
	}

	void Bird::Tap()
	{
		_movementClock.restart(); // Обнуляем таймер, чтобы точно знать сколько времени будет проходить после каждого клика по экрану
		_birdState = BIRD_STATE_FLYING; // Ставим постояние полета вверх
	}

	const sf::Sprite &Bird::GetSprite()
	{
		return _birdSprite; // Возвращаем спрайт птицы 
	}
}