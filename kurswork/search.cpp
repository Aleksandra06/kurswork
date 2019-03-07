#include "search.h"
#include "pch.h"

void masiving(list *l, list *r[N]) {
	for (int i = 0; i < N; i++) {
		r[i] = l;
		l = l->next;
	}
}

int compare(char *a, char *b) {
	for (int i = 0; i < 3; i++) {
		if ((int)a[i] < (int)b[i]) return 1;
		else
			if ((int)a[i] > (int)b[i]) return -1;
	}
	return 0;
}

void binary_search(char *x, list *l[N], queue *&turn) {
	int L = 1;
	int R = N;
	int m, h, t;
	int sravn;
	turn = new queue();
	turn->head = turn->tail;
	while (L < R) {
		m = (L + R) / 2;
		sravn = compare(l[m]->data->publisher, x);
		if (sravn == 1) {
			L = m + 1;
		}
		else {
			if (sravn == -1) {
				R = m;
			}
			else
				if (sravn == 0) {
					h = m;
					t = m;
					while (compare(l[h - 1]->data->publisher, x) == 0) {
						h--;
						if (h - 1 == 0)
							break;
					}
					while (compare(l[t + 1]->data->publisher, x) == 0) {
						t++;
						if (t + 1 == 4000)
							break;
					}
					turn->head = l[h];
					num_h = h;
					turn->tail = l[t];
					num_t = t;
					return;
				}
		}
	}
}