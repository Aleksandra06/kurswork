#include "pch.h"
#include <fstream> ///Для работы с файлом

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
	print_base(base);
	system("PAUSE");
	return 0;
}