#include "sort.h"
#include "pch.h"

const int L = 3;//количество символов дл€ сортировки

struct queue {//очереди
	list *head;
	list *tail;
} Q;


void prior(list *p) {
	p->prior = NULL;
	for (int i = 1; i < N; i++) {
		p->next->prior = p;
		p = p->next;
	}
}

void DigitalSort(list *&head) {

	queue Q[256];

	for (int i = 0; i < 256; i++) {
		Q[i].tail = (list*)&(Q[i].head);
	}

	list *p;

	for (int j = 0; j < L; j++) {
		cout << "!";
		for (int i = 0; i < 256; i++) {
			Q[i].tail = Q[i].head = NULL;
		}

		while (head) {
			int d;
			d = head->data->publisher[j] + 128;
			p = Q[d].tail;
			if (Q[d].head == NULL)
				Q[d].head = head;
			else
				p->next = head;

			p = Q[d].tail = head;
			head = head->next;
			p->next = NULL;
		}

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
