// pch.cpp: исходный файл, соответствующий предкомпилированному заголовку; нужен для компиляции

#include "pch.h"
#include <Windows.h>///Для русских букв

void constr_list(list &l) { /// Создание пустого списка
	l.head = NULL;
}

//bool list_empty(list l){/// Проверка списка на пустоту
//	return (l.head == NULL);
//}

void comp_in(record *buf, list &l) {/// Включение в список новой структуры
	buf->next = NULL;
	if (l.head == NULL)/// Проверка списка на пустоту
		l.head = buf;
	else
//		l.tail->next = buf;
	l.tail = buf;
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
			l.tail = l.tail->next;
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