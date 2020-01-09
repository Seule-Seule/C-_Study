
// register关键字的扩展
// C++ 可以取地址
// C++ 自动对使用频繁变量优化为寄存器变量
/*
{//C 语言
	register int a = 0;
	printf("%d",&a);    // 对寄存器变量取地址，C语言报错
}
*/
/*
{//C++ 语言
	register int a = 0;
	printf("%d",&a);    // 对寄存器变量取地址，C++ 语言不会报错
}
*/