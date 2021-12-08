#include "Game.hpp"
#include "SplashState.hpp"

// Подключение библиотек для того чтобы исключить повторения в разных длинах труб
#include <stdlib.h>
#include <time.h>

namespace Pogosian // Данный файл нужен для создания игрового цикла
{
	Game::Game(int width, int height, std::string title)
	{
		srand(time(NULL));

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar); // Создаем окно рендера
		_data->machine.AddState(StateRef(new SplashState(this->_data)));

		this->Run(); // Запускаем игру
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;
		
		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen()) // Пока окно открыто
		{
			this->_data->machine.ProcessStateChanges(); // Изменение состояния

			newTime = this->_clock.getElapsedTime().asSeconds(); // Эта строчка и строчка ниже позволяют найти сколько времени прошло между кадрами
			frameTime = newTime - currentTime; // Эти две строчки нужны для плавного отображения кадров
			
			if (frameTime > 0.25f) // Продолжение той же идеи
			{
				frameTime = 0.25f;
			}
			
			currentTime = newTime; 
			accumulator += frameTime; // Общее количество всего времени кадра, накопитель

			while (accumulator >= dt)  
			{
				this->_data->machine.GetActiveState()->HandleInput(); // Обрабатываем ввод
				this->_data->machine.GetActiveState()->Update(dt); // Обновляем

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.GetActiveState()->Draw(interpolation);
		}

	}
}