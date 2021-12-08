#include <sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Pogosian
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{

	}

	void GameOverState::Init()
	{
		_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH); // Загружаем текстуру

		_background.setTexture(this->_data->assets.GetTexture("Game Over Background")); // Ставим её как задний фон
	}

	void GameOverState::HandleInput() // Обработка закрытия окна (если нажать на крестик в верхнем углу)
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void GameOverState::Update(float dt) // Проверяем сколько секунд прошло и отправляем в главное меню
	{

	}

	void GameOverState::Draw(float dt)
	{
		_data->window.clear(); // Очищаем экран

		_data->window.draw(_background); // Рисуем задний фон

		_data->window.display(); // Отображаем его
	}
}