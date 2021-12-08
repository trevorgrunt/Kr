#pragma once

#include "SFML/Graphics.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "Pipe.hpp"
#include "Land.hpp"
#include "Bird.hpp"
#include "Collision.hpp"

namespace Pogosian
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt); // dt - delta time Это время в секундах, которое прошло с прошлого тика
		void Draw(float dt);

	private:
		GameDataRef _data; // Локальная ссылка на игровые данные

		sf::Sprite _background;

		Pipe *pipe;
		Land *land;
		Bird *bird;
		Collision collision;

		sf::Clock clock;
		int _gameState;
	}; // Все последующие состояния будут создаваться по такому же принципу и шаблону
}
