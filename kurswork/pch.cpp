// pch.cpp: исходный файл, соответствующий предкомпилированному заголовку; нужен для компиляции

#include "pch.h"
#include <Windows.h>///Для русских букв
#include <conio.h>///для getch
#include <iomanip>/// для установки кол-ва символов при выводе

//void constr_list(list &l) { /// Создание пустого списка
//	l.head = NULL;
//}

//bool list_empty(list l){/// Проверка списка на пустоту
//	return (l.head == NULL);
//}

//void comp_in(record *buf, list &l) {/// Включение в список новой структуры
//	if (l.head == NULL)/// Проверка списка на пустоту
//		l.head = buf;
//	else
//		{
//			l.tail = l.head;
//			l.tail = buf;
//buf.next = NULL;
//buf.
//		}
//	
//}

void dlstore(struct buf_record *buf, struct record **last) {
	//record *i = NULL;
	list* base = new list();
	int j;
	for (j = 0; j < 12; j++) {
		base->author[j] = buf->author[j];
	}
	for (j = 0; j < 32; j++) {
		i->title[j] = buf->title[j];
	}
	for (j = 0; j < 16; j++) {
		i->publisher[j] = buf->publisher[j];
	}
	i->num_of_page = buf->num_of_page;
	i->year = buf->year;
	if (last == NULL) {
		i->prior = NULL;
		last = &i;
	} /* вставка первого элемента */
	else {
		(*last)->next = i;
		i->prior = *last;
	}
	i->next = NULL;
}

void print(struct record *t) {
	int M = 20; ///По столько элементов выводится на экран
	int i, j, flag = 1, num = 1;
	int c;
	//record * buf = {};
//	*buf = *t;
	while (flag) {
		SetConsoleCP(1251);///Меняем кодировку
		i = 0;
		while ((i < M) && (num < N+1)) {
			cout << setw(5) << num << ")";
			for (j = 0; j < 12; j++)
				cout << t->author[j];
			cout << "  ";
			for (j = 0; j < 32; j++) 
				cout << t->title[j];
			cout << "  ";
			for (j = 0; j < 16; j++)
				cout << t->publisher[j];
			cout << "  ";
			cout << t->year; cout << "  ";
			cout << t->num_of_page << endl;
			num++;
			i++;
			t = t->next;
		}
		SetConsoleCP(866);///Возвращаем кодировку
		if (num == (N + 1)) cout << "Конец" << endl;
		c = _getch();
		if (c == 80) {
			i = 0;
		}
		else
			if (c == 72) {
				for (i = 0; i < 40; i++) {
					t = t->prior;
					num--;
				}
				i = 0;
			}
			else
				if (c == 27) {
					flag = 0;
				}
		/*SetConsoleCP(866);///Возвращаем кодировку
		if (num < N) {
			cout << "Продолжить? (1/0): ";
			cin >> flag;
		}
		else {
			if (num == N) {
				cout << "Конец" << endl;
				flag = 0;
			}
		}*/
	}
}