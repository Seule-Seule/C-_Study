
#include "iostream"
using namespace std;

class TestParent
{
public:
	TestParent(int a)
	{
		this->a = a; 
	}
	virtual void Print()  //   virtual 表明是多态
	{
		cout << "TestParent : a:" << a << endl;
	}
private:
	int a;
};

class TestChild:public TestParent
{
public:
	TestChild(int a) :TestParent(10)
	{
		this->b = a;
	}
	virtual void Print()  // virtual 可写可不写 。写醒目，是多态
	{
		cout << "TestChild : a:" << b << endl;
	}
protected:
private:
	int b;
};

void HowToPrint1(TestParent& p)
{
	p.Print();
}


void HowToPrint2(TestParent* p)
{
	p->Print();
}


int main() 
{
	int ret = 0;

	TestParent p1(20);
	TestChild c1(30);

	TestParent* pp1;
 	pp1 = &p1;
	pp1->Print();

	pp1 = &c1;
	pp1->Print();

	{
		TestParent& yp1 = p1;
		yp1.Print();
		TestParent& yp2 = c1;
		yp2.Print();
	}
	{
		HowToPrint1(p1);
		HowToPrint1(c1);

		HowToPrint2(&p1);
		HowToPrint2(&c1);
	}
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}