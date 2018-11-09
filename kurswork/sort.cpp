#include "sort.h"
#include "pch.h"

const int L = 3;//количество символов для сортировки

struct queue {//очереди
	list *head;
	list *tail;
} Q;

void DigitalSort(list *&S) {
	queue Q[256];//объявление очереди
	list *p = NULL;
	for (int i = 0; i < 256; i++) {
		Q[i].tail = (list*)&(Q[i].head);//инициализация очередей 
	}
	for (int j = 0; j < L; j++) {//цикл по колиеству байт
		for (int i = 0; i < 256; i++) {
			Q[j].tail = Q[j].head = NULL;
		}
		//p = S;//п-указатель на структуру, кот. будет сортироваться 
		while (S != NULL) {//разбиваем список на очереди
			int d = S->data->publisher[j] + 128;//получаем байт
			cout << " d=" << d;
			Q[d].head;
			p = Q[d].tail;
			if (Q[d].head == NULL)
				Q[d].head = S;
			else
				p->next = S;
			p = Q[d].tail = S;
			S = S->next;
			p->next = NULL;
		}
		cout << endl << endl;
		S = NULL;//(указатель на укзаательи — П) чтобы использовать его как * списка
		int i;
		for (i = 0; i < 256; i++) {
			if (Q[i].head != NULL)
				break;
		}
		S = Q[i].head;
		//cout << S->data->year;
		p = Q[i].tail;
		for (int k = i + 1; k < 256; k++) {//создания списка из очередей
			if (Q[k].head != NULL) {//добавляем только те очереди которые изменились
				p->next = Q[k].head;
				p = Q[k].tail;
			}
		}
		//p->next = NULL;
	}
		
}