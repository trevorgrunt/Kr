#include "AssetManager.hpp"

namespace Pogosian
{
	void AssetManager::LoadTexture(std::string name, std::string fileName) // Метод - добавление текстур
	{
		sf::Texture tex; // Локальный экземпляр текстуры

		if (tex.loadFromFile(fileName)) // Если файл успешно загружен
		{
			this->_textures[name] = tex; // Добавляем его в map текстур из хедера 
		}
	}

	sf::Texture& AssetManager::GetTexture(std::string name) // Метод - получение текстуры 
	{
		return this->_textures.at(name); // Поиск текстуры по имени
	}


	// Аналогичные методы для шрифтов 
	void AssetManager::LoadFont(std::string name, std::string fileName) 
	{
		sf::Font font; 

		if (font.loadFromFile(fileName)) 
		{
			this->_fonts[name] = font;  
		}
	}

	sf::Font &AssetManager::GetFont(std::string name)
	{
		return this->_fonts.at(name); 
	}	
}
