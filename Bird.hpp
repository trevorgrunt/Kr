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

		void Draw(); // ������������ �����

		void Animate(float dt); // �������� �����

		void Update(float dt); // ����� ����� �� ����� Updata, ��� � � ������ �������

		void Tap(); // ����� ��� ���� ����� ����� ������, ����� ����� ������� ������

		const sf::Sprite& GetSprite(); // ������ ����� (����� ����� ��� ������������ ����� � ���������)

	private:
		GameDataRef _data;

		sf::Sprite _birdSprite; // ������ �����
		std::vector<sf::Texture> _animationFrames; // ����� ��������

		unsigned int _animationIterator; // ������� ������������ ����

		sf::Clock _clock;

		sf::Clock _movementClock; // ���� ��� �����

		int _birdState; // ������� ��������� �����

		float _rotation;
	};
}