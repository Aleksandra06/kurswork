#include "pch.h"
#include "print.h"
#include "sort.h"
#include "search.h"
#include "tree_search.h"
#include <fstream> ///Для работы с файлом

list *base, *sbase;
queue *stack;
int *w;
int num_h = 0, num_t = 0;

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
	///tree///
	vertex *root = NULL;
	///-menu-///
	int enter = 0;
	while (true) {
		system("CLS");///Очистка экрана
		enter = 0;
		SetConsoleCP(866);
		cout << "\t------------------------------МЕНЮ------------------------" << endl;
		cout << "\t1. Посмотреть базу данных (< - назад, esc - выйти)" << endl;
		cout << "\t2. Просмотр отсортированной базы данных (Digital sort)" << endl;
		cout << "\t3. Поиск в отсортированноq базе по ключу (публикация)" << endl;
		cout << "\t4. Поиск в дереве (год)" << endl;
		cout << "\tEsc. Выход " << endl;
		cout << "\t----------------------------------------------------------" << endl;
		while ((enter != 27) && (enter != 49) && (enter != 50) && (enter != 51) && (enter != 52)) {
			if (_kbhit()) {
				enter = _getch();
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
			//delete stack->head;
			//delete stack->tail;
			delete_tree(root);
			stack = NULL;
			root = NULL;
			char X[3];
			SetConsoleCP(866);
			cout << "Введите ключ (три буквы публикации): ";
			cin >> X;
			binary_search(X, mas_sbase, stack);
			if (stack->head != stack->tail)
				print_stak(stack);
			else
				cout << "Такой записи нет";
			_getch();
			break;
		case 52:
			short int x;
			weight(stack);//заполнение массива весов
			DOP_A2(root, mas_sbase, num_h, num_t);
			cout << "Посмотреть дерево (1/0) ";
			cin >> x;
			if (x == 1) {
				print_tree(root);
			}
			cout << "Книги какого года хотите увидеть?" << endl;
			cin >> x;
			tree_search(root, x);
			break;
		}
	}
	system("PAUSE");
	return 0;
}