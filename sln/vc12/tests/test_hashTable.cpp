#include <gtest.h>
#include "HashTable.h"
#include "polinoms.h"

TEST(HashTable, can_insert)
{
	HashTable t = HashTable();
	HashTable t2 = HashTable();
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
		t.Insert(t3);
		List<Polinoms> a;
		a.insert_at_end(t3);
		switch (i)
		{
		case 0:
			t2.Table[1] = a;
			break;
		case 1:
			t2.Table[9] = a;
			break;
		case 2:
			t2.Table[30] = a;
			break;
		case 3:
			t2.Table[62] = a;
			break;
		default:
			break;
		}
	}
	EXPECT_EQ(t,t2);
}

TEST(HashTable, cant_insert_simlar_element)
{
	HashTable t;
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	t.Insert(t3);
	ASSERT_ANY_THROW(t.Insert(t3));
}
TEST(HashTable, can_delete)
{
	HashTable t = HashTable();
	HashTable t2 = HashTable();
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		List<Polinoms> a;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
		t.Insert(t3);
		a.insert_at_end(t3);
		switch (i)
		{
		case 0:
			t2.Table[1] = a;
			break;
		case 1:
			t2.Table[9] = a;
			break;
		case 2:
			t2.Table[30] = a;
			break;
		case 3:
			break;
		default:
			break;
			a.del(t3);
		}
	}
	t.Del(t3);
	EXPECT_EQ(t, t2);
}
TEST(HashTable, cant_delete_invalid_element)
{
	HashTable t1;
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	t1.Insert(t3);
	for( int i = 5; i < 7; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	ASSERT_ANY_THROW(t1.Del(t3));
}
TEST(HashTable, can_searh)
{
	HashTable t = HashTable();
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
		t.Insert(t3);
	}
	EXPECT_EQ(t.Searh(t3), 62.1);
}
TEST(HashTable, cant_search_invalid_element)
{
	HashTable t1;
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	t1.Insert(t3);
	for( int i = 1; i < 5; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	EXPECT_EQ(t1.Searh(t3), -1);
}
TEST(HashTable, can_get)
{
	HashTable t = HashTable();
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
		t.Insert(t3);
	}
	EXPECT_EQ(t.Get(62.1), t3);
}
TEST(HashTable, cant_get_invalid_element)
{
	HashTable t1;
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	t1.Insert(t3);
	for( int i = 1; i < 5; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	t1.Insert(t3);	
	ASSERT_ANY_THROW(t1.Get(3));
}
TEST(HashTable, cant_get_invalid_element_2)
{
	HashTable t1;
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	t1.Insert(t3);
	ASSERT_ANY_THROW(t1.Get(-4));
}