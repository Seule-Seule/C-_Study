
#include "iostream"
using namespace std;



class IntArray
{
public:
	IntArray(int len);
	~IntArray();
	int getLen();

public:
	class SizeError
	{
	public:
		SizeError(int size)
		{
			this->size = size;
		}
		virtual void printSize() = 0;
	public:
		int size;
	};
	class SmallZero : public SizeError
	{
	public:
		SmallZero(int size): SizeError(size)
		{
		}
		virtual void printSize()
		{
			cout << size << endl;
		}
	};
	class TooBig : public SizeError
	{
	public:
		TooBig(int size) : SizeError(size)
		{
		}
		virtual void printSize()
		{
			cout << size << endl;
		}
	};
	class TooSmall : public SizeError
	{
	public:
		TooSmall(int size) : SizeError(size)
		{
		}
		virtual void printSize()
		{
			cout << size << endl;
		}
	};
private:
	int* place;
	int len;
};

IntArray::IntArray(int len)
{
	if (len < 0)
	{
		throw SmallZero(len);
	}
	else if (len > 1000)
	{
		throw TooBig(len);
	}
	else if (len < 10)
	{
		throw TooSmall(len);
	}
	this->len = len;
	this->place = new int[len];
}
IntArray::~IntArray()
{
	if (NULL != place)
	{
		delete[] place;
		place = NULL;
		len = 0;
	}
}
int IntArray::getLen()
{
	return len;
}

int main() 
{
	int ret = 0;
	try
	{
		IntArray a(5);
	}
	catch (IntArray::SmallZero& e)
	{
		e.printSize();
	}
	catch (IntArray::TooBig & e)
	{
		e.printSize();
	}
	catch (IntArray::TooSmall & e)
	{
		e.printSize();
	}
	catch (...)
	{
		cout << "未知类型异常" << endl;
	}
	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}