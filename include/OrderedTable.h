#include "polinoms.h"
class OrTable
{
public:
	int compare;
	Polinoms* Table;
	int maxSize, realSize;
	Polinoms NULLPOL;

	OrTable()
	{
		compare = 0;
		Mon a;
		a.Value = 0;
		a.degree = 0;
		NULLPOL.Insert(a);
		Table = new Polinoms[10];
		for(int i = 0; i < 10; i++)
		{
			Table[i] = NULLPOL;
		}
		maxSize = 10;
		realSize = 0;
	};

	void Insert(Polinoms x)
	{
		compare = 0;
		if(Table[0] == NULLPOL)
		{
			compare++;
			Table[0] = x;
			realSize++;
			return;
		}
		else 
		{ 
			int i = 0;
			while (Table[i] != NULLPOL)
			{ 
				compare++;
				if (Table[i] != x)
				{
					if (Table[i] < x)
					{
						if (maxSize != realSize)
						{
							Polinoms tmp = Table[i];
							Table[i] = x;
							int ind = i;
							for(i = realSize + 1; i > ind+1; i--)
							{
								compare++;
								Table[i] = Table[i-1];
							} 
							Table[ind+1] = tmp;
							realSize++;
							return;
						}
						else
						{
							Polinoms *ttmp = new Polinoms[2*realSize];
							for (int j = 0; j < i ; j++ )
							{
								compare++;
								ttmp[j] = Table[j];
							}
							ttmp[i] = x;
							for(int j = realSize+1; j > i; j--)
								ttmp[j] = Table[j-1];
							Table = ttmp;
							realSize++;
							maxSize =2*maxSize;
							return;
						}
					}
					else i++;
				} 
				else
					throw ("Already exsist");
			}
			if (maxSize != realSize)
						{
							Polinoms tmp = Table[i];
							Table[i] = x;
							int ind = i;
							for(i = realSize + 1; i > ind+1; i--)
							{
								compare++;
								Table[i] = Table[i-1];
							} 
							Table[ind+1] = tmp;
							realSize++;
							return;
						}
						else
						{
							Polinoms *ttmp = new Polinoms[2*realSize];
							for (int j = 0; j < i ; j++ )
							{
								compare++;
								ttmp[j] = Table[j];
							}
							ttmp[i] = x;
							for(int j = realSize+1; j > i; j--)
								ttmp[j] = Table[j-1];
							Table = ttmp;
							realSize++;
							maxSize =2*maxSize;
							return;
						}
		}
	};

	void Del(Polinoms x)
	{
		if(Table[0]!= NULLPOL)
		{
			int ind = Searh(x);
			if(ind != -1)
			{
				for(int i = ind-1; i < realSize-1; i++)
				{
					Table[i] = Table[i+1];
				}
				realSize--;
				return;
			}
			else throw ("Invalid element!");
		}
		else throw("Empty OrTable! Can`t delele");
	};

	int Searh(Polinoms x)
	{
		compare = 0;
		int left = 0, right = realSize-1;
		while((left<=right) && (left!= right-1))
		{
			compare++;
			if(Table[(right-left)/2] < x)
			{
				left = (right-left)/2 + 1;
			}
			else if(Table[(right-left)/2] > x)
			{
				right = (right-left)/2 - 1;
			}
			else return (right-left)/2 ;
		}
		if (Table[left] == x)
			return left+1;
		else return -1;
	};

	Polinoms Get(int ind)
	{
		compare = 1;
		if ((ind > realSize)||(ind < 1))
			throw ("Invalid Ingex!");
		else return Table[ind-1];
	}

	void Print()
	{			
		for (int i = 0; i < realSize; i++)
		{
			cout <<" "<<i<<" ";
			Table[i].Print();
			cout << endl;
		}
		cout << "Выполнено операций(сравнение и т.д.)" << compare << endl;
	};

	bool operator == (const OrTable a) const
	{

		if (realSize == a.realSize)
		{
			for (int i = 0; i < realSize; i ++)
				if (Table[i] != a.Table[i])
					return false;
			return true;
		}
		else return false;
	}
};