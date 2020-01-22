
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;

#include "00_String.h"

void main() 
{
	String s1;
	String s2("name s2");
	String s3 = s2;

	s2.Print();

	//重载等号
	// s1.operator=(s2)
	// String& operator=(String& sObj)
	s1 = s2;
	s3 = s2 = s1;
	 

	// 重载括号()
	// s1.operator()(const char *pS)
	// void operator()(const char *pS);
	s1("sssss");
	s3("aaaa");

	// 重载> <
	// s1.operator>(s2)
	//bool  operator>(String& sObj)
	//bool  operator<(String& sObj)
	if (s1 > s2)
	{
		cout << "s1 > s2" << endl;
	}
	if (s3 < s2)
	{
		cout << "s3 < s2" << endl;
	}

	//重载 == !=
	// s1.operator==(s3)
	// String& operator==(String& sObj);
	// String& operator!=(String& sObj);
	s1 = s2;
	if (s1 == s2)
	{
		cout << "s1 == s2" << endl;
	}
	if (s3 != s2)
	{
		cout << "s3 != s2" << endl;
	}

	//重载<< >>
	//ostream& operator<<(ostream& out, String& sObj);
	//istream& operator>>(istream& out, String& sObj);
	//cout << s1 << s2 << endl;
	//cin >> s3 >> s2;
	cout << s1 << s2 << s3 << endl;

	// 重载+ -
	// s1.operator+(s2)
	// String& operator+(String& sObj);
	s3 = s1 + s2;
	cout << s1 << s2 << s3 << endl;
	// String& operator-(String& sObj);
	s1("name name s2");
	s3 = s1 - s2;
	s3 = s1 - s2;
	cout << s1 << s2 << s3 << endl;
	

	// 指针外露
	// 拷贝时注意已分配内存的大小！！
	// if(len>s3.GetStringLen){拷贝操作};
	strcpy(s3.GetpSting(), "aaaaa");
	cout << s1 << s2 << s3 << endl;
	cout << "Hello World!" << endl;
	system("pause");

}