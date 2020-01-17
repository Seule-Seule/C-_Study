#pragma once

#include "iostream"

using namespace std;

class Array
{
public:
	Array(int lenght);
	Array(const Array& tmp);
	~Array();
	void setData(int index, int value);
	int getData(int index);
	int getLenght();
private:
	int lenght;
	int* pValue;
};

