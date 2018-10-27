#include "pch.h"
#include <conio.h>///для getch
#include <iomanip>/// для установки кол-ва символов при выводе

void read_base(FILE *f, list *l) {
	record* tmp = new record();
	list* tmpl;
	fread((record *)tmp, sizeof(record), 1, f);
	l->data = tmp;
	l->prior = NULL;
	l->next = NULL;
	for (int i = 1; i < N; i++) {
		tmp = new record();
		fread((record *)tmp, sizeof(record), 1, f);
		tmpl = l;
		l = l->next= new list();
		l->data = tmp;
		l->prior = tmpl;
		l->next = NULL;
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

void print_base(list *l) {
	int M = 20; ///По столько элементов выводится на экран
	int i, flag = 1, num = 1;
	int c = 0;
	while (flag) {
		i = 0; 
		system("cls"); cout << c<<endl;
		while (i < M) {
			cout << num << ") ";
			print_record(l->data);
			num++;
			i++;
			l = l->next;
			if (l->next != NULL)
				break;
		}
		SetConsoleCP(866);///Возвращаем кодировку
		if (num == (N + 1)) cout << "Конец" << endl;
		c = _getch();
		_getch();
		if (c == 238) {///Стрелка вниз
			i = 0;
		}
		else
			if (c == 161) {
				for (i = 0; i < 40; i++) {
					if (num == 1) break;
					l = l->prior;
					num--;
				}
				i = 0;
			}
			else
				if (c == 27) {
					flag = 0;
					return;
				}
				else
					while ((c != 238) || (c != 161) || (c != 27)) c = _getch();
	}
}