#include "iostream"

using namespace std;

// ��ķ�װ
// --> �Գ�Ա�����ͳ�Ա���Խ��з�װ
// --> �Գ�Ա�����ͳ�Ա���Խ��з��ʿ���

class MyCricle
{
	double m_d;  // class Ĭ�϶����������private: �����ⲿ���ɼ�
public:
	double m_r;
	double m_s;

public:
	void setR(double r)
	{
		m_r = r;
	}
	double getS()
	{
		m_s = 3.14 * m_r * m_r;
		return m_s;
	}
};

void PrintC(MyCricle* pC)
{
	cout << "pC ��S" << pC->getS() << endl;
}

void PrintC1(MyCricle& c)
{
	cout << "C : S" << c.getS() << endl;
}

void main00() 
{
	MyCricle c1;
	c1.setR(10);
	cout << "c1 : s" << c1.getS() << endl;

	c1.setR(11);
	PrintC(&c1);

	c1.setR(22);
	PrintC1(c1);

	// c1.m_d = 20;   // ERROĬ�϶��壬���ɷ���

	cout << "Hello World!" << endl;
	system("pause");
 }

// ��Գ�Ա���Ժͳ�Ա�����ķ��ʿ���
// public: ����������ڲ����ⲿ����
// private: ֻ��������ڲ����ʣ�����������ⲿ����


class MyCricle1
{
private:
	double m_r;
	double m_s;

public:
	void setR(double r)
	{
		m_r = r;
	}
	double getS()
	{
		m_s = 3.14 * m_r * m_r;
		return m_s;
	}
};

void main01()
{
	MyCricle1 c1;
	// c1.m_r = 10; // ERRO �������ⲿ����private:���εĳ�Ա�������Ա����
	c1.setR(20);

	cout << "c1 : S" << c1.getS() << endl;

	system("pause");
}

struct stud
{
	int age;
	const char *name;
public:
	int len;
private:
	int wight;
};

void main()
{
	stud s1;
	s1.age = 20;           // Ĭ������Ϊ public �ⲿ�ɷ���
	s1.len = 175;
	//s1.wight = 60;  // ERRO ���ܷ���

}