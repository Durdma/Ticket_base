#include <string>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

struct client
{

	string city;
	string number_res;
	string fio;
	int date;

};

void f_info(void)
{

	cout << "������� ���� ����������� �������� � �������" << endl;
	cout << "�������� ��������: " << endl;
	cout << "1 - ������� ����� ������" << endl;
	cout << "2 - ������� ������������ ������" << endl;
	cout << "3 - ����������� ��� ������" << endl;
	cout << "0 - ����� �� ���������" << endl;

}

void f_creating(struct client &new_memb)
{

	system("cls");

	cout	<< "�������� ����� ������" << endl;
	cout	<< endl;

	cout	<< "������� ���� ������: ";
	cin		>> new_memb.date;
	cout	<< endl;

	cout	<< "������� ����� ����������: ";
	cin		>> new_memb.city;
	cout	<< endl;

	cout	<< "������� 3-� ������� ����� �����: ";
	cin		>> new_memb.number_res;
	cout	<< endl;
	
	cout	<< "������� ���: ";
	cin		>> new_memb.fio;
	cout	<< endl;

}

int main()
{

	using namespace std;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<client> tickets;

	int direct = 1;
	int numb_of_membs = 0;

	do
	{

		f_info();

		cin >> direct;

		switch (direct)
		{
		
		case(0):
		{

			direct = 0;

			break;

		}

		case(1):
		{

			client new_membs;

			tickets.push_back(new_membs);

			f_creating(tickets.at(numb_of_membs));

			system("cls");

			numb_of_membs++;

			break;

		}

		default:
			break;
		}

	} while (direct != 0);

	cin.get();

	return 0;

}