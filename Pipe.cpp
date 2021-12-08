#include "Pipe.hpp"
#include <iostream>

namespace Pogosian
{
	Pipe::Pipe(GameDataRef data) : _data(data)
	{
		_landHeight = _data->assets.GetTexture("Land").getSize().y;  // Передаем переменной расположение спрайта по Y
		_pipeSpawnYOffset = 0; // Смещение по оси Y труб (нужна разная высота) 
	}

	void Pipe::SpawnBottomPipe() // Спавн нижней трубы
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));

		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYOffset); // Ставим позицию, по X от разрешения экрана, по Y применяем формулу с учетом случайно длины каждой трубы 

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnTopPipe() // Спавн верхней трубы
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));

		sprite.setPosition(_data->window.getSize().x, -_pipeSpawnYOffset); // Ставим позицию

		pipeSprites.push_back(sprite);
	}

	void Pipe::SpawnInvisiblePipe() // Небольшой костыль для исправления бага с трубами при помощи создания невидимой трубы
	{
		sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));

		sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height);

		sprite.setColor(sf::Color(0, 0, 0, 0));

		pipeSprites.push_back(sprite);
	}

	void Pipe::MovePipes(float dt) // Передвижение труб
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{		
			if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width) // Если труба выходит за левый край, то удаляем её
			{
				pipeSprites.erase(pipeSprites.begin() + i);
			}
			else // Иначе она просто двигается
			{
				float movement = PIPE_MOVEMENT_SPEED * dt; // Вычисляем скорость (dt нужен для того чтобы геймплей не зависил от количества кадров в секунду)

				pipeSprites.at(i).move(-movement, 0); // -movement означает движение влево по Х оси, 0 означает отсутствие движения по Y
			}		
		}
	}

	void Pipe::DrawPipes()
	{
		for (unsigned short int i = 0; i < pipeSprites.size(); i++)
		{
			_data->window.draw(pipeSprites.at(i)); // Отрисовываем трубы
		}
	}

	void Pipe::RandomisePipeOffset()
	{
		_pipeSpawnYOffset = rand() % (_landHeight + 1); // Ставим смещение случайным образом от нуля до значения высоты земли 
	}

	const std::vector<sf::Sprite>&Pipe::GetSprites()
	{
		return pipeSprites; // Возвращаем спрайты труб
	}
}