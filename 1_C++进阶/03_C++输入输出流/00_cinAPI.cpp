
#include "iostream"
using namespace std;


// cin.get()
void cinGet()
{
	// 当缓冲区没有数据时， 程序被阻塞
	char cinGetVar;
	while ((cinGetVar = cin.get()) != EOF)
	{
		cout << cinGetVar;
	}
}

// cin.get(一个参数)
void cinGetOne()
{
	char a, b, c;
	// 当缓冲区没有数据时， 程序被阻塞
	cin.get(a);
	cin.get(b);
	cin.get(c);
	cout << a << " " << b << " " << c << " " << endl;

	// 当缓冲区有数据时， 程序被直接运行，不等待
	// 支持链式编程
	cin.get(a).get(b).get(c);
	cout << a << " " << b << " " << c << " " << endl;
}

// getLine()
void cinGetLine()
{
	char buf1[256];
	char buf2[256];

	// 遇到空格即停止
	cin >> buf1;
	cout << "buf1 ->" << buf1 << "<-" << endl;

	// 可以接受空格
	cin.getline(buf2, 256);
	cout << "buf2 ->" << buf2 << "<-" << endl;
	/*
	buf1 ->aa<-  
	buf2 -> bb cc dd<-
	*/

}

// cin.ignore()
void cinIgnore()
{
	char buf1[256];
	char buf2[256];

	cin >> buf1;
	cout << "buf1 ->" << buf1 << "<-" << endl;

	// 忽略字符
	cin.ignore(2);
	/*
	aa  bbccdd 
	buf1 ->aa<-   
	buf2 ->bbccdd<-
	*/

	cin.getline(buf2, 256);
	cout << "buf2 ->" << buf2 << "<-" << endl;

 }

// cin.peek()
void cinPeek()
{
	char buf1[256];
	char buf2[256];

	cin >> buf1;
	cout << "buf1 ->" << buf1 << "<-" << endl;

	cin.ignore(2);
	// 忽略字符数大于缓冲区拥有字符时， peek 被阻塞？？

	int Test;
	// 查看缓冲区是否有数据，如果有则读出数据， 没有返回0
	Test = cin.peek();
	cout << char(Test) << "\n";

	cin.getline(buf2, 256);
	cout << "buf2 ->" << buf2 << "<-" << endl;
}

// cin.putback()
void cinPutback()
{
	cout << "Please input a number or word:";
	char tryVar;
	tryVar = cin.get();
	
	if (tryVar >= 0 && tryVar <= 9)
	{
		// 把数据吐回去
		cin.putback(tryVar);
		// 再把数据读回来
		int intVar = cin.get();
		cout << "Your input number is : " << intVar << endl;
	}
	else
	{
		// 把数据吐回去
		cin.putback(tryVar);
		// 再把数据读回来
		char buf[1024] = { 0 };
		cin.getline(buf, 1024);
		cout << "Your input word is : " << buf << endl;
	}

}

int main() 
{
	int ret = 0;


	// cinGet();
	// cinGetOne();
	// cinGetLine();
	// cinIgnore();
	// cinPeek();
	cinPutback();

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}