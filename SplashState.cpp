#include <sstream>
#include "SplashState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Pogosian
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{
		_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH); // Загружаем текстуру

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background")); // Ставим её как задний фон
	}

	void SplashState::HandleInput() // Обработка закрытия окна (если нажать на крестик в верхнем углу)
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

	void SplashState::Update(float dt) // Проверяем сколько секунд прошло и отправляем в главное меню
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void SplashState::Draw(float dt)
	{
		_data->window.clear(); // Очищаем экран

		_data->window.draw(_background); // Рисуем задний фон

		_data->window.display(); // Отображаем его
	}
}