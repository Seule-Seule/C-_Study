	


#include "iostream"
using namespace std;
#include "09_MyVector.h"

template <typename Type>
MyVector<Type>::MyVector(int size)
{
	this->ValueLen = size;
	this->ValueSpace = new Type[size];
}

template <typename Type>
MyVector<Type>::~MyVector()
{
	if (ValueSpace != NULL)
	{
		delete[] ValueSpace;
		ValueSpace = NULL;
		ValueLen = 0;
	}
}


template <typename Type>
Type& MyVector<Type>::operator[](int index)
{
	return *(ValueSpace + index);
}
template <typename Type>
MyVector<Type>::MyVector(const MyVector<Type>& obj)
{
	// 申请空间
	ValueLen = obj.ValueLen;
	ValueSpace = new Type[ValueLen];

	// 拷贝数据
	for (int i = 0; i < ValueLen; i++)
	{
		this->ValueSpace[i] = obj.ValueSpace[i];
	}
}

template <typename Type>
MyVector<Type>&  MyVector<Type>::operator=(const MyVector<Type>& obj)
{
	// 释放资源
	if (ValueSpace != NULL)
	{
		delete[] ValueSpace;
		ValueSpace = NULL;
		ValueLen = 0;
	}

	// 申请空间
	ValueLen = obj.ValueLen;
	ValueSpace = new Type[ValueLen];

	// 拷贝数据
	for (int i = 0; i < ValueLen; i++)
	{
		this->ValueSpace[i] = obj.ValueSpace[i];
	}

	return *this;
}

template <typename Type>
ostream& operator<<(ostream& out, const MyVector< Type >& obj)
{
	for (int i = 0; i < obj.ValueLen; i++)
	{
		out << " "<< obj.ValueSpace[i] ;
	}
	out << endl;
	return out;
}