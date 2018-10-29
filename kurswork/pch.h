#ifndef PCH_H
#define PCH_H

#include <iostream> ///Для работы с клавиатурой
#include <cstdio> ///Например для fread()
#include <cstring> ///Для работы со строками
#include <cstdlib>
#include <Windows.h>///Для русских букв

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

struct tQ {
	list *head;
	list *tail;
};

void read_base(FILE *, list *);
void print_record(record *);//Печать
void print_base(list *);
void rasheplen(list* &, list* &, list* &, int &);
int sravn(record *, record *);
void mergesort(list*&);

#endif //PCH_H
