#include "code.h"
#include "pch.h"
#include <cmath>
#include <iomanip>

using namespace std;

const int n = 256;

struct code {
	unsigned char a;
	float p;
	int word[50];
	int l;
} C[n];

long int num = 0;
float entropy = (float)(0);
float averageLength = (float)(0);

void open() {
	int i, j = 0;
	unsigned char ch;
	FILE *f;
	errno_t err; 
	err = fopen_s(&f, "Base1.dat", "rb");
	for (i = 0; i < n; i++) {
		C[i].a = i;
		C[i].p = (float)(0);
		C[i].l = 0;
	}
	int flag = 100;
	while (!feof(f)) {
		fscanf_s(f, "%c", &ch);
		C[ch].p = C[ch].p + 1.0;
		num++;
	}
	fclose(f);
	for (i = 0; i < n; i++)
		if (C[i].p != (float)(0)) {
			C[i].p /= (float)num;
			j++;
		}
	num = (unsigned long int)(j);
}

void chance() {
	int i, k;
	int j;
	code temp;
	for (i = 1; i < n - 1; i++) {
		k = 1;
		if (C[i].p == (float)(0))
			for (j = i + 1; j < n; j++)
				if (k)
					if (C[j].p != (float)(0)) {
						temp = C[i];
						C[i] = C[j];
						C[j] = temp;
						k = 0;
					}
	}
	i = 0;
	while (C[i].p != 0.0) i++;
	num = (unsigned long int)(i);
	for (i = 1; i < num; ++i)
		for (j = 2; j < num; ++j) {
			if (C[j].p > C[j - 1].p) {
				temp = C[j - 1];
				C[j - 1] = C[j];
				C[j] = temp;
			}
		}
}

int shanon()
{
	float q[n];
	q[0] = 0;
	for (int i = 1; i < num; i++)
	{
		q[i] = q[i - 1] + C[i].p;
		C[i].l = ceil(-log(C[i].p) / log(2));
	}
	for (int i = 1; i < num; i++)
	{
		for (int j = 1; j <= C[i].l; j++)
		{
			q[i - 1] *= 2;
			C[i].word[j] = floor(q[i - 1]);
			if (q[i - 1] > 1) q[i - 1] -= 1;

		}
	}
	return 0;
}

void print() {
	int j;
	int i;
	float check = 0;
	for (i = 1; i < num; i++) {
		entropy += -C[i].p * log(C[i].p) / log(2);
		averageLength += C[i].l * C[i].p;
	}

	for (i = 1; i < num; i++) {
		cout << setw(1) << (char)C[i].a << setw(3) << " ";
		cout << (float)C[i].p << " " << setw(2)
			<< (int)C[i].l << " ";
		for (j = 1; j <= C[i].l; ++j)
			cout << C[i].word[j];
		cout << endl;
	}
	cout << endl;
	cout << setw(8) << entropy << " - Ёнтропи€" << endl;
	cout << setw(8) << averageLength << " - —редн€€ длина" << endl;
	cout << setw(8) << entropy + 1 << " > " << averageLength << endl << endl;
	for (int i = 0; i <= num; ++i) check += (float)C[i].p;
	cout << "Sum of all chances: " << check << endl << endl;
	_getch();
}