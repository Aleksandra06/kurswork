#include "print.h"
#include "pch.h"

void print_record(record *t) {
	SetConsoleCP(1251);///������ ���������
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
	int M = 20; ///�� ������� ��������� ��������� �� �����
	int i, flag = 1, num = 1;
	int c = 0;
	while (flag) {
		i = 0;
		system("cls"); cout << c << endl;
		cout << "+-----+------------+--------------------------------+----------------+------+-----+" << endl;
		while ((i < M) && (num <= N)) {
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
		SetConsoleCP(866);///���������� ���������
		c = _getch();
		_getch();
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
