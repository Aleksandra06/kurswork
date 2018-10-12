#include "pch.h"
#include <iostream> //Для работы с клавиатурой
#include <cstdio> //Например для fread()
#include <cstring> //Для работы со строками
#include <cstdlib>
#include <fstream> ///Для работы с файлом


using namespace std;

FILE *base;

int main()
{
	setlocale(LC_ALL, "Russian");
	///*SetConsoleCP(1251);///Для считывания из бинарника на русском*/
	///SetConsoleOutputCP(1251);
	char* buf_author = new char[12];
	char* buf_title = new char[32];
	char* buf_publisher = new char[16];
	char* buf_year = new char[4];
	char* buf_num_of_page = new char[3];
	list base;
	ifstream* Base1 = new ifstream("Base1.dat");
	if (!Base1->good())///Функция good() возвращает истину, если не найдено ни одной ошибки в текущем потоке, иначе возвращает ложь.
	{
		cout << "Ошибка: невозможно открыть файл!\n" << endl;;
		system("PAUSE");
		return 0;
	}
	Base1->close();
	constr_list(base);
	while (!Base1->eof())///Функция eof() возвращает 1, если был достигнут конец файла; в противном случае она возвращает 0
	{
		Base1->getline(buf_author, 12);///Функция getline() считывает символы в буфер
		/*for (int i = 0; i < 12; i++) cout << buf_author[i]; cout << endl;*/
		Base1->getline(buf_title, 32);
		Base1->getline(buf_publisher, 16);
		Base1->getline(buf_year, 4);
		Base1->getline(buf_num_of_page, 3);
		comp_in(base, buf_author, buf_title, buf_publisher, (short int)buf_year, (short int)buf_num_of_page);
	}
	_fcloseall();//Закрытие всех потоков
	Conclusion(base);//Печать
	system("PAUSE");
	return 0;
}

/// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
/// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"