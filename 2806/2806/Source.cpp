#include <string>
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

struct client														//��������� ��� �������� ������: �����, ����� �����, ���, ����
{

	string city;
	string number_res;
	string fio;
	string date;

};																	

bool f_check(struct client& new_memb)							//������� �������� ������������ ��������� ������, ��� ����� ������������� ��������� ��������
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

void f_info(void)													//������� ������ ������������ ����������. �������� �����������
{

	cout << "������� ���� ����������� �������� � �������" << endl;
	cout << "�������� ��������: " << endl;
	cout << "1 - ������� ����� ������" << endl;
	cout << "2 - ������� ������������ ������" << endl;
	cout << "3 - ����������� ��� ������" << endl;
	cout << "0 - ����� �� ���������" << endl;
	cout << endl;

}

void f_creating(struct client &new_memb, int &numb_of_new_membs)							//������� ��� �������� ����� ������
{

	system("cls");

	cout	<< "�������� ����� ������" << endl;
	cout	<< endl;

	cin.get();

	cout	<< "������ �����: " << numb_of_new_membs + 1 << endl;

	cout << "������� ���: ";
	getline(cin, new_memb.fio);
	cout << endl;

	cout	<< "������� ���� ������ � ������� ��.��.���� : ";
	getline	(cin, new_memb.date);
	cout	<< endl;

	cout	<< "������� ����� ����������, ��������� 3-� ��������� �����������: ";
	getline(cin, new_memb.city);
	cout	<< endl;

	cout	<< "������� 3-� ������� ����� �����: ";
	getline(cin, new_memb.number_res);
	cout	<< endl;

	bool answ = f_check(new_memb);														//����� �������� ������������ ��������� ������

	if (answ == 1)
	{

		numb_of_new_membs++;

		cout << "������ ������� ���������!!!" << endl;

	}

	else
	{

		cout << "������������ ���� ������!!! ������ �� �������!!!" << endl;

	}

}

void f_deleting(vector<client> &Outtickets, int &Outnumb_of_membs)					//������� �������� �������
{

	int count;

	system("cls");

	cin.get();

	cout	<< "������� ����� ������, �������� ������ �������: ";
	cin		>> count;

	if ((count > Outtickets.size()) && (count <= 0) )
	{

		cout << "����� ������ �� ����������!!!" << endl;
		cout << endl;

	}

	else
	{

		Outtickets.erase(Outtickets.begin() + count-1);

		Outnumb_of_membs--;

		cout << "������ ������� �������!!!" << endl;

	}
}

void f_view(const vector<client> &tickets, const int &numb_of_membs )				//������� ��������� ���� �������
{

	system("cls");

	cout << "�������� ���� �������" << endl;

	for (int i = 0; i < numb_of_membs; i++)
	{

		cout << "����� ������: " << i + 1 << endl;
		cout << "��� ���������: " << tickets.at(i).fio << endl;
		cout << "���� ������: " << tickets.at(i).date << endl;
		cout << "����� ����������: " << tickets.at(i).city << endl;
		cout << "����� �����: " << tickets.at(i).number_res << endl;
		cout << endl;

	}

}

int main()														//������� �������
{

	using namespace std;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<client> tickets;

	int direct = 1;												//����������, ������� ������������ ����� ��������
	int numb_of_membs = 0;										//����������, �������� ���������� �������

	do
	{															//�������� ���� ���������

		f_info();												//����� ��������������� ����

		cin >> direct;

		switch (direct)											//����� ����������� �������
		{
		
		case(0):												//����� �� ����������
		{

			direct = 0;

			break;

		}

		case(1):												//����� ������� �������� ����� ������
		{

			system("cls");

			client new_membs;

			tickets.push_back(new_membs);

			f_creating(tickets.at(numb_of_membs), numb_of_membs);



			break;

		}

		case(2):											//����� ������� �������� ������
		{

			f_deleting(tickets, numb_of_membs);

			break;

		}

		case(3):											//����� ������� ��������� ���� �������
		{

			f_view(tickets, numb_of_membs);

			break;
		}

		default:
			break;
		}

	} while (direct != 0);									//������� ������ �� ����������

	cin.get();

	return 0;

}