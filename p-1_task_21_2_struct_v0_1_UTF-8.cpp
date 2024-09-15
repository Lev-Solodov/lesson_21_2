/*p-task_struct_v0_4_UTF-8.cpp
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
#include <fstream>
#include <locale> //помощь для отображения кириличесских символов, т.е. русского языка
//~ #include <windows.h>
#include <vector>

// функция подсчёта урона игроку
void take_damage(char* name, int* health, int* armor, int damage) {
	std::cout << name << " took damage: -" << damage << '\n';
	*armor -= damage;
	if (*armor < 0) {
		*health += *armor;//оставшийся урон распространяется и на сами жизни
		*armor = 0;
	}
}

int main() {
	setlocale(LC_ALL, ""); //setlocale(LC_ALL, "Rus");
	//~ SetConsoleCP(1251); // Корректный ввод кириллицы
	//~ SetConsoleOutputCP(1251); //Корректный вывод кириллицы
	std::wcout << L"Задание 1. Создаём ролевая игра v0_1 UTF-8" << std::endl; //Инициализирую строку как широкие символы, используя префикс L перед строками.
	char* names[10];
	int health[10];
	int armor[10];
	//~ std::cout << "  -endHardness: " << tree.woodHard.endHardness << '\n';

	std::cout << "Game over. Bye :-) !\n";
	return 0;
}
