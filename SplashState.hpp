#pragma once

#include "SFML/Graphics.hpp"
#include "State.hpp"
#include "Game.hpp"

namespace Pogosian
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt); // dt - delta time ��� ����� � ��������, ������� ������ � �������� ����
		void Draw(float dt);

	private:
		GameDataRef _data; // ��������� ������ �� ������� ������

		sf::Clock _clock;

		sf::Sprite _background;
	}; // ��� ����������� ��������� ����� ����������� �� ������ �� �������� � �������
}