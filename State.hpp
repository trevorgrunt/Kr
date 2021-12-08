#pragma once

namespace Pogosian
{
	class State
	{
	public:
		virtual void Init() = 0; //������������� - Initialize 

		virtual void HandleInput() = 0; // ��������� �����
		virtual void Update(float dt) = 0; // ����������
		virtual void Draw(float dt) = 0; // ���������� ��� ���������� ��������� 

		virtual void Pause() { } // �����
		virtual void Resume() { } // ����������� 
	};
}