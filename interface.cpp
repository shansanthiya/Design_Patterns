#include <iostream>
using namespace std;

class Interface
{
public:

	virtual void method1() = 0;
	virtual void method2() = 0;
};

class Concrete1 : public Interface
{
private:
	int myMember;

public:

	void method1();
	void method2();
};

void Concrete1::method1()
{
	cout << "method1" << endl;
}

void Concrete1::method2()
{
	cout << "method2" << endl;
}

class Concrete2 : public Interface
{
private:
	int myMember;

public:

	void method1();
	void method2();
};

void Concrete2::method1()
{
	cout << "method1*" << endl;
}

void Concrete2::method2()
{
	cout << "method2*" << endl;
}

int main(void)
{
	Interface* f = new Concrete2;

	f->method1();
	f->method2();

	return 0;
}