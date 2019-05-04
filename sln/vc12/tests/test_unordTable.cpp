#include <gtest.h>
#include "UnorderedTable.h"
#include "polinoms.h"

TEST(UnorderedTable, can_insert)
{
	UnTable t;
	List<Polinoms> t2;
	Polinoms t3;
	for( int i = 0; i < 4; i++)
	{
		Mon tmp;
		tmp.Value = i+1;
		tmp.degree = i*1000+i*100+i;
		t3.Insert(tmp);
	}
	t.Insert(t3);
	t2.insert_at_end(t3);
	EXPECT_EQ(t.Table,t2);
}

TEST(UnorderedTable, cant_insert_simlar_element)
{
	UnTable t;
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
TEST(UnorderedTable, can_delete)
{
	UnTable t1, t2;
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
TEST(UnorderedTable, cant_delete_invalid_element)
{
	UnTable t1;
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
TEST(UnorderedTable, can_searh)
{
	UnTable t1;
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
	EXPECT_EQ(t1.Searh(t3), 2);
}
TEST(UnorderedTable, cant_search_invalid_element)
{
	UnTable t1;
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
TEST(UnorderedTable, can_get)
{
	UnTable t1;
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
	EXPECT_EQ(t3,t1.Get(2));
}
TEST(UnorderedTable, cant_get_invalid_element)
{
	UnTable t1;
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
TEST(UnorderedTable, cant_get_invalid_element_2)
{
	UnTable t1;
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
	ASSERT_ANY_THROW(t1.Get(-3));
}
