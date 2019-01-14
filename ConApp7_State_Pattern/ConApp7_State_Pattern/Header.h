#pragma once
#include <iostream>
using namespace std;
class Machine
{
	class State *current;
public:
	Machine();
	void setCurrent(State *s)
	{
		current = s;
	}
	void gr1();
	void gr2();
	void gr3();
};

class State
{
public:
	virtual void gr1(Machine *m)
	{
		cout << "   already gr1\n";
	}
	virtual void gr2(Machine *m)
	{
		cout << "   already gr2\n";
	}
	virtual void gr3(Machine *m)
	{
		cout << "   already gr3\n";
	}
};

class GR2 : public State
{
public:
	GR2()
	{
		cout << "   gr2-ctor ";
	};
	~GR2()
	{
		cout << "   dtor-gr2\n";
	};
	void gr1(Machine *m);
	void gr3(Machine *m);
};
class GR1 : public State
{
public:
	GR1()
	{
		cout << "   gr1-ctor ";
	};
	~GR1()
	{
		cout << "   dtor-gr1\n";
	};
	//void gr2(Machine *m);
	//void gr3(Machine *m);
	void gr2(Machine *m);
	void gr3(Machine *m);
};



class GR3 : public State
{
public:
	GR3()
	{
		cout << "   gr3-ctor ";
	};
	~GR3()
	{
		cout << "   dtor-gr3\n";
	};
	void gr1(Machine *m);
	void gr2(Machine *m);
};