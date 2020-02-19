#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
using namespace std;
#include <fstream>



// 普通读写操作
void writeReadFile(const char * _fileName)
{
	const char* fileName = _fileName;
	// 建立一个输出流对象和文件关联
	ofstream  fout(fileName);
	if (!fout)
	{
		cout << "文件打开失败";
		return;
	}
	fout << "test line one. " << endl;
	fout << "test line two. " << endl;
	fout << "test line three. " << endl;
	fout.close();

	// 建立一个输入流对象和文件关联
	char buf[256] = { 0 };
	ifstream  fin(fileName);
	if (!fin)
	{
		cout << "文件打开失败";
		return;
	}
	//fin >> buf;  // 只读了一个单词
	//cout << buf;
	while (fin >> buf)  // 读出了所有行， 但是空格没有了
	{
		cout << buf;
	}
	fin.close();

	cout << endl << endl;

	ifstream  fin2(fileName);
	if (!fin2)
	{
		cout << "文件打开失败";
		return;
	}
	char ch;

	while (fin2.get(ch))  // 可以读出所有内容,包括空格和回车
	{
		cout << ch;
	}
	fin2.close();	
}


class TestClass
{
public:
	TestClass()
	{
		age = 33;
		strcpy(name, "No name!");
	}
	TestClass(int age, const char * name)
	{
		this->age = age;
		strcpy(this->name, name);
	}
public:
	friend ostream& operator<<(ostream& out, TestClass& Tc);
private:
	int age;
	char name[30];
};
ostream& operator<<(ostream& out, TestClass& Tc)
{
	out << "age: " << Tc.age;
	out << "  name: " << Tc.name;
	out << endl;
	return out;
}
// 二进制文件读写
void binaryWriteReadFile(const char* _fileName)
{
	TestClass t1;
	TestClass t2(45, "张三");
	TestClass t3(34, "李四");

	ofstream  fout(_fileName, ios::binary);
	if (!fout)
	{
		cout << "文件打开失败";
		return;
	}
	fout.write((char*)&t1, sizeof(t1));
	fout.write((char*)&t2, sizeof(t2));
	fout.write((char*)&t3, sizeof(t3));
	// fout.write((char*)&t1, 3 * sizeof(TestClass));// 不行滴，debug 只读到一行无错误数据， release读到两行， 这种bug还是不写了
	fout.close();

	TestClass tmp;
	ifstream fin(_fileName, ios::binary);
	if (!fin)
	{
		cout << "文件打开失败";
		return;
	}
	fin.read((char*)&tmp, sizeof(TestClass));
	cout << tmp;
	fin.read((char*)&tmp, sizeof(TestClass));
	cout << tmp;
	fin.read((char*)&tmp, sizeof(TestClass));
	cout << tmp;
	fin.close();

}
int main() 
{
	int ret = 0;
	// writeReadFile("./test.txt");
	binaryWriteReadFile("./test.txt");

	cout << "Hello World!" << endl;
	system("pause");
	return ret;
}