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
		
		void SpawnBottomPipe(); // ����� ������ �����
		void SpawnTopPipe(); // ����� ������� �����
		void SpawnInvisiblePipe(); // ��������� ������� ��� ����������� ���� � ������� ��� ������ �������� ��������� �����
		void MovePipes(float dt); // ������������ ����
		void DrawPipes(); // ��������� ����
		void RandomisePipeOffset(); // ��������� �������� �� Y ���� ��� ������ ������
		
		const std::vector<sf::Sprite>& GetSprites();
	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites; // ������ �������� "�����" ��� ����

		int _landHeight; // ������ ������� �����
		int _pipeSpawnYOffset; // �������� �� ��� Y ���� (����� ������ ������) 
	};
}