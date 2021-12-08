#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace Pogosian
{
	typedef std::unique_ptr<State> StateRef;

	class StateMachine // Класс управляющий всеми состояниями, скелет приложения
	{
	public:
		StateMachine() { } // Конструктор
		~StateMachine() { } // Деструктор 

		void AddState(StateRef newState, bool isReplacing = true); //Добавляет состояние на стэк 
		void RemoveState(); // Соотвественно метод убирающий состояние

		void ProcessStateChanges(); // Метод запускающийся при каждом старте игрового цикла

		StateRef& GetActiveState();

	private:
		std::stack<StateRef> _states; // Текущие состояние на стэке
		StateRef _newState;

		//Отслеживаем если мы убираем состояние, если мы добавляем, или заменяем
		bool _isRemoving; 
		bool _isAdding;
		bool _isReplacing;
	};
}