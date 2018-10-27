// pch.cpp: исходный файл, соответствующий предкомпилированному заголовку; нужен для компиляции

#include "pch.h"
#include <conio.h>///для getch
#include <iomanip>/// для установки кол-ва символов при выводе

void read_base(FILE *f, list *l) {
	record* tmp = new record();
	list* tmpl;
	fread((record *)tmp, sizeof(record), 1, f);
	l->data = new record;
	l->data = tmp;
	l->prior = NULL;
	for (int i = 1; i < 20; i++) {
		fread((record *)tmp, sizeof(record), 1, f);
		tmpl = l;
		l = l->next;
		l = new list();
		//l->data = new record();
		l->data = tmp;
		l->prior = tmpl;
		l->next = NULL;
		//print_record(l->data);
		//print_record(l->prior->data);
	}
}

void print_record(record *t) {
	SetConsoleCP(1251);///Меняем кодировку
	for (int j = 0; j < 12; j++)
		cout << t->author[j];
	cout << "  ";
	for (int j = 0; j < 32; j++)
		cout << t->title[j];
	cout << "  ";
	for (int j = 0; j < 16; j++)
		cout << t->publisher[j];
	cout << "  ";
	cout << t->year; cout << "  ";
	cout << t->num_of_page << endl;
}

/*
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
*//*
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
	}  вставка первого элемента 
	else {
		(*last)->next = i;
		i->prior = *last;
	}
	i->next = NULL;
}
*/
void print_base(list *l) {
	int M = 20; ///По столько элементов выводится на экран
	int i, flag = 1, num = 1;
	int c = 0;
	while (flag) {
		i = 0;
		system("cls");
		while ((i < M) && (num < N + 1)) {
			print_record(l->data);
			num++;
			i++;
			l = l->next;
		}
		SetConsoleCP(866);///Возвращаем кодировку
		if (num == (N + 1)) cout << "Конец" << endl;
		c = _getch();
		_getch();
		if (c == 80) {///Стрелка вниз
			i = 0;
		}
		else
			if (c == 72) {///Стрелка вверх
				for (i = 0; i < 40, num > 0; i++) {
					l = l->prior;
					num--;
				}
				i = 0;
			}
			else
				if (c == 27) {/// escape
					flag = 0;
					return;
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
			*/
	}
}