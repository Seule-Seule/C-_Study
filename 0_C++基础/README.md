# C++基础

> 关于C++基础部分的文件目录


## 目录

- [HelloWorld](#HelloWorld)
- [C++对C的扩展](#C++对C的扩展)
- [C和C++中的const](#C和C++中的const)
- [引用](#引用)

## HelloWorld

- [C++ HelloWold 代码。](00_Helloword/00_Hello.cpp)
  - （有句话说的好，从HelloWorld到放弃）

## C++对C的扩展

- [命名空间和iostream](01_namespace/00_namespace.cpp)
- [“实用性”增强](01_namespace/01_C++对C实用性增强.cpp)
  - C中定义必须在执行语句前，C++可以在任何位置
- [register关键字加强](01_namespace/02_register关键字的扩展.cpp)
  - C中不能对register取地址，C不对语句进行优化，C++可以对register取地址，且对语句做优化以加快执行速度
- [变量检测增强](01_namespace/03_变量检测增强.cpp)
  - C可以定义两个同名变量不报错，C++会报错
- [struct功能增强](01_namespace/04_struct功能增强.cpp)
  - C语言中认为struct定义了一组变量的集合，C++认为struct定义了一个性类型。
  - C++中对struct和class进行的操作是一样的,也有区别
- [变量和函数类型检测增强](01_namespace/05_变量_函数类型检查增强.cpp)
  - c++中函数必须有返回值类型，C语言可以没有，会有默认值‘
  - C++函数参数必须有类型，C语言可以没有。
- [新增bool类型](01_namespace/06_新增bool类型.cpp)
- [三目运算符](01_namespace/07_三目运算符.cpp)
  - C语言中表达式不能直接做左值，C++中可以

## C和C++中的const

- [C和C++中对const的实现](02_C语言和C++中的const/00_C和C++中const的实现.cpp)
  - C语言中const可以通过指针修改，C++中不能修改
  - C语言只是增加了一个不能修改的属性
  - C++放在了符号表中，不能以任何方式修改
- [C++中const和#define的异同](02_C语言和C++中的const/00_C和C++中const的实现.cpp)
  - 相同点
    - 可以用const替代#define使用
  - 不同点
    - const 由编译器提供处理，有变量检查和作用域
    - #define 由预处理器处理，只实现文本处理功能

## 引用
- [引用基础知识](03_引用/00_引用基础知识.cpp)
  - 已定义变量的别名
  - 语法：  TYPE& name = var;
  - 普通引用必须初始化，引用做函数参数不用初始化
  - 复杂类型的引用举例(struct)
  - C++中引用代替zhizhen？部分场合吧，引用可读性好
- [引用的本质](03_引用/01_引用的本质.cpp)
  - 引用本质： TYPE * cosnt var; // 必须初始化且占用一个指针的内存空间
  - 引用就是间接赋值的1-23模型
  - 引用使用时不必关注本质，分析语法现象时才考虑其常量指针的本质


