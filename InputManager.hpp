#pragma once

#include <SFML/Graphics.hpp>

namespace Pogosian
{
	class InputManager
	{
	public:
		InputManager() {} // �����������
		~InputManager() {} // ����������

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window); // ��������� ������� �� ������

		sf::Vector2i GetMousePosition(sf::RenderWindow &window); // ��������� ������� ���� 
	};
}