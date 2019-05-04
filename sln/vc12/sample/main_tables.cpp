#include "UnorderedTable.h"
#include "OrderedTable.h"
#include "HashTable.h"
#include "polinoms.h"
#include "iostream"
#include "stdlib.h"
using namespace std;

void main()
{
	UnTable unTable;
	OrTable orTable;
	HashTable hashTable;
	setlocale(LC_ALL, "Russian");
l:	system("cls");
	cout << "��� ������ �������?"<<endl;
	cout << "1.������ ����� �������"<<endl;
	cout << "2.������� ��� �����������"<<endl;
	cout << "3.���������� �� ��� �������"<<endl;
	int k  = 0;
	cin >> k;
	int newdegree = 1;
		double valye = 0;
		Mon tmp;
		Polinoms pol;
	switch (k)
	{
		
m:	case 1:
		pol.Clear();
		system("cls");
		cout << "������� �������(������� �������, ����� �����������)" <<endl;
		newdegree = 1;
		while(newdegree != 0)
		{
			cin >> newdegree;
			if(newdegree == 0)
				break;
			cout<< endl;
			cin >> valye;
			cout<< endl;
			tmp.degree = newdegree;
			tmp.Value = valye;
			pol.Insert(tmp);
		}
		try{
		unTable.Insert(pol);
		orTable.Insert(pol);
		hashTable.Insert(pol);
		cout<<"����������������� �������:"<<endl;
		unTable.Print();
		cout<<"��������������� �������:"<<endl;
		orTable.Print();
		cout<<"���-�������:"<<endl;
		hashTable.Print();
		break;}
		catch(...)
		{
			cout<<"����� ������� ��� ����!"<<endl;
		}

	case 2:
		pol.Clear();
		system("cls");
		cout << "������� �������(������� �������, ����� �����������)" <<endl;
		while(newdegree != 0)
		{
			cin >> newdegree;
			if(newdegree == 0)
				break;
			cout<< endl;
			cin >> valye;
			cout<< endl;
			tmp.degree = newdegree;
			tmp.Value = valye;
			pol.Insert(tmp);
		}
		try
		{
			unTable.Del(pol);
			orTable.Del(pol);
			hashTable.Del(pol);

			cout<<"����������������� �������:"<<endl;
			unTable.Print();
			cout<<"��������������� �������:"<<endl;
			orTable.Print();
			cout<<"���-�������:"<<endl;
			hashTable.Print();
		}
		catch(...)
		{
			cout << "� ������ �������� � �������� ���!" << endl;
		}

		break;

	case 3:

		system("cls");
		cout<<"����������������� �������:"<<endl;
		unTable.Print();
		cout<<"��������������� �������:"<<endl;
		orTable.Print();
		cout<<"���-�������:"<<endl;
		hashTable.Print();
		break;

	default:
		break;
	}

	int q;
	cout << "1-��������� � ����" <<endl;
	
	cout << "2-������ ��� �������" <<endl;
n:	cin >> q;
	switch (q)
	{
	case 1:
		goto l;
		break;
	case 2:
		goto m;
		break;
	default:
		cout<<"��� �����"<<endl;
		goto n;
		break;
	}
}
