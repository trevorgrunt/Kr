#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"
#include <vector>

namespace Pogosian
{
	class Bird
	{
	public:
		Bird(GameDataRef data);

		void Draw(); // Отрисовываем птицу

		void Animate(float dt); // Анимация птицы

		void Update(float dt); // Точно такой же метод Updata, что и в прочих хедерах

		void Tap(); // Метод для того чтобы птица летела, когда игрок кликает мышкой

		const sf::Sprite& GetSprite(); // Спрайт птицы (метод нужен для столкновения птицы с объектами)

	private:
		GameDataRef _data;

		sf::Sprite _birdSprite; // Спрайт птицы
		std::vector<sf::Texture> _animationFrames; // Кадры анимации

		unsigned int _animationIterator; // Текущий отображенный кадр

		sf::Clock _clock;

		sf::Clock _movementClock; // Часы для птицы

		int _birdState; // Текущее состояние птицы

		float _rotation;
	};
}