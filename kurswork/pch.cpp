// pch.cpp: исходный файл, соответствующий предкомпилированному заголовку; нужен для компиляции

#include "pch.h"
#include <Windows.h>///Для русских букв
#include <iostream> ///Для работы с клавиатурой
#include <cstdio> ///Например для fread()
#include <cstring> ///Для работы со строками
#include <cstdlib>

using namespace std;

void constr_list(list &l) { /// Создание пустого списка
	l.head = NULL;
}

bool list_empty(list l){/// Проверка списка на пустоту
	return (l.head == NULL);
}

void comp_in(list &l, char* a, char* t, char* p, short int y, short int n) {/// Включение в список новой структуры
	record* c = new record();
	strcpy_s(c->author, 12, a);
	strcpy_s(c->title, 32, t);
	strcpy_s(c->publisher, 16, p);
	c->year = y;
	c->num_of_page = n;
	c->next = NULL;
	if (list_empty(l))/// Проверка списка на пустоту
		l.head = c;
	else
	//	l.tail->next = c;
	l.tail = c;
}

void Conclusion (list &l) {
	int M = 20; ///По столько элементов выводится на экран
	int i, j, flag = 1, num = 0;
	while (flag) {
		SetConsoleCP(1251);///Меняем кодировку
		i = 0;
		while ((i < M) && (num < N)) {
			for (j = 0; j < 12; j++) 
				cout << l.head->author[j];
			cout << "  ";
			for (j = 0; j < 32; j++) 
				cout << l.head->title[j];
			cout << "  ";
			for (j = 0; j < 16; j++)
				cout << l.head->publisher[j];
			cout << "  ";
			cout << l.head->year; cout << "  ";
			cout << l.head->num_of_page << endl;
			num++;
			i++;
		}
		SetConsoleCP(866);///Возвращаем кодировку
		if (num < N) {
			cout << "Продолжить? (1/0): ";
			cin >> flag;
		}
		else {
			if (num == N) {
				cout << "Конец" << endl;
				flag = 0;
			}
		}
	}
}