#include "pch.h"
#include "tree_search.h"
#include "print.h"
#include <time.h>

extern int num_h, num_t;

//void add(vertex *&point, record *x) {
//	vertex **p = &point;
//		if (p == NULL)
//		{
//			p = new vertex();
//			p->fact = new queue();
//			p->fact->head = new list();
//			p->fact->head->data = x;
//			p->fact->head->next = NULL;
//			p->fact->head->prior = NULL;
//			p->fact->tail = p->fact->head;
//			p->left = NULL;
//			p->right = NULL;
//			return;
//		}
//		while (*p) {
//		//else
//			if ((*x).year < p->fact->tail->data->year) {
//				//add(p->left, x);
//				p = p->left;
//			}
//			else
//				if ((*x).year > p->fact->tail->data->year) {
//					//add(p->right, x);
//					p = p->right;
//				}
//				else
//					//if ((*x).year == p->fact->tail->data->year) 
//				{
//					/*p->fact->tail->next = new list();
//					p->fact->tail->next->data = x;
//					p->fact->tail->next->prior = p->fact->tail;
//					p->fact->tail = p->fact->tail->next;*/
//					list *tmp = new list();
//					tmp->data = x;
//					tmp->next = p->fact->tail->next;
//					p->fact->tail->next = tmp;
//					p->fact->tail = tmp;
//				}
//	}
//}

void add(vertex *&point, record *x)
{
	vertex **p = &point;

	while (*p) {
		if ((*x).year < (*p)->fact->data->year) {
			p = &((*p)->left);
		}
		else
			if ((*x).year > (*p)->fact->data->year) {
				p = &((*p)->right);
			}
			else
				if ((*x).year == (*p)->fact->data->year) {
					(*p)->fact->next = new list();
					(*p)->fact->next->data = x;
					(*p)->fact->next->prior = (*p)->fact;
					(*p)->fact->next->next = NULL;
					return;
				}
	}
	if ((*p) == NULL) {
		(*p) = new vertex();
		(*p)->fact = new list();
		(*p)->fact->data = x;
		(*p)->fact->next = NULL;
		(*p)->fact->prior = NULL;
		(*p)->left = NULL;
		(*p)->right = NULL;
	}
}

void DOP_A2(vertex *&q, list *mas[N], int L, int R) {
	int wes = 0, summa = 0;
	int i;
	L = L - num_h;
	R = R - num_h;
	if (L <= R)
	{
		for (i = L; i <= R; i++)
			wes = wes + w[i];
		for (i = L; i <= R; i++)
		{
			if ((summa <= (wes / 2)) && ((summa + w[i]) >= (wes / 2)))
				break;
			summa = summa + w[i];
		}
		add(q, mas[i + num_h]->data);
		DOP_A2(q, mas, L + num_h, i - 1 + num_h);
		DOP_A2(q, mas, i + 1 + num_h, R + num_h);
	}
}

void weight(queue *&q) {
	srand(time_t(NULL));
	w = new int[num_t - num_h + 1];
	for (int i = 0; i < (num_t - num_h + 1); i++) {
		w[i] = rand() % 99 + 1;
	}
}

void tree_search(vertex *&p, short int x) {
	vertex *tmp = p;
	while (tmp != NULL) {
		if (tmp->fact->data->year == x) {
			print_base(tmp->fact);
			return;
		}
		else
			if (tmp->fact->data->year > x)
				tmp = tmp->left;
			else
				if (tmp->fact->data->year < x)
					tmp = tmp->right;
	}
	cout << " нига не найдена" << endl;
}

void delete_tree(vertex *&p) {
	if (p != NULL) {
		delete_tree(p->left);
		delete_tree(p->right);
		delete p;
	}
}
