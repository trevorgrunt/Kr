#pragma once

#include "SFML/Graphics.hpp"
#include "State.hpp"
#include "Game.hpp"

namespace Pogosian
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt); // dt - delta time Это время в секундах, которое прошло с прошлого тика
		void Draw(float dt);

	private:
		GameDataRef _data; // Локальная ссылка на игровые данные

		sf::Sprite _background;
	}; // Все последующие состояния будут создаваться по такому же принципу и шаблону
}
