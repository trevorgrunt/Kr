#include "Land.hpp"
#include "DEFINITIONS.hpp"

namespace Pogosian
{
	Land::Land(GameDataRef data) : _data(data)
	{
		sf::Sprite sprite(data->assets.GetTexture("Land")); // Спрайт земля
		sf::Sprite sprite2(data->assets.GetTexture("Land"));

		sprite.setPosition(0, _data->window.getSize().y - sprite.getGlobalBounds().height); // Устанавливаем позицию, 0 для того чтобы все было видимым, формула по Y позволяет сделать землю снизу
		sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y - sprite.getGlobalBounds().height);

		_landSprites.push_back(sprite); // Добавляем в вектор
		_landSprites.push_back(sprite2);
	}

	void Land::MoveLand(float dt) // Передвигаем землю
	{
		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			float movement = PIPE_MOVEMENT_SPEED * dt ; // Ставим скорость как у труб, умножаем на дельта тайм, чтобы геймплей не зависел от количества кадров в секунду
			
			_landSprites.at(i).move(-movement, 0.0f); // -movement означает движение влево по Х оси, 0 означает отсутствие движения по Y

			if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getGlobalBounds().width) // Если земля выходит за левый край, то удаляем её
			{
				sf::Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);
				
				_landSprites.at(i).setPosition(position); // Новая позиция
			}
		}
	}

	void Land::DrawLand()
	{
		for (unsigned short int i = 0; i < _landSprites.size(); i++)
		{
			_data->window.draw(_landSprites.at(i)); // Отрисовываем землю
		}
	}

	const std::vector<sf::Sprite>&Land::GetSprites()
	{
		return _landSprites;
	}
}