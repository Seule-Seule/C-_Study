# C++基础

> 关于C++进阶部分的文件目录


## 目录

- [函数模板](#函数模板)

## 函数模板

- [函数模板基本语法](00_函数模板/00_函数模板基本语法.cpp)
  - 模板函数定义声明`template <typename T>`
  - 显示类型转换`Swap<int>(a, b);`
  - 隐式类型转换`int a; int b;`  `Swap(a, b);`
  - 函数模板本质:类型参数化

- [函数模板做函数参数](00_函数模板/01_函数模板做函数参数.cpp)
  - `template <typename T, typename T2>`  `void Sort(T* array, T2 size)`
  - `Sort<int, int>(array, size);`
  