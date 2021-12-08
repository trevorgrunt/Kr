#pragma once

#include <SFML/Graphics.hpp>

namespace Pogosian
{
	class Collision
	{
	public:
		Collision(); // Столкновение 

		bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2); // Проверяем не столкнулись ли два спрайта 
		bool CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);
	};
}