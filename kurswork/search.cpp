#include "search.h"
#include "pch.h"

void move(list *&p, int num) {
	for (int i = 0; i < num; i++) {
		p = p->next;
	}
	//return;
}

int compare(char *a, char *b) {
	for (int i = 0; i < 3; i++) {
		if ((int)a[i] < (int)b[i]) return 1;
		else
			if ((int)a[i] > (int)b[i]) return -1;
	}
	return 0;
}

void binary_search(char *x, list *&l, queue *&turn) {
	int L = 1;
	int R = N;
	int m;
	int sravn;
	list *t;
	t = l;
	turn = new queue();
	turn->head = turn->tail;
	while (L < R) {
		m = (L + R) / 2;
		t = l;
		move(t, m - 1);
		sravn = compare(t->data->publisher, x);
		if (sravn == 1) {
			L = m + 1;
		}
		else {
			if (sravn != 1) {
				R = m;
			}
		}
	}
	cout << "ok";
	if (compare(t->data->publisher, x) == 0) {
		while (compare(l->prior->data->publisher, x) == 0)
			turn->head = turn->head->prior;
		while (compare(t->prior->data->publisher, x) == 0)
			turn->tail = turn->tail->prior;
	}
	else {
		cout << "Такой записи нет";
	}
}

