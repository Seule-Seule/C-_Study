#include "00_Array.h"

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