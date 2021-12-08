#pragma once

#include <memory> // Этот заголовок определяет общие утилиты для управления динамической памятью
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Pogosian
{
	struct GameData
	{
		StateMachine machine; // Состояния
		sf::RenderWindow window; // Окно рендера нашего приложения
		AssetManager assets; // Ассеты
		InputManager input; // Ввод
	};

	typedef std::shared_ptr<GameData> GameDataRef; 

	class Game
	{
	public:
		Game(int width, int height, std::string title); // Принимает высоту, ширину и название

	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock; // Нужно для хранения кадров в секунду 

		GameDataRef _data = std::make_shared<GameData>(); // Используется для того, чтобы  получить доступ ко всем состояниям игры

		void Run(); // Запуск игры
	};
}