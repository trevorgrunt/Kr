#include "Collision.hpp"

namespace Pogosian
{
	Collision::Collision()
	{

	}

	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
	{
		sf::Rect<float> rect1 = sprite1.getGlobalBounds();  // Эта строчка и строчка снизу два прямоугольника
		sf::Rect<float> rect2 = sprite2.getGlobalBounds(); 
			
		if (rect1.intersects(rect2)) // Если один прямоугольник столкнулся с другим
		{
			return true; // Спрайты столкнулись
		}
		else // Иначе
		{
			return false; // Не столкнулись, все логично
		}
	}

	bool Collision::CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2) // Похожий метод с масштабированием, чтобы пробел между птицей и препятствием был меньше, едва заметная деталь, но захотелось исправить
	{
		sprite1.setScale(scale1, scale2); // Масштабирование
		sprite2.setScale(scale1, scale2);

		sf::Rect<float> rect1 = sprite1.getGlobalBounds();
		sf::Rect<float> rect2 = sprite2.getGlobalBounds();

		if (rect1.intersects(rect2))
		{
			return true; 
		}
		else 
		{
			return false; 
		}
	}
}