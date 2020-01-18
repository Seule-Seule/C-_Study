#include "05_Array.h"

Array::Array(int lenght)
{
	if (lenght < 0)
	{
		lenght = -1;
	}
	this->lenght = lenght;
	pValue = new int[lenght];
}

// Array IntArray2 = IntArray;
Array::Array(const Array& tmp)  // 深拷贝
{
	this->lenght = tmp.lenght;
	this->pValue = new int[this->lenght];
	for (int i = 0; i < this->lenght; i++)
	{
		this->pValue[i] = tmp.pValue[i];
	}
}

Array::~Array()
{
	if (this->pValue != NULL)
	{
		delete[] this->pValue;
		this->pValue = NULL;
		this->lenght = 0;
	}
}

//IntArray.setData(i, i);
void Array::setData(int index, int value)
{
	this->pValue[index] = value;
}

int Array::getData(int index)
{
	return this->pValue[index];
}

int Array::getLenght()
{
	return this->lenght;
}

int& Array::operator[](int index)
{
	return this->pValue[index];
}

Array& Array::operator=(Array& IntArray)
{
	//1 释放资源
	if (this->pValue != NULL)
	{
		delete[] this->pValue;
		this->pValue = NULL;
		this->lenght = 0;
	}

	//2 申请空间
	this->lenght = IntArray.lenght;
	this->pValue = new int[this->lenght];

	// 3 copy 数据
	for (int i = 0; i < this->lenght; i++)
	{
		this->pValue[i] = IntArray.pValue[i];
	}
	return *this;
}

bool Array::operator==(Array& IntArray)
{
	if (this->lenght != IntArray.lenght)
	{
		return false;
	}
	for (int i = 0; i < this->lenght; i++)
	{
		if (this->pValue[i] != IntArray[i])
		{
			return false;
		}
	}
	return true;
}

bool Array::operator!=(Array& IntArray3)
{
	if (this->lenght != IntArray3.lenght)
	{
		return true;
	}
	for (int i = 0; i < this->lenght; i++)
	{
		if (this->pValue[i] != IntArray3[i])
		{
			return true;
		}
	}
	return false;

	//利用已有函数
	//return !(*this == IntArray3);
}

ostream& operator<<(ostream& out, Array& IntArray)
{
	for (int i = 0; i < IntArray.lenght; i++)
	{
		out << "  " << IntArray[i];
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Array& IntArray)
{
	for (int i = 0; i < IntArray.lenght; i++)
	{
		cout << "Please input number in array " << i<<" :";
		in >> IntArray[i];
	}
	cout << "Array complete input!" << endl;
	return in;
}