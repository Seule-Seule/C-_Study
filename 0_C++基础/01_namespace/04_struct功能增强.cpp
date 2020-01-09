// struct 关键字增强

/*
//C 语言
struct node
{
	int q;
	char b;
};

void main()
{
	node n1; // C语言会报错，没有说明是一个集合
}
*/
//C++ 语言
struct node
{
	int q;
	char b;
};

// C++对struct的操作和对class的一样,也有区别？？不知道是啥
class c1
{
public:
protected:
private:
};
struct node2
{
public:
	int q;
	char b;
};

void main_41()
{
	node n1; // C++ 语言不会报错，是一个新类型
}
