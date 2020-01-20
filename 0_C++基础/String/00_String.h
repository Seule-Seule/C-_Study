#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;

class String
{
public:
	String();
	String(const char* pS);
	String(const String& s);
	~String();

public:
	void Print();

public:
	String& operator=(String& sObj);
	bool  operator>(String& sObj);
	bool  operator<(String& sObj);
	void operator()(const char* pS);
	bool operator==(String& sObj);
	bool operator!=(String& sObj);
	friend ostream& operator<<(ostream& out, String& sObj);
	friend istream& operator>>(istream& out, String& sObj);
	String& operator+(String& sObj);
	String& operator-(String& sObj);
private:
	char* pString;
	int StringLen;
};

