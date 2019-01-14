#include<iostream>
#include<string> 
class Human {
public:
	Human()
	{
		std::cout << "Base const";
	}
};

class emp:public Human {
private:
	int emp_id;
public:
	emp()
	{
		emp_id = 100;
		std::cout << "Child const";

	}
	emp(int emp_val)
	{
		emp_id = emp_val ;
		std::cout << "Child const";
	}
	int getemp_id()
	{
		return emp_id;
	}
};

int main()
{
	emp *p = new emp(20);
	std::cout<< p->getemp_id();
	int i;
	std::cin >> i;
	return 0;
}