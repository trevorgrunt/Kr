#pragma once

#include <SFML/Graphics.hpp>

namespace Pogosian
{
	class InputManager
	{
	public:
		InputManager() {} // Конструктор
		~InputManager() {} // Деструктор

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window); // Проверяем нажатие на спрайт

		sf::Vector2i GetMousePosition(sf::RenderWindow &window); // Проверяем позицию мыши 
	};
}