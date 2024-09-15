/*p-1_task_21_3_struct_v0_1_UTF-8.cpp
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
#include <cstdlib>
#include <string>
//~ #include <windows.h>

//струткура персонажа
struct character {
	std::string name = "unknown";
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
	std::wcout << L"Задание 3. Создаём ролевую игру через структуры v0_1 UTF-8" << std::endl; //Инициализирую строку как широкие символы, используя префикс L перед строками.
	//~ character people[10] = {{ "Lohse", 115, 35}, { "Mendez", 120, 38}, { "Petrovich", 140, 55}};//объявляем 10 персонажей с характеристиками
	int persons = 10;
	character people[persons];//объявляем 10 персонажей с характеристиками через цикл
	for (int i = 0; i < persons; ++i) {
		people[i].name = "Character #" + std::to_string(i);
		people[i].health = (std::rand() % 100) + 100; //ot 100 do 199 включительно
		people[i].armor = (std::rand() % 40) + 10; //ot 10 do 49 включительно
	}
	//после удара молнии все персонажи получают урон в 30 единиц
	//используем указатель на элемент, т.е. используем оператор & (end)
	for (int i = 0; i < persons; ++i) {
		take_damage(people + i, 30);
	}
	//~ std::cout << "Health: " << person.health << " Armor:"<< person.armor << "\n";

	std::cout << "Game over. Bye :-) !\n";
	return 0;
}
