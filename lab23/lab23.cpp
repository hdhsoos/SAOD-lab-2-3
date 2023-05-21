#include "list_2.h"
#include "list_2.cpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	menu();
	return 0;
}

int failure() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		// достигнут ли конец и введено ли больше одного "слова"
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nОшибка ввода. Попробуйте снова.\n" << endl;
	}
	return a;
}

void menu() {
	int command;
	type search_data;
	List l;
	init_list(l);
	while (true) {
		cout << "\nВыберите команду из списка:\n";
		cout << "1. Вывод текущего состояния списка на экран\n";
		cout << "2. Проверка пустоты списка\n";
		cout << "3. Проверка полноты списка\n";
		cout << "4. Добавить элемент в список\n";
		cout << "5. Удалить элемент из списка\n";
		cout << "6. Поиск элемента с заданной информационной частью\n";
		cout << "7. Очистить список\n";
		cout << "0. Завершить работу программы\n";
		cout << "Номер команды: ";
		command = failure();
		switch (command) {
		case 0:
			return;
			break;
		case 1:
			output_list(l);
			break;
		case 2:
			if (is_Empty(l)) cout << "Список пуст" << endl;
			else cout << "Список не пуст" << endl;
			break;
		case 3:
			if (is_Full(l)) cout << "Список полон" << endl;
			else cout << "Список не полон" << endl;
			break;
		case 4:
			push(l);
			break;
		case 5:
			remove(l);
			break;
		case 6:
			cout << "Введите информационную часть искомого элемента: " << endl;
			cin >> search_data;
			cout << "Индекс элемента в списке: " << find(l, search_data) << endl;
			break;
		case 7:
			if (!is_Empty(l)) {
				init_list(l);
				l.count = 0;
			}
			else {
				cout << "Список пуст, удалять нечего";
			}
			break;
		default:
			cout << "\nТакой команды нет, введите другое число" << endl;
			break;
		}
	}
}