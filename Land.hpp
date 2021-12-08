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

		void MoveLand(float dt); // ������� �����
		void DrawLand(); // ������������ 

		const std::vector<sf::Sprite>& GetSprites();
	private:
		GameDataRef _data;

		std::vector<sf::Sprite>_landSprites; // ������ �������� ��� �����
	};
}