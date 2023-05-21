#pragma once
#include <iostream>

#define ARRAY_SIZE 5
typedef int type;

typedef struct ListElem {
	int next;
	type data;
};

typedef struct List {
	int head = 0;
	ListElem arr[ARRAY_SIZE];
	int count = 0;
};


type remove(List& list);
int find(List& list, type data);
int find_prev(List& list, type data);
bool is_Full(List& list);
bool is_Empty(List& list);
void init_list(List& list);
void push(List& list);
void output_list(List& list);
int failure();
void menu();