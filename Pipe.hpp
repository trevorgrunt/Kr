#pragma once

#include "SFML/Graphics.hpp"
#include "Game.hpp"
#include <vector>
#include "DEFINITIONS.hpp"

namespace Pogosian
{
	class Pipe
	{
	public:
		Pipe(GameDataRef data);
		
		void SpawnBottomPipe(); // Спавн нижней трубы
		void SpawnTopPipe(); // Спавн верхней трубы
		void SpawnInvisiblePipe(); // Небольшой костыль для исправления бага с трубами при помощи создания невидимой трубы
		void MovePipes(float dt); // Передвижение труб
		void DrawPipes(); // Отрисовка труб
		void RandomisePipeOffset(); // Случайное смещение по Y труб для разной высоты
		
		const std::vector<sf::Sprite>& GetSprites();
	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites; // Вектор хранящий "трубы" для игры

		int _landHeight; // Высота спрайта земли
		int _pipeSpawnYOffset; // Смещение по оси Y труб (нужна разная высота) 
	};
}