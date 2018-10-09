#include "pch.h"
#include <iostream> //Для работы с клавиатурой
#include <cstdio> //Например для fread()
#include <cstring> //Для работы со строками
#include <cstdlib>
///#include <fstream> ///Для работы с файлом


using namespace std;

FILE *base;

int main()
{
	setlocale(LC_ALL, "Russian");
	///*SetConsoleCP(1251);///Для считывания из бинарника на русском*/
	///SetConsoleOutputCP(1251);
	errno_t err; //Без этого почему-то не работает fopen_s
	err = fopen_s(&base,"Base1.dat", "rb");//Открыть для чтения (не удастся, если файл «Base1.dat» не существует)
	if (err != 0)
	{
		cout << "Ошибка: невозможно открыть файл" << endl;
		exit(1); 
	}
	else
	{
		cout << "Ок" << endl;
	}
	record basa[N] = { 0 };
	fread((record *)basa, sizeof(record), 4000, base);
	_fcloseall();//Закрытие всех потоков
	Conclusion(basa);//Печать
	system("PAUSE");
	return 0;
}

/// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
/// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"