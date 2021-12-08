#pragma once

namespace Pogosian
{
	class State
	{
	public:
		virtual void Init() = 0; //Инициализация - Initialize 

		virtual void HandleInput() = 0; // Обработка ввода
		virtual void Update(float dt) = 0; // Обновление
		virtual void Draw(float dt) = 0; // Переменная для обновления отрисовки 

		virtual void Pause() { } // Пауза
		virtual void Resume() { } // Отображение 
	};
}