#include"polinoms.h"

class UnTable
{
public:
	int compare;
	List<Polinoms> Table;
	void Insert(Polinoms a)
	{
		if ((Searh(a) == -1))
			Table.insert_at_end(a);
		else throw("Alredy exsist!");
	};
	void Del(Polinoms a)
	{
		compare = 1;
		Table.del(a);
	};
	int Searh(Polinoms a)
	{
		compare = 0;
		int i = 0;
		Node<Polinoms> *tmp = Table.head;
		if (tmp == nullptr)
			return -1;
		else
		{
			while(tmp != nullptr)
			{
				compare++;
				if (tmp->data == a)
				{
					i++;
					return i;
				}
				else {
					tmp = tmp->next;
					i++;
				}
			}
			return -1;
		}

	};
	Polinoms Get(int ind){
		compare = 0;
		if (ind > 0)
		{Node<Polinoms> *tmp = Table.head;
		int i = 0;
		while(tmp != nullptr)
		{
			compare++;
			if (i+1 == ind)
			{
				return tmp->data;
			}
			else 
			{
				tmp = tmp->next;
				i++;
			}
		}
		
		throw ("Invalid index!");
		} else throw ("Invalid index!");
	};
	void Print()
	{
		Node<Polinoms> *tmp = Table.head;
		while(tmp != nullptr)
		{
			tmp->data.Print();
			cout<<endl;
			tmp = tmp->next;
		}
		if (compare == NULL)
			compare = 0;
		cout << "Выполнено операций (сравнение и т.д.)" << compare <<endl;
	};
	bool operator == ( const UnTable a) const
	{
		Node<Polinoms> *t1 = Table.head;
		Node<Polinoms> *t2 = a.Table.head;
		if ((t1 == nullptr) && (t2 != nullptr))
			return false;
		else if ((t1 != nullptr) && (t2 == nullptr))
			return false;
		else if ((t1 == nullptr) && (t2 == nullptr))
			return true;
		else if ((t1 != nullptr) && (t2 != nullptr))
		{
			while((t1 != nullptr) && (t2 != nullptr))
			{
				if(t1->data != t2->data)
					return false;
				else 
				{
					t1 =t1->next;
					t2 = t2->next;
				}
			}
			if ((t1 == nullptr) && (t2 != nullptr))
				return false;
			else if ((t1 != nullptr) && (t2 == nullptr))
				return false;
			else return true;

		}
	}
};