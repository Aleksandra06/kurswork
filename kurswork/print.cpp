#include "print.h"
#include "pch.h"

void print_record(record *t) {
	SetConsoleCP(1251);///Меняем кодировку
	for (int j = 0; j < 12; j++)
		cout << t->author[j];
	cout << "|";
	for (int j = 0; j < 32; j++)
		cout << t->title[j];
	cout << "|";
	for (int j = 0; j < 16; j++)
		cout << t->publisher[j];
	cout << "| ";
	cout << t->year;
	cout << " | ";
	cout << t->num_of_page << " |" << endl;
}

void print_base(list *l) {
	int M = 20; ///По столько элементов выводится на экран
	int i, flag = 1, num = 1;
	int c = 0;
	while (flag) {
		i = 0;
		system("cls");
		cout << "+-----+------------+--------------------------------+----------------+------+-----+" << endl;
		while ((i < M) && (num <= N) && (l != NULL)) {
			cout << "|";
			cout << setw(4) << num << ")|";
			print_record(l->data);
			cout << "+-----+------------+--------------------------------+----------------+------+-----+" << endl;
			num++;
			i++;
			if (l->next == NULL)
				break;
			else
				l = l->next;
		}
		SetConsoleCP(866);///Возвращаем кодировку
		c = 0;
		while ((c != 161) && (c != 27) && (c != 238)) {
			if (_kbhit()) {///Пользоавтель нажал на кнопку = 1
				c = _getch();
			}
		}
		if (c == 161) {
			for (i = 0; i < 40; i++) {
				if (l->prior == NULL) break;
				l = l->prior;
				num--;
			}
		}
		else
			if (c == 27) {
				flag = 0;
				return;
			}
	}
}

void print_stak(queue *p) {
	list *l = p->head;
	int M = 20; ///По столько элементов выводится на экран
	int i, flag = 1, num = 1;
	int c = 0;
	while (flag) {
		i = 0;
		system("cls");
		cout << "+-----+------------+--------------------------------+----------------+------+-----+" << endl;
		while ((i < M) && (p->tail != l)) {
			cout << "|";
			cout << setw(4) << num << ")|";
			print_record(l->data);
			cout << "+-----+------------+--------------------------------+----------------+------+-----+" << endl;
			num++;
			i++;
			if ((l->next == NULL) || (p->tail == l->next)) {
				num--;
				break;
			}
			else
				l = l->next;
		}
		SetConsoleCP(866);///Возвращаем кодировку
		c = 0;
		while ((c != 161) && (c != 27) && (c != 238)) {
			if (_kbhit()) {///Пользоавтель нажал на кнопку = 1
				c = _getch();
			}
		}
		if (c == 161) {
			for (i = 0; i < 40; i++) {
				if ((l->prior == NULL) || (p->head == l)) break;
				l = l->prior;
				num--;
			}
		}
		else
			if (c == 27) {
				flag = 0;
				return;
			}
	}
}

void LorR(vertex *&p, vertex *&stop) {
	if ((p == NULL) || (p == stop)) return;
	list *tmp = p->fact;
	LorR(p->left, stop);
	tmp = p->fact;
	while (tmp != NULL) {
		print_record(tmp->data);
		tmp = tmp->next;
	}
	cout << "---------------------------------------------------------------------------" << endl;
	LorR(p->right, stop);
}

void LorL(vertex *&p, vertex *&stop) {
	if ((p == NULL) || (p == stop) || (p == stop->right)) return;
	list *tmp = p->fact;
	LorR(p->left, stop);
	tmp = p->fact;
	while (tmp != NULL) {
		print_record(tmp->data);
		tmp = tmp->next;
	}
	cout << "---------------------------------------------------------------------------" << endl;
	LorR(p->right, stop);
}

void print_tree(vertex *&p) {
	if (p == NULL) return;
	vertex *stop = p;
	list *tmp;
	int c;
	while (true) {
		c = 0;
		SetConsoleCP(866);
		while ((c != 161) && (c != 27) && (c != 238)) {
			if (_kbhit()) {///Пользоавтель нажал на кнопку = 1
				c = _getch();
			}
		}
		switch (c) {
		case 27:
			system("cls");
			return;
		case 161:
			system("cls");
			LorR(p->left, stop);
			tmp = p->fact;
			while (tmp != NULL) {
				print_record(tmp->data);
				tmp = tmp->next;
			}
			cout << "---------------------------------------------------------------------------" << endl;
			break;
		case 238:
			system("cls");
			tmp = p->fact;
			while (tmp != NULL) {
				print_record(tmp->data);
				tmp = tmp->next;
			}
			cout << "---------------------------------------------------------------------------" << endl;
			LorR(p->right, stop);
			break;
		}
	}
}


//void print_queue(queue *&x) {//Обход слева направо
//	list *t;
//	t = x->head;
//	while (t != x->tail) {
//		print_record(t->data);
//		t = t->next;
//	}
//}