#include "sort.h"


void rasheplen(list* &head, list* &a, list* &b, int &n) {
	list *p, *q;
	a = head;
	b = head->next;
	n = 1;
	p = a;
	q = b;
	while (q)
	{
		n++;
		p->next = q->next;
		p = q;
		q = q->next;
	}
}

int sravn(record *a, record *b) {
	for (int i = 0; i < 3; i++) {
		if ((int)a->publisher[i] < (int)b->publisher[i])
			return -1;
		else
			if ((int)a->publisher[i] > (int)b->publisher[i])
				return 1;
	}
	for (int i = 0; i < 3; i++) {
		if ((int)a->author[i] < (int)b->author[i])
			return -1;
		else
			if ((int)a->author[i] > (int)b->author[i])
				return 1;
	}
	return 0;
}

//void mergesort(list* &head){
//	int L = 3;
//	tQ *Q;
//	for (int j = L; j > 0; j--) {
//		for (int i = 0; i < 255; i++) {
//			Q[i].tail = (list*) &(Q[i].head);
//		}
//		p = s;
//	}
//


	//int m, n;
	//list  *a, *b;
	//tQ  c[3];
	//int p, q, r;
	//int i;
	//if (head == NULL) return;
	//rasheplen(head, a, b, n);
	//p = 1;
	//while (p < n)
	//{
	//	c[0].tail = (list*) &(c[0].head);
	//	c[1].tail = (list*) &(c[1].head);
	//	i = 0, m = n;
	//	while (m > 0)
	//	{
	//		if (m >= p) q = p; else q = m;
	//		m -= q;
	//		if (m >= p) r = p; else r = m;
	//		m -= r;

	//		while ((q > 0) && (r > 0))
	//		{
	//			if ((sravn(a->data,b->data)==-1) || (sravn(a->data, b->data) == 0))
	//			{
	//				c[i].tail->next = a;
	//				c[i].tail = a;
	//				a = a->next;
	//				q--;
	//			}
	//			else
	//			{
	//				c[i].tail->next = b;
	//				c[i].tail = b;
	//				b = b->next;
	//				r--;
	//			}
	//		}
	//		while (q > 0)
	//		{
	//			c[i].tail->next = a;
	//			c[i].tail = a;
	//			a = a->next;
	//			q--;
	//		}
	//		while (r > 0)
	//		{
	//			c[i].tail->next = b;
	//			c[i].tail = b;
	//			b = b->next;
	//			r--;
	//		}
	//		i = 1 - i;
	//	}
	//	a = c[0].head; b = c[1].head;
	//	p = 2 * p;
	//}
	//c[0].tail->next = 0;
	//head = c[0].head;
	//return;
//}