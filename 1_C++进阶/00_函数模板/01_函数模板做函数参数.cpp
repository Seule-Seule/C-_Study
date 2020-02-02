
#include "iostream"
using namespace std;

template <typename T, typename T2>
void Sort(T* array, T2 size)
{
	T2 i, j;
	T tmp;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (array[i] < array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

template <typename T, typename T2>
void Print(T* array, T2 size)
{
	T2 i;
	cout << "      ";
	for (i = 0; i < size; i++)
	{
		cout << array[i] << "  ";
	}
	cout << endl;
}

int main() 
{
	int ret = 0;

	// int 类型
	{
		int array[] = { 12, 342,45,123,345,1,43,6,8,32,1,5,346,4657,13 };
		int size = sizeof(array) / sizeof(*array);
		cout << "排序之前：" << endl;
		Print<int, int>(array, size);

		cout << "排序之后：" << endl;
		Sort<int, int>(array, size);
		Print<int, int>(array, size);
	}

	// char 类型
	{
		char carrayp[] = "sfasfikljaseuidghashyuasdufg";
		int size = strlen(carrayp);
		cout << "排序之前：" << endl;
		Print<char, int>(carrayp, size);

		cout << "排序之后：" << endl;
		Sort<char, int>(carrayp, size);
		Print<char, int>(carrayp, size);
	}


	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}