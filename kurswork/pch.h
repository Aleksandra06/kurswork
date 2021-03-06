#ifndef PCH_H
#define PCH_H

#include <iostream> ///Для работы с клавиатурой
#include <conio.h>///для getch
#include <Windows.h>///Для русских букв
#include <iomanip>/// для установки кол-ва символов при выводе
#include <cstdio> ///Например для fread()
#include <cstring> ///Для работы со строками
#include <cstdlib>

using namespace std;

const int N = 4000;

struct record
{
	char author[12];
	char title[32];
	char publisher[16];
	short int year;
	short int num_of_page;
};

struct list {
	record *data;
	list *next; 
	list *prior;
};

struct queue {
	list *head;
	list *tail;
};

struct vertex {
	list *fact;
	vertex *left;
	vertex *right;
};

extern list *base;
extern queue *stack;
extern int *w;
extern int num_h, num_t;

void read_base(FILE *, list *);

#endif //PCH_H
