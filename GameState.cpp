#include <sstream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Pogosian
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH); // Загружаем текстуру заднего фона
		_data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH); // Загружаем текстуру труб
		_data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
		_data->assets.LoadTexture("Land", LAND_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
		_data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);

		pipe = new Pipe(_data);
		land = new Land(_data);
		bird = new Bird(_data);

		_background.setTexture(this->_data->assets.GetTexture("Game Background")); // Ставим её как задний фон

		_gameState = GameStates::eReady;
	}

	void GameState::HandleInput() // Обработка закрытия окна (если нажать на крестик в верхнем углу)
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				if (GameStates::eGameOver != _gameState) // Если состояние не конец игры
				{
					_gameState = GameStates::ePlaying;
					bird->Tap(); // Кликаем и поднимаем птицу
				}					
			} 
		}
	}

	void GameState::Update(float dt) // Проверяем сколько секунд прошло и отправляем в главное меню
	{
		if (GameStates::eGameOver != _gameState) // Если состояние не конец игры
		{
			bird->Animate(dt);
			land->MoveLand(dt);
		}

		if (GameStates::ePlaying == _gameState) // Если состояние это игровой процесс 
		{
			pipe->MovePipes(dt);

			if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) // Позволяет через определенный промежуток времени спавнить трубы
			{
				pipe->RandomisePipeOffset();

				pipe->SpawnInvisiblePipe();
				pipe->SpawnBottomPipe();
				pipe->SpawnTopPipe();

				clock.restart();
			}
			bird->Update(dt);

			std::vector<sf::Sprite> landSprites = land->GetSprites();

			for (int i = 0; i < landSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(bird->GetSprite(), landSprites.at(i))) // Если птица столкнулась с землей
				{
					_gameState = GameStates::eGameOver; // Игра окончена
				}
			}

			std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();

			for (int i = 0; i < pipeSprites.size(); i++)
			{
				if (collision.CheckSpriteCollision(bird->GetSprite(), 0.625f, pipeSprites.at(i), 1.0f)) // Если птица столкнулась с землей
				{
					_gameState = GameStates::eGameOver; // Игра окончена
				}
			}
		}
	}
		
	void GameState::Draw(float dt)
	{
		_data->window.clear(); // Очищаем экран

		_data->window.draw(_background); // Отрисовываем задний фон
		pipe->DrawPipes();  // Отрисовываем трубы
		land->DrawLand(); // Отрисовываем землю
		bird->Draw(); // Отрисовываем птицу

		_data->window.display(); // Отображаем его
	}
}