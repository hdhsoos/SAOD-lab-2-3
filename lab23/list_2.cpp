#include "list_2.h"
using namespace std;

void init_list(List& list) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		list.arr[i].next = -1;
		list.arr[i].data = '\0';
	}
}

type remove(List& list) {
	type data, del_data = '\0';
	cout << "Введите информационную часть удаленного элемента" << endl;
	cin >> data;
	int ind = find(list, data);
	if (ind != -1) {
		if (ind == list.head) {
			int cur_head = list.head;
			list.head = list.arr[list.head].next;
			list.arr[cur_head].next = -1;
			list.count--;
		}
		else {
			int ind_prev = find_prev(list, data);
			del_data = list.arr[ind].data;
			list.arr[ind_prev].next = list.arr[ind].next;
			list.arr[ind].next = -1;
			list.count--;
		}
	}
	else {
		cout << "Элемент не найден" << endl;
	}

	return del_data;
}

int find(List& list, type data) {
	int cur_ind = 0;
	ListElem cur = list.arr[list.head];
	while (cur_ind < ARRAY_SIZE) {
		if (list.arr[cur_ind].data == data)
			return cur_ind;
		cur_ind++;
	}
	return -1;
}

int find_prev(List& list, type data) {
	int cur_ind = list.head, prev_ind = list.head;
	ListElem cur = list.arr[list.head];
	ListElem prev = list.arr[list.head];
	if (list.arr[list.head].next != -1) { cur = list.arr[cur.next]; cur_ind = cur.next; }
	while (cur_ind != -1) {
		if (cur.data == data)
			return prev_ind;
		cur_ind = cur.next;
		if (cur.next != -1)
			cur = list.arr[cur.next];
		prev_ind = prev.next;
		if (prev.next != -1)
			prev = list.arr[prev.next];

	}
	return 0;
}

bool is_Full(List& list) {
	return list.count == ARRAY_SIZE;
}

bool is_Empty(List& list) {
	return list.count == 0;
}

void output_list(List& list) {
	int c = 0;
	if (!is_Empty(list)) {
		cout << "Вывод списка: " << endl;
		ListElem cur = list.arr[list.head];
		while (c < list.count && cur.data != 0) {
			cout << cur.data << " ";
			if (cur.next != -1) {
				cur = list.arr[cur.next];
			}
			c++;
		}
		cout << endl;
	}
	else {
		cout << "Список пуст" << endl;
	}
}

int find_max_next(List& list) {
	int max_j = -2;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (list.arr[i].next > max_j) {
			max_j = list.arr[i].next;
		}
	}
	return max_j == -1 ? max_j + 2 : max_j + 1;
}

void push(List& list) {
	ListElem cur = list.arr[list.head];
	int command, ind, cur_ind = 0, j = find_max_next(list), ind_prev = 0;
	type data, data_push;
	if (is_Full(list)) {
		cout << "Список полон, новый элемент добавить нельзя" << endl;
	}
	else if (is_Empty(list)) {
		cout << "Список пуст, элемент будет добавлен в начале списка" << endl;
		cout << "Введите элемент, который хотите добавить" << endl;
		cin >> data;
		list.arr[list.head].data = data;
		list.count++;
	}
	else {
		cout << "Введите информационную часть элемента, относительно которого будет выполнена вставка:" << endl;
		cin >> data;
		ind = find(list, data);
		if (ind != -1) {
			cout << "Введите способ добавления:\n0. Вставить перед элементом\n1. Вставить после элемента" << endl;
			command = failure();
			if (command == 1) {
				cout << "Введите данные, которые хотите добавить" << endl;
				cin >> data_push;
				list.arr[j].next = list.arr[ind].next;
				list.arr[ind].next = j;
				list.arr[j].data = data_push;
				list.count++;
			}
			else if (command == 0) {
				if (ind == list.head) {
					int cur_head = list.head;
					j = find_max_next(list);
					list.head = j;
					list.arr[list.head].next = cur_head;
					cout << "Введите данные, которые хотите добавить" << endl;
					cin >> data_push;
					list.arr[list.head].data = data_push;
					list.count++;
				}
				else {
					ind_prev = find_prev(list, data);
					cout << "Введите данные, которые хотите добавить" << endl;
					cin >> data_push;
					j = find_max_next(list);
					list.arr[j].next = ind;
					list.arr[ind_prev].next = j;
					list.arr[j].data = data_push;
					list.count++;
				}
			}
			else {
				cout << "Ошибка ввода" << endl;
			}
		}
		else {
			cout << "Такого элемента нет в списке" << endl;
		}
	}
}