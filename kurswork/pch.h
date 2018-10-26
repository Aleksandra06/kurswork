// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#ifndef PCH_H
#define PCH_H

#include <iostream> ///Для работы с клавиатурой
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
	record data;
	record *next; // Последний элемент (хвост) списка
	record *prior; // Первый элемент (голова) списка
};

//void constr_list(list &l);
//bool list_empty(list l);// Проверка списка на пустоту
//void comp_in(record *buf, list &l); // Включение в список нового компонента
void dlstore(struct buf_record *i, struct record **last);
void print(struct record *t);//Печать

#endif //PCH_H
