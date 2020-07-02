#include <string>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

struct client														//Структура для создания записи: город, номер рейса, фио, дата
{

	string city;
	string number_res;
	string fio;
	string date;

};																	

bool f_check(struct client& new_memb)							//Функция проверки правильности введенных данных, где могут действительно возикнуть проблемы
{

	if (new_memb.number_res.size() > 3)
	{

		return 0;

	}

	if (new_memb.date.size() > 10)
	{

		return 0;

	}

	if ((new_memb.city.size() > 3) || 
		(new_memb.city.find('0' || '1' || '2' || '3' || '4' || '5' || '6' || '7' ||
		'8' || '9' )))
	{
		
		return 0;

	}

	return 1;

}

void f_info(void)													//Функция вывода возможностей приложения. Описание функционала
{

	cout << "Главное меню управлением записями о билетах" << endl;
	cout << "Выберите действие: " << endl;
	cout << "1 - создать новую запись" << endl;
	cout << "2 - удалить существующую запись" << endl;
	cout << "3 - просмотреть все записи" << endl;
	cout << "0 - выйти из программы" << endl;
	cout << endl;

}

void f_creating(struct client &new_memb, int &numb_of_new_membs)							//Функция для создания новой записи
{

	system("cls");

	cout	<< "Создание новой записи" << endl;
	cout	<< endl;

	cin.get();

	cout	<< "Запись номер: " << numb_of_new_membs + 1 << endl;

	cout << "Введите ФИО: ";
	getline(cin, new_memb.fio);
	cout << endl;

	cout	<< "Введите дату полета в формате дд.мм.гггг : ";
	getline	(cin, new_memb.date);
	cout	<< endl;

	cout	<< "Введите пункт назначения, используя 3-х буквенные обозначения: ";
	getline(cin, new_memb.city);
	cout	<< endl;

	cout	<< "Введите 3-х значный номер рейса: ";
	getline(cin, new_memb.number_res);
	cout	<< endl;

	bool answ = f_check(new_memb);														//Вызов проверки правильности введенных данных

	if (answ == 1)
	{

		numb_of_new_membs++;

		cout << "Запись успешно добавлена!!!" << endl;

	}

	else
	{

		cout << "Некорректный ввод данных!!! Запись не создана!!!" << endl;

	}

}

void f_deleting(vector<client> &Outtickets, int &Outnumb_of_membs)					//Функция удаления записей
{

	int count;

	system("cls");

	cin.get();

	cout	<< "Введите номер записи, котороую хотите удалить: ";
	cin		>> count;

	if ((count > Outtickets.size()) && (count <= 0) )
	{

		cout << "Такой записи не существует!!!" << endl;
		cout << endl;

	}

	else
	{

		Outtickets.erase(Outtickets.begin() + count-1);

		Outnumb_of_membs--;

		cout << "Запись успешно удалена!!!" << endl;

	}
}

void f_view(const vector<client> &tickets, const int &numb_of_membs )				//Функция просмотра всех записей
{

	system("cls");

	cout << "Просмотр всех записей" << endl;

	for (int i = 0; i < numb_of_membs; i++)
	{

		cout << "Номер записи: " << i + 1 << endl;
		cout << "ФИО пассажира: " << tickets.at(i).fio << endl;
		cout << "Дата полета: " << tickets.at(i).date << endl;
		cout << "Пункт назначения: " << tickets.at(i).city << endl;
		cout << "Номер рейса: " << tickets.at(i).number_res << endl;
		cout << endl;

	}

}

int main()														//Главная функция
{

	using namespace std;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<client> tickets;

	int direct = 1;												//Переменная, которая осуществляет выбор действия
	int numb_of_membs = 0;										//Переменная, хранящая количество записей

	do
	{															//Основной цикл программы

		f_info();												//Вызов информационного меню

		cin >> direct;

		switch (direct)											//Выбор необходимой функции
		{
		
		case(0):												//Выход из приложения
		{

			direct = 0;

			break;

		}

		case(1):												//Вызов функции создания новой записи
		{

			system("cls");

			client new_membs;

			tickets.push_back(new_membs);

			f_creating(tickets.at(numb_of_membs), numb_of_membs);



			break;

		}

		case(2):											//Вызов функции удаления записи
		{

			f_deleting(tickets, numb_of_membs);

			break;

		}

		case(3):											//Вызов функции просмотра всех записей
		{

			f_view(tickets, numb_of_membs);

			break;
		}

		default:
			break;
		}

	} while (direct != 0);									//Усолвие выхода из приложения

	cin.get();

	return 0;

}