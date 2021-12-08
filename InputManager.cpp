#include "InputManager.hpp"

namespace Pogosian
{
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		if (sf::Mouse::isButtonPressed(button)) // Проверяем нажата ли кнопка мыши 
		{
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height); // Проверяем наведена ли мышка, задав координаты

			if (tempRect.contains(sf::Mouse::getPosition(window)))
			{
				return true; // На спрайт нажали
			}
		}
		return false; // На спрайт не нажали
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window) 
	{
		return sf::Mouse::getPosition(window); // Возвращаем позицию мыши
	}
} 