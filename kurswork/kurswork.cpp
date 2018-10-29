#include "pch.h"
#include <fstream> ///Для работы с файлом
#include <conio.h>///Для _getch например

#define stop _getch(); _getch();

int main()
{
	setlocale(LC_ALL, "Russian");
	///*SetConsoleCP(1251);///Для считывания из бинарника на русском*/
	///SetConsoleOutputCP(1251);
	FILE *Base1;
	errno_t err; 
	err = fopen_s(&Base1, "Base1.dat", "rb");//Открыть для чтения (не удастся, если файл «Base1.dat» не существует)
	if (err != 0)
	{
		cout << "Ошибка: невозможно открыть файл" << endl;
		exit(1);
	}
	else
	{
		cout << "Ок" << endl;
	}
	list *base;
	base = new list();
	read_base(Base1, base);
	_fcloseall();//Закрытие всех потоков
	list *sort_base = base;
	mergesort(base);

	///-menu-///
	int enter = 1;
	while (enter != 0) {
		system("CLS");///Очистка экрана
		cout << "---------------МЕНЮ----------------" << endl;
		cout << "0. Выход" << endl;
		cout << "1. Посмотреть базу данных \n   (< - назад, esc - выйти)" << endl;
		cout << "2. Отсортировать (mergesort)" << endl;
		cin >> enter;
		switch (enter) {
		case 1:
			print_base(base);
			stop;
			break;
		case 2:
			stop;
			break;
		}
	}

	system("PAUSE");
	return 0;
}