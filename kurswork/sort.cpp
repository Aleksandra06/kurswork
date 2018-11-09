#include "sort.h"
#include "pch.h"

const int L = 3;//���������� �������� ��� ����������

struct queue {//�������
	list *head;
	list *tail;
} Q;

void DigitalSort(list *&S) {
	queue Q[256];//���������� �������
	list *p = NULL;
	for (int i = 0; i < 256; i++) {
		Q[i].tail = (list*)&(Q[i].head);//������������� �������� 
	}
	for (int j = 0; j < L; j++) {//���� �� ��������� ����
		for (int i = 0; i < 256; i++) {
			Q[j].tail = Q[j].head = NULL;
		}
		//p = S;//�-��������� �� ���������, ���. ����� ������������� 
		while (S != NULL) {//��������� ������ �� �������
			int d = S->data->publisher[j] + 128;//�������� ����
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
		S = NULL;//(��������� �� ���������� � �) ����� ������������ ��� ��� * ������
		int i;
		for (i = 0; i < 256; i++) {
			if (Q[i].head != NULL)
				break;
		}
		S = Q[i].head;
		//cout << S->data->year;
		p = Q[i].tail;
		for (int k = i + 1; k < 256; k++) {//�������� ������ �� ��������
			if (Q[k].head != NULL) {//��������� ������ �� ������� ������� ����������
				p->next = Q[k].head;
				p = Q[k].tail;
			}
		}
		//p->next = NULL;
	}
		
}