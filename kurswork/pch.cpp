// pch.cpp: исходный файл, соответствующий предкомпилированному заголовку; нужен для компиляции

#include "pch.h"
#include <Windows.h>///Для русских букв
#include <iostream> ///Для работы с клавиатурой
#include <cstdio> ///Например для fread()
#include <cstring> ///Для работы со строками
#include <cstdlib>

using namespace std;

void Conclusion (record *bas) {
	int M = 30; ///По столько элементов выводится на экран
	int i, j, flag = 1, num = 0;
	while (flag) {
		SetConsoleCP(1251);///Меняем кодировку
		i = 0;
		while ((i < M) && (num < N)) {
			for (j = 0; j < 12; j++) cout << bas[num].author[j];
			cout << "  ";
			for (j = 0; j < 32; j++) cout << bas[num].title[j];
			cout << "  ";
			cout << bas[num].publisher; cout << "  ";
			cout << bas[num].year; cout << "  ";
			cout << bas[num].num_of_page << endl;
			num++;
			i++;
		}
		SetConsoleCP(866);///Возвращаем кодировку
		if (num < N) {
			cout << "Продолжить? (1/0): ";
			cin >> flag;
		}
		else {
			if (num == N) {
				cout << "Конец" << endl;
				flag = 0;
			}
		}
	}
}
