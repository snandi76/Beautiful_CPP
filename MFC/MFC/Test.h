#pragma once
class Test
{
public:
	Test();
	~Test();
	Test(const Test &rhs);
	Test& operator=(const Test &rhs);
};

