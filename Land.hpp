#pragma once

#include "SFML/Graphics.hpp"
#include "Game.hpp"
#include <vector>

namespace Pogosian
{
	class Land
	{
	public:
		Land(GameDataRef data);

		void MoveLand(float dt); // Двигаем землю
		void DrawLand(); // Отрисовываем 

		const std::vector<sf::Sprite>& GetSprites();
	private:
		GameDataRef _data;

		std::vector<sf::Sprite>_landSprites; // Вектор спрайтов для земли
	};
}