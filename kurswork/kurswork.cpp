#include "pch.h"
#include "print.h"
#include "sort.h"
#include <fstream> ///Для работы с файлом

#define stop _getch(); _getch();

list *base, *sbase;

extern struct queue {
	list *head;
	list *tail;
};

queue *stack;

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
	base = new list();
	read_base(Base1, base);
	_fcloseall();

	///sort///
	sbase = new list();
	copy_base(base, sbase);
	DigitalSort(sbase);
	///-menu-///
	int enter = 1;
	while (enter != 0) {
		system("CLS");///Очистка экрана
		SetConsoleCP(866);
		cout << "\t------------------------------МЕНЮ------------------------" << endl;
		cout << "\t0. Выход" << endl;
		cout << "\t1. Посмотреть базу данных (< - назад, esc - выйти)" << endl;
		cout << "\t2. Просмотр отсортированной базы данных (Digital sort)" << endl;
		cout << "\t3. Поиск в отсортированноq базе по ключу" << endl;
		cout << "\t----------------------------------------------------------" << endl;
		cin >> enter;
		switch (enter) {
		case 1:
			print_base(base);
			stop;
			break;
		case 2:
			print_base(sbase);
			stop;
			break;
		case 3:
			char X[3];
			SetConsoleCP(866);
			cout << "Введите ключ (три буквы публикации): ";
			SetConsoleCP(1251);
			cin >> X;
			///SetConsoleCP(866);
			///cout << X;
			//Binary_Search(sbase, stack);
			stop;
			break;
		}
	}

	system("PAUSE");
	return 0;
}