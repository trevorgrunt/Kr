#include "StateMachine.hpp"

namespace Pogosian
{
	void StateMachine::AddState( StateRef newState, bool isReplacing) //Осуществление добавления состояния
	{
		this-> _isAdding = true;
		this-> _isReplacing = isReplacing; 

		this->_newState = std::move(newState);
	}

	void StateMachine::RemoveState() // Удаление состояния
	{
		this->_isRemoving = true; // Довольно простая реализация
	}

	void StateMachine::ProcessStateChanges() // Изменяем состояния
	{
		if (this->_isRemoving && !this->_states.empty()) // Если мы убрали состояние и текущее состояния на стэке пустое
		{
			this->_states.pop(); // Удаляем состояние с вершины стэка

			if (!this->_states.empty()) // Если теперь текущее состояние не пустое
			{
				this->_states.top()->Resume(); // Выводим состояние наверху
			}
			this->_isRemoving = false; // Переменная которая отслеживает удаление состояния 
		}

		if (this->_isAdding) // Если мы хотим добавить состояние
		{
			if (!this->_states.empty()) // Если контейнер в стэке не пустой
			{
				if (this->_isReplacing) // Заменяем?
				{
					this->_states.pop(); // Происходит замена
				}
				else // Если все таки не заменяем
				{
					this->_states.top()->Pause(); // Ставим на паузу
				}
			}
			this->_states.push(std::move(this->_newState)); // Вставляем состояние на вершину стэка
			this->_states.top()->Init(); // Инициализируем
			this->_isAdding = false; // Меняем переменную-трекер добавления 
		}
	}

	StateRef& StateMachine::GetActiveState() // Функция получения активного состояния 
	{
		return this->_states.top(); // Возвращаем актуальное состояние с вершины стэка
	}
}