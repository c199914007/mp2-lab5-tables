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
	cout << "Что хотите сделать?"<<endl;
	cout << "1.Ввести новый полином"<<endl;
	cout << "2.Удалить уже сущствующий"<<endl;
	cout << "3.Посмотреть на все таблицы"<<endl;
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
		cout << "Введите полином(сначала степень, потом коэффициент)" <<endl;
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
		cout<<"Неотсортированная таблица:"<<endl;
		unTable.Print();
		cout<<"Отсортированная таблица:"<<endl;
		orTable.Print();
		cout<<"Хеш-таблица:"<<endl;
		hashTable.Print();
		break;}
		catch(...)
		{
			cout<<"Такой полином уже есть!"<<endl;
		}

	case 2:
		pol.Clear();
		system("cls");
		cout << "Введите полином(сначала степень, потом коэффициент)" <<endl;
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

			cout<<"Неотсортированная таблица:"<<endl;
			unTable.Print();
			cout<<"Отсортированная таблица:"<<endl;
			orTable.Print();
			cout<<"Хеш-таблица:"<<endl;
			hashTable.Print();
		}
		catch(...)
		{
			cout << "А такого полинома в таблицах нет!" << endl;
		}

		break;

	case 3:

		system("cls");
		cout<<"Неотсортированная таблица:"<<endl;
		unTable.Print();
		cout<<"Отсортированная таблица:"<<endl;
		orTable.Print();
		cout<<"Хеш-таблица:"<<endl;
		hashTable.Print();
		break;

	default:
		break;
	}

	int q;
	cout << "1-вернуться в меню" <<endl;
	
	cout << "2-ввести еще полином" <<endl;
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
		cout<<"Еще разок"<<endl;
		goto n;
		break;
	}
}
