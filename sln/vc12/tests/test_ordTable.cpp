#include <gtest.h>
#include "OrderedTable.h"
#include "polinoms.h"

TEST(OrderedTable, can_insert)
{
	OrTable t = OrTable();
	OrTable t4 = OrTable();
	Polinoms *t2 = new Polinoms[1];
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	t.Insert(t3);
	t2[0] = t3;
	t4.Table = t2;
	t4.realSize = 1;

	EXPECT_EQ(t,t4);
}

TEST(OrderedTable, insert_is_sort)
{
	OrTable t1 = OrTable();
	OrTable t2 = OrTable();
	Polinoms *arr = new Polinoms[3];
	Mon tmp ;
	tmp.Value = 1;
	tmp.degree = 303030;
	arr[2].Insert(tmp);
	t1.Insert(arr[2]);
	tmp.degree = 303031;
	arr[1].Insert(tmp);
	t1.Insert(arr[1]);
	tmp.degree = 303032;
	arr[0].Insert(tmp);
	t1.Insert(arr[0]);
	t2.realSize = 3;
	t2.Table = arr;

	EXPECT_EQ(t1,t2);
}
TEST(OrderedTable, cant_insert_simlar_element)
{
	OrTable t;
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
TEST(OrderedTable, can_delete)
{
	OrTable t1, t2;
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	t1.Insert(t3);
	t2.Insert(t3);
	for( int i = 1; i < 5; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	t1.Insert(t3);
	t1.Del(t3);
	EXPECT_EQ(t1,t2);
}
TEST(OrderedTable, cant_delete_invalid_element)
{
	OrTable t1;
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
TEST(OrderedTable, can_searh)
{
	OrTable t1;
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
	EXPECT_EQ(t1.Searh(t3), 1);
}
TEST(OrderedTable, cant_search_invalid_element)
{
	OrTable t1;
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
TEST(OrderedTable, can_get)
{
	OrTable t1;
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
	EXPECT_EQ(t3,t1.Get(1));
}
TEST(OrderedTable, cant_get_invalid_element)
{
	OrTable t1;
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
TEST(OrderedTable, cant_get_invalid_element_2)
{
	OrTable t1;
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