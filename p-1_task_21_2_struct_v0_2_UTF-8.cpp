/*p-1_task_21_2_struct_v0_2_UTF-8.cpp
Задание. Создаём деревья на примере их структуры и вложенных структур.
Что нужно сделать
Реализуйте упрощённую струткуру деревьев.

Учтите следующее:

создать одну струтуру или вложенную струтур дерева и "посадить" их в саду.
Вывести на экран.


Что оценивается
Соблюдены все условия заданий.
Программы работают корректно.
*/

#include <iostream>
#include <locale> //помощь для отображения кириличесских символов, т.е. русского языка
//~ #include <windows.h>

//струткура персонажа
struct character {
	char* name = "unknown";
	int health = 0;
	int armor = 0;
};

// функция подсчёта урона игроку
void take_damage(character* person, int damage) {
	//обращаюсь к полю структуры через person->name
	std::cout << person->name << " took damage: -" << damage << '\n';
	//~ person->armor -= person->armor - damage;
	person->armor -= damage;
	if (person->armor < 0) {
		person->health += person->armor;//оставшийся урон распространяется и на сами жизни
		person->armor = 0;
	}
}

int main() {
	setlocale(LC_ALL, ""); //setlocale(LC_ALL, "Rus");
	//~ SetConsoleCP(1251); // Корректный ввод кириллицы
	//~ SetConsoleOutputCP(1251); //Корректный вывод кириллицы
	std::wcout << L"Задание 1. Создаём ролевую игру через структуры v0_2 UTF-8" << std::endl; //Инициализирую строку как широкие символы, используя префикс L перед строками.
	//~ character person = { "Ivan", 100, 20}; или указать явно см. ниже
	character person = { "Ivan", .health = 100};
	/*если переменная типа указателя, то используем "->" person->armor. Если переменная самого типа, то ".armor" */
	person.armor = 20;
	//character* person_ptr = &person; //вызываю указатель на структуру через оператор "&" на переменной person и превращаем её в указатель
	//take_damage(person_ptr, 30); // а можно передать напрямую передав в функцию "&person"
	take_damage(&person, 30);
	std::cout << "Health: " << person.health << " Armor:"<< person.armor << "\n";

	std::cout << "Game over. Bye :-) !\n";
	return 0;
}
