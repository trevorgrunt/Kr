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
		void Update(float dt); // dt - delta time Это время в секундах, которое прошло с прошлого тика
		void Draw(float dt);

	private:
		GameDataRef _data; // Локальная ссылка на игровые данные

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
	};
}