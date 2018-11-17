#include "sort.h"
#include "pch.h"

struct queue {
	list *head;
	list *tail;
} Q;

void copy_base(list *a, list *b) {
	b->prior = NULL;
	b->data = a->data;
	for (int i = 1; i < N; i++) {
		a = a->next;
		b->next = new list;
		b->next->prior = b;
		b = b->next;
		b->data = a->data;
	}
	b->next = NULL;
}

void prior(list *p) {
	p->prior = NULL;
	for (int i = 1; i < N; i++) {
		p->next->prior = p;
		p = p->next;
	}
}

void DigitalSort1(list *&head) {

	queue Q[257];

	for (int i = 0; i < 257; i++) {
		Q[i].tail = (list*)&(Q[i].head);
	}

	list *p;
	SetConsoleCP(1251);
	for (int j = 10; j >= 0; j--) {
		for (int i = 0; i < 257; i++) {
			Q[i].tail = Q[i].head = NULL;
		}

		while (head) {
			int d;
			if (head->data->publisher[j] == ' ')
				d = 0;
			else
				d = head->data->publisher[j] + 129;
			p = Q[d].tail;
			if (Q[d].head == NULL)
				Q[d].head = head;
			else
				p->next = head;

			p = Q[d].tail = head;
			head = head->next;
			p->next = NULL;
		}
		cout << endl << endl;
		head = NULL;

		int i;
		for (i = 0; i < 256; i++) {
			if (Q[i].head != NULL)
				break;
		}
		head = Q[i].head;
		p = Q[i].tail;
		for (int k = i + 1; k < 256; k++) {
			if (Q[k].head != NULL) {
				p->next = Q[k].head;
				p = Q[k].tail;
			}
		}
	}
	prior(head);
}

void DigitalSort(list *&head) {

	queue Q[257];

	for (int i = 0; i < 257; i++) {
		Q[i].tail = (list*)&(Q[i].head);
	}

	list *p;
	SetConsoleCP(1251);
	for (int j = 10; j >= 0; j--) {
		for (int i = 0; i < 257; i++) {
			Q[i].tail = Q[i].head = NULL;
		}

		while (head) {
			int d;
			if (head->data->author[j] == ' ')
				d = 0;
			else
				d = head->data->author[j] + 129;
			p = Q[d].tail;
			if (Q[d].head == NULL)
				Q[d].head = head;
			else
				p->next = head;

			p = Q[d].tail = head;
			head = head->next;
			p->next = NULL;
		}
		cout << endl << endl;
		head = NULL;

		int i;
		for (i = 0; i < 256; i++) {
			if (Q[i].head != NULL)
				break;
		}
		head = Q[i].head;
		p = Q[i].tail;
		for (int k = i + 1; k < 256; k++) {
			if (Q[k].head != NULL) {
				p->next = Q[k].head;
				p = Q[k].tail;
			}
		}
	}
	DigitalSort1(head);
}


