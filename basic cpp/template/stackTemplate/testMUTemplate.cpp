//
// Stack64 Class Exercise
//
//
#include "mu_test.h"
#include "StackTemplate.h"
#include "stdio.h"

UNIT(constructors)
	Stack <int> s;

	ASSERT_THAT(s.isEmpty());
	ASSERT_THAT(s.isFull() == false);
	ASSERT_EQUAL_INT(0, s.size());
END_UNIT

UNIT(is_lifo_int)
	Stack <int> s;

	int a = 1;
	ASSERT_THAT(s.push(a));

	ASSERT_THAT(s.isEmpty() == false);
	ASSERT_THAT(s.isFull() == false);
	ASSERT_EQUAL(s.size(), 1);

	int b=2;
	ASSERT_THAT(s.push(b));
	ASSERT_THAT(s.isEmpty() == false);
	ASSERT_THAT(s.isFull() == false);
	ASSERT_EQUAL(s.size(), 2);

	int c=3;
	ASSERT_THAT(s.pop(c));
	ASSERT_EQUAL(s.size(), 1);
	ASSERT_EQUAL(c, b);

END_UNIT

UNIT(is_lifo_float)
	Stack <float> s;

	float a = 1.1;
	ASSERT_THAT(s.push(a));

	ASSERT_THAT(s.isEmpty() == false);
	ASSERT_THAT(s.isFull() == false);
	ASSERT_EQUAL(s.size(), 1);

	float b=2.2;
	ASSERT_THAT(s.push(b));
	ASSERT_THAT(s.isEmpty() == false);
	ASSERT_THAT(s.isFull() == false);
	ASSERT_EQUAL(s.size(), 2);

	float c=3.3;
	ASSERT_THAT(s.pop(c));
	ASSERT_EQUAL(s.size(), 1);
	ASSERT_EQUAL(c, b);

END_UNIT

UNIT(empty_full)
	Stack <int> s;

	// push
	for (int i=0; i < static_cast<int>(s.capacity()); ++i)
	{
		ASSERT_THAT(s.push(i));
	}
	ASSERT_EQUAL(s.size(), s.capacity());

	// full
	ASSERT_THAT(s.isFull());
	ASSERT_THAT(s.push(99) == false);

	// pop
	for (int i=0; i < static_cast<int>(s.capacity()); ++i)
	{
		int r;
		ASSERT_THAT(s.pop(r));
		ASSERT_EQUAL_INT(r, (s.capacity() - 1 - i));
	}
	ASSERT_EQUAL(s.size(), 0);

	// empty
	int c = -1;
	ASSERT_THAT(s.isEmpty());
	ASSERT_THAT(s.pop(c) == false);
	ASSERT_EQUAL(c, -1);
	
	int stam;
	ASSERT_THAT(s.top(stam) == false);
	ASSERT_EQUAL(c, -1);

END_UNIT


TEST_SUITE(Stack [fixed size] of ints)

	TEST(constructors)
	TEST(is_lifo_int)
	TEST(is_lifo_float)
	TEST(empty_full)

END_SUITE
