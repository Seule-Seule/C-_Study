/*
#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int	ErroMsg = 0;
	
	
	return ErroMsg;
}
*/
#include "iostream" // ����C++ͷ  //iostream.h

using namespace std;  //std ��׼�����ռ䣬�����˺ܶ��׼���塣

void main_00() {

	// cout ��׼��� ���󣿣��� �����Ǻ���Ļ
	// << ���Ʋ����� �������ƣ��� ��˵�ǲ���������
	// endl == \n
	cout << "Hello World!" << endl;
	system("pause");
}

//������̣�Բ�������
void main_01() {
	double	r = 0;
	double	s = 0;
	cout << "����뾶��";
	cin >> r;

	s = 3.14  *r * r;

	cout << "�����" << s << endl;

	cout << "Hello World!" << endl;
	system("pause");
}


//�������
//�ڴ���䣿��
//�෽���������ݣ���
class  Round
{
public:
	double	m_r;
	double	m_s;

public:
	void SetR(double r)
	{
		m_r = r;
	}
	double GetS()
	{
		m_s = m_r * m_r * 3.14;
		return m_s;
	}
};

void main() {
	Round	c;
	double	r;
	cout << "����뾶��";
	cin >> r;
	c.SetR(r);

	cout << "�����" << c.GetS() << endl;
	cout << "Hello World!" << endl;
	system("pause");
}