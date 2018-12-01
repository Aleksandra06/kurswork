#include "pch.h"
#include "print.h"
#include "sort.h"
#include "search.h"
#include <fstream> ///Для работы с файлом

list *base, *sbase;

queue *stack;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(866);
	///SetConsoleCP(1251);///Для считывания из бинарника на русском*/
	///SetConsoleOutputCP(1251);
	FILE *Base1;
	errno_t err; 
	err = fopen_s(&Base1, "Base1.dat", "rb");//Открыть для чтения (не удастся, если файл «Base1.dat» не существует)
	if (err != 0)
	{
		cout << "Ошибка: невозможно открыть файл" << endl;
		exit(1);
	}
	base = new list();
	read_base(Base1, base);
	_fcloseall();

	///sort///
	sbase = new list();
	copy_base(base, sbase);
	DigitalSort(sbase, 0);
	list *mas_sbase[N];
	masiving(sbase, mas_sbase);
	///-menu-///
	int enter = 0;
	while (true) {
		system("CLS");///Очистка экрана
		enter = 0;
		SetConsoleCP(866);
		cout << "\t------------------------------МЕНЮ------------------------" << endl;
		cout << "\t1. Посмотреть базу данных (< - назад, esc - выйти)" << endl;
		cout << "\t2. Просмотр отсортированной базы данных (Digital sort)" << endl;
		cout << "\t3. Поиск в отсортированноq базе по ключу" << endl;
		cout << "\t----------------------------------------------------------" << endl;
		while ((enter != 27) && (enter != 49) && (enter != 50) && (enter != 51)) {
			if (_kbhit()) {
				enter = _getch();
				cout << enter;
			}
		}
		switch (enter) {
		case 27: return 0;
		case 49:
			print_base(base);
			break;
		case 50:
			print_base(sbase);
			break;
		case 51:
			char X[3];
			SetConsoleCP(866);
			cout << "Введите ключ (три буквы публикации): ";
			cin >> X;
			binary_search(X, mas_sbase, stack);
			print_stak(stack);
			break;
		}
	}

	system("PAUSE");
	return 0;
}