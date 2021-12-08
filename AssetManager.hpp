#pragma once

#include <map>

#include <SFML/Graphics.hpp>

namespace Pogosian
{
	class AssetManager
	{
	public:
		AssetManager() { } // Конструктор 
		~AssetManager() { } // Деструктор

		void LoadTexture(std::string name, std::string fileName); // Загрузка текстур, передаем название текстуры и имя файла
		sf::Texture &GetTexture(std::string name); // Этот метод позволит получить определенную текстуру (принимает только название текстуры)

		void LoadFont(std::string name, std::string fileName); // Тоже самое но с шрифтами
		sf::Font &GetFont(std::string name);

	private:
		std::map<std::string, sf::Texture> _textures; // map где первый параметр строка имя определенной текстуры, а второй сама текстура
		std::map<std::string, sf::Font> _fonts; // Тоже самое для шрифтов
	};
}