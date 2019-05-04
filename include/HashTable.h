#include"polinoms.h"

class HashTable
{
public:
	int compare;
	List<Polinoms>* Table;
	HashTable()
	{
		Table = new List<Polinoms>[100];
		compare = 0;
	};
	void Insert(Polinoms x)
	{
		if(Searh(x) == -1.0)
		{

			Table[getHash(x)].insert_at_end(x);
		}
		else throw"Already Exsist!";
	};
	void Del(Polinoms x){
		if (Searh(x) != -1)
		Table[getHash(x)].del(x);
		else throw "InvalidElement";
	};
	double Searh(Polinoms x){
		int ind = getHash(x);
		compare = 0;
		if ( ind != -1)
		{
			Node<Polinoms> *tmp = Table[ind].head; 
			int i = 1;
			double res=0;
			for(;;)
			{ compare++;
				if (tmp == nullptr)
					return -1;
				if (tmp->data == x)
				{
					int k = i;
					int st = 0;
					while( k != 0)
					{
						k = k/10;
						st++;
					}
					res =i*pow(10, -st);
					return res+ind;
				}
					i++;
					
					tmp->next;
			}
		}
	};
	int getHash(Polinoms x)
	{  compare++;
		int res = 0, i = 1;
		Node<Mon> *tmp = x.Polinom.head;
		while( tmp!= nullptr)
		{
			int x, y ,z;
			int deg = tmp->data.degree;
			z = deg % 100;
			deg = deg/100;
			y = deg % 100;
			deg = deg/100;
			x = deg;
			res += (x+y+z)*i - tmp->data.Value;
			tmp = tmp->next;
		}
		return abs(res)%100;
	};
	Polinoms Get (double ind)
	{
		compare = 0;
		if (ind >= 0) 
		{
		int i = (int)ind;
		double k = ind - i;
		double E = 0.00000001;
		while(abs((int)k*1.0 - k) > E)
			k *=10;
		if(i < 100)
		{ 
			int j = 1;
			Node<Polinoms> *tmp = Table[i].head;
			while (tmp != nullptr)
			{
				compare++;
				if((int)k== j)
					return tmp->data;
				else
				{
					j++;
					tmp = tmp->next;
				}
			}
			throw("Invalid index");
		}
		else throw("invalid index");
		}
		else throw("invalid index");
	};
	void Print()
	{
		for(int i =0; i < 100; i++)
		{
			int j = 0;
			Node<Polinoms> *tmp = Table[i].head;
			while(tmp != nullptr)
			{
				j++;
				cout <<i << "." << j << " ";
				tmp->data.Print();
				cout<<endl;
				tmp = tmp->next;

			}
		}
		cout <<endl;
		cout << "Совершено опрераций(сравнение+вставка+вычисление хеш-функции) " << compare << endl;
	};

	bool operator == (const HashTable x) const
	{
		for(int i = 0; i < 100; i++)
		{
			if (!(Table[i] == x.Table[i]))
				return false;
		}
		return true;
	}
};