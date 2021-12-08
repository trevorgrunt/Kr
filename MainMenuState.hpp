#pragma once

#include "SFML/Graphics.hpp"
#include "State.hpp"
#include "Game.hpp"

namespace Pogosian  
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt); // dt - delta time ��� ����� � ��������, ������� ������ � �������� ����
		void Draw(float dt);

	private:
		GameDataRef _data; // ��������� ������ �� ������� ������

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
	};
}