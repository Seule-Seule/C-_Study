# C++基础

> 关于C++进阶部分的文件目录


## 目录

- [函数模板](#函数模板)
- [类型转换](#类型转换)
- [异常处理机制](#异常处理机制)
- [C++的输入输出流](#C++的输入输出流)
- [stl实用技术](#stl实用技术)

## 函数模板

- [函数模板基本语法](00_函数模板/00_函数模板基本语法.cpp)
  - 模板函数定义声明`template <typename T>`
  - 显示类型转换`Swap<int>(a, b);`
  - 隐式类型转换`int a; int b;`  `Swap(a, b);`
  - 函数模板本质:类型参数化

- [函数模板做函数参数](00_函数模板/01_函数模板做函数参数.cpp)
  - `template <typename T, typename T2>`  `void Sort(T* array, T2 size)`
  - `Sort<int, int>(array, size);`
  
- [模板函数遇上函数重载](00_函数模板/02_模板函数遇上函数重载.cpp)
  - 模板函数有极其严格的类型检查,不允许自动类型转换
  - 普通函数类型检查相对宽松，可以进行隐式类型转换
  - 模板函数可以像普通函数一样被重载
  - C++编译器优先考虑普通函数
  - 如果模板函数可以产生一个更好的匹配，则选择模板函数
  - 可以通过空模板实参列表的语法限制编译器选择模板函数匹配

- [模板函数本质剖析](00_函数模板/03_模板函数本质剖析.cpp)
  - 函数模板本质剖析
  - 编译器并不是把模板函数编译成能处理任何类的函数
  - 编译器从模板函数通过具体类型产生不同函数
  - 编译器会对模板函数进行两次编译！！！
    - 在声明的地方对代码本身进行编译，在调用的地方对参数替换后的代码进行编译

- [类模板基本语法](00_函数模板/04_类模板基本语法.cpp)
  - 类模板声明
    - `template <typename Type>`
    - `class Test`
  - 类模板定义: 类模板是抽象的  需要具体化
	- `Test <int> a1(10), a2(20), a3(30);  // 类模板使用 必须初始化参数`
  - 类模板做函数参数 也需要具体化
    - `void useTest(Test <int> a)`

- [模板类派生普通类和模板类](00_函数模板/05_模板类派生普通类.cpp)
  - 需要模板类具体化，子类必须知道为父类分配多大内存空间
  - `class TestB : public Test<int>`

- 类模板的应用-复数类的实现
  - [模板类的方法都写在类的内部](00_函数模板/06_复数类_所有类的方法都在写类的内部.cpp)
  - [模板函数方法写在类的外部同一个cpp文件中](00_函数模板/06_复数类_模板类方法的外部实现_一个cpp中.cpp)
    - 友元函数重载模板类操作符的解决方法
    - 模板类友元函数滥用编译出错解决方法
  - [模板函数方法写在类的外部_h_hpp文件中](00_函数模板/07_模板类的外部实现_h_hpp.cpp)
    - 主调文件中需要包含cpp文件，改名hpp
    - 尽量写到一个文件中

- [类模板中的static关键字](00_函数模板/08_static关键字遇上模板类.cpp)
  - 模板类的静态成员变量每个类都拥有自己的静态成员变量(模板类的编译机制吻合)

- [MyVector实现](00_函数模板/09_MyVector_Test.cpp)
  - 初步实现
  - 存储复杂数据类型(类、类(含有指针变量)、类的指针)

## 类型转换

- [C++与C中的类型转换](01_类型转换/00_C++与C语言中的类型转换.cpp)
  - C 语言中的类型转换：（强制类型转换）
	  - `TYPE b = (TYPE) a;`
  - C++ 语言中的类型转换：（4种、应对不同场合）
	  - 1 `static_cast`
		  - 静态类型转换所有C语言支持都不会报错， 不支持的会报错
	  - 2 `reinterpret_cast`
		  - 重新解释类型
	  - 3 `dynamic_cast`
		  - 动态类型转换， 如父类和子类之间的动态类型转换
	  - 4 `const_cast`
		  - 去 const 属性

## 异常处理机制

- [异常基本语法](02_异常处理机制/00_异常处理的基本语法.cpp)
  - 异常的基本语法
  - 异常跨函数
  - 接收异常之后可以不处理， 继续向上抛出
  - 异常的cacht严格遵守类型匹配
  - 异常的处理机制使得错误的引发和处理不必在同一个函数中进行， 实现软件分层

- [栈解旋unwimding](02_异常处理机制/01_栈解旋unwimding.cpp)
  - 从进入try语句到发生异常的语句之前所有栈变量都将被析构，析构顺序与构造顺序相反
  - 异常接口声明
    - 写了， 只能抛出列表异常`void voidTest4() throw(int , char , char *)`
    - 不写，可以抛出任何类型异常`void voidTest5() `
    - 异常列表为空， 不抛出任何类型异常`void voidTest5() throw()`

- [异常变量的生命周期](02_异常处理机制/02_异常变量的生命周期.cpp)
  - C++异常处理机制 int 、const char * 
  - C++异常处理机制 类对象异常
    - `throw ErrorTest();`捕捉变量|引用 注意特殊写法, 创建匿名对象
      - 1 捕捉变量异常变量时利用匿名对象拷贝构造异常变量
      - 2 捕捉引用异常变量会使用 throw 的匿名对象
    - `throw &(ErrorTest());`  捕捉指针异常变量  返回时析构，返回野指针 ERROR
		- `throw new ErrorTest; `  捕捉指针异常变量  放到堆上
      - 3 为避免野指针， 异常变量放在堆上
      - `delete e; `  释放空间， 避免内存泄漏
    - 指针异常变量的捕捉与变量或者引用可以同时存在， 引用个变量不能同时存在
    - 结论：类对象使用引用能避免麻烦，提高效率

- [异常的层次结构（异常类继承）](02_异常处理机制/03_异常的层次结构_继承中的异常类.cpp)

- [标准异常库](02_异常处理机制/04_C++exception类.cpp)
  - [C++异常类继承图](02_异常处理机制/04_C++异常类继承图.png)
  - [异常类具体信息](02_异常处理机制/04_异常类具体信息.md)
  - 标准异常库的使用和继承

## C++的输入输出流
- [输入输出流结构](03_C++输入输出流/流类库结构.md)

- [标准io输入cin](03_C++输入输出流/00_cinAPI.cpp)
  - `cin.get()`获取一个字符
  - `cin.get(一个参数)`获取一个字符到参数变量
  - `cin.get(三个参数)`获取一个串，遇到空格停止
  - `cin.getline(buf2, 256);`获取一个串，可以接受空格
  - `cin.ignore(2); `忽略字符
  - `Test = cin.peek();`查看缓冲区是否有数据，如果有则读出数据， 没有返回0

- [标准输出cout](03_C++输入输出流/01_coutAPI.cpp)
  - 单个字符输出 `cout.put('a').put('b');  `
	- 刷新缓存 `cout.flush();`   
  - 输出二进制流 

  ```c++
    cout.write(buf, strlen(buf)) << endl;
    cout.write(buf, strlen(buf) - 4) << endl;
    cout.write(buf, strlen(buf) + 8) << endl;   // 注意越界
  ```
  - 控制输出长度 `cout.width(30); `
	- 填充字符 `cout.fill('&');`
  - 输入输出流的控制符

    |控制符|	作 用|
    |:--:|:--|
    |dec|	设置数值的基数为10|
    |hex|	设置数值的基数为16|
    |oct|	设置数值的基数为8|
    |setfill(c)|	设置填充字符c，c可以是字符常量或字符变量
    |setprecision(n)|	|设置浮点数的精度为n位。在以一般十进制小数形式输出时，n代表有效数字。在以fixed(固定小数位数)形式和 scientific(指数)形式输出时，n为小数位数|
    |setw(n)|	设置字段宽度为n位|
    |setiosflags( ios::fixed)|	设置浮点数以固定的小数位数显示|
    |setiosftags( ios::scientific)|	设置浮点数以科学记数法(即指数形式)显示|
    |setiosflags( ios::left)|	输出数据左对齐|
    |setiosflags( ios::right)|	输出数据右对齐|
    |setiosflags( ios::skipws)|	忽略前导的空格|
    |setiosflags( ios::uppercase)|	数据以十六进制形式输出时字母以大写表示|
    |setiosflags( ios::lowercase)|	数据以十六进制形式输出时宇母以小写表示|
    |setiosflags(ios::showpos)|	输出正数时给出“+”号|

- [文件流fstream](03_C++输入输出流/02_fstreamAPI.cpp)
  - 普通文件读写
    - 建立一个输出流对象和文件关联 `ofstream  fout(fileName);`
      - 判断文件是否打开成功` if (!fout){...; return ;}`
      - 写文件 `fout << "test line one. " << endl;`
      - 关闭文件 `fout.close();`
    - 建立一个输入流对象和文件关联 `ifstream  fin(fileName);`
      - `fin >> buf;  // 只读了一个单词`
      
      ```c++
      char buf[256] = { 0 };
      while (fin >> buf)  // 读出了所有行， 但是空格和回车没有了
	    {
		      cout << buf;
	    }
      char ch;
      while (fin2.get(ch))  // 可以读出所有内容,包括空格和回车
      {
        cout << ch;
      }
      ```

  - 二进制文件读写
    - 建立一个输出流对象和二进制文件关联 `ofstream  fout(_fileName, ios::binary);`
    - 写入二进制数据 `fout.write((char*)&t1, sizeof(t1));`
    - 建立一个输入流对象和二进制文件关联 `ifstream fin(_fileName, ios::binary);`
    - 读出二进制数据 `fin.read((char*)&tmp, sizeof(TestClass));`

## stl实用技术

- [stl容器算法迭代器基本概念](04_stl基础/00_stl容器算法迭代器基本概念.cpp)
  - 容器 把数据copy到容器中, 实现了 数据结构 和 算法 的有效分离
  - 迭代器  相当于一个指针
  - 算法和容器无缝连接 

- [string基础](04_stl基础/01_String类基础.cpp)
  - string 初始化
	  - `string s1 = "aaaaaaaaa";  - `
	  - `string s2("bbbbbbbb");  - `
	  - `string s3 = s2; // copy 构造  - `
	  - `string s4(10, 'c');  - `
  - string 遍历
    - 1 数组方式 s[i] 
    - 2 迭代器方式 `string::iterator it = s.begin(); it != s.end(); it++`
	  - 3 at 方式 s.at(i) // 与直接使用[]相比，at 越界抛出异常
  - 字符指针和 char * 之间转换
    - char * ==> string: `string s1 = "cscscscs";`
    - string ==> char *: `char* p = const_cast<char*>(s1.c_str());`
    - string copy到buf : `s1.copy(buf, 5);  // 只copy 内存数据, 不添加 '\0' 构成从风格字符串手动添加或者buf初始化为0`
  - 字符串连接
    - 使用+ `s1 += s2;`
    - 使用append() `s1.append(s2);`
  - string 的查找和替换
    - 查找 `index = s.find("ilu", 0);  // 从位置0查找字符串`
    - 替换 `s.replace(index, 3, "ILU");`
  - string 的插入和删除
    - 从index位置删除n个数据 `s.erase(index, n);`
	  - 在index位置插入n个Z字符`s.insert(index, n, 'Z');`
  - string transform算法
    - 转大写：`transform(s.begin(), s.end(), s.begin(), toupper); // toupper位置参数可以是 1函数入口地址 2函数对象 3预定义函数对象`
    - 转小写：`transform(s.begin(), s.end(), s.begin(), tolower);`

- [vector单端数组基础](04_stl基础/02_vector基础.cpp)
  - 尾部插入    ` v1.push_back(i); `
  - 获取头部元素 ` v1.front() << endl;`
  - 获取尾部元素 ` v1.back() << endl;  ` 
  - 删除尾部元素 ` v1.pop_back(); `
  - vector遍历
    - 方括号      `vInt[i] `
    - at访问元素 ` vInt.at(i) // 与直接使用[]相比，at 越界抛出异常`
  - vector初始化
    - 无参构造函数	`vector <int > v1;` 
    - copy 构造函数`vector<int> v2 = v1; `
    - 带参构造函数 从v1头到v1尾-2赋值给v3 `vector<int> v3(v1.begin(), v1.end() - 2);`
    - 带参构造函数 v4尾部插入4个5 `vector<int> v4(4, 5);`
  - 迭代器
    - 1 正逆序指针值
      - 正序时， begin()指向首元素，end()指向尾元素的后一个地址
      - 逆序时， rbegin()指向为元素，rend()指向首元素的前一个地址
    - 2 迭代器分类
      - `using iterator               = _Vector_iterator<_Scary_val>; `
      - `using const_iterator         = _Vector_const_iterator<_Scary_val>;  `
      - `using reverse_iterator       = _STD reverse_iterator<iterator>;`
      -` using const_reverse_iterator = _STD reverse_iterator<const_iterator>;`
  - vector 插入删除操作
    - 指定序列删除  删除前两个元素 `v1.erase(v1.begin(), v1.begin() + 2);`
    - 指定位置删除  删除第三个元素 `v1.erase(v1.begin() + 2);`
	  - 指定元素删除  for循环if判断实现
    - 插入 头插22 尾插23 `v1.insert(v1.begin(), 22);v1.insert(v1.end(), 23);`

- [deque双端数组基础](04_stl基础/03_deque容器基础.cpp)
  - 尾部添加 `d1.push_back(0);`
  - 首部添加 `d1.push_front(-1);`
	- 首部元素 `d1.front();`
	- 尾部元素 `d1.back();`
	- 尾部弹出 `d1.pop_back();`
	- 首部弹出 `d1.pop_front();`
  - 查找元素0的位置
	  - `deque<int>::iterator it = find(d1.begin(),d1.end(), 0);`
	  - `cout << "元素 0 下标为 : " << distance(d1.begin(), it) << endl;`
	  - distance 求偏移 

- [stack栈容器](04_stl基础/04_stack栈模型.cpp)
  - 入栈 `s.push(0); `
  - 出栈 `s.pop();`
  - 获取栈顶元素` s.top();`

- [queue队列模型](04_stl基础/05_queue队列模型.cpp)
  - 出入队列 `q.push(x); q.pop();`
  - 队头元素 `q.front()`
  - 队列长度 `q.size()`
  - 队列判空 `q.empty()`

- [list双向链表模型](04_stl基础/06_list双向链表.cpp)
  - 尾部添加 `d1.push_back(0);`
  - 首部添加 `d1.push_front(-1);`
	- 首部元素 `d1.front();`
	- 尾部元素 `d1.back();`
	- 尾部弹出 `d1.pop_back();`
	- 首部弹出 `d1.pop_front();`
  - 插入 `l.insert(itInsert, 50);`
    - list下标从0开始
    - list插入时, it位置插入元素，剩余元素下标加1
  - 删除 
    - 1 erase([begin, end))  // [0, 3) 删除时区间左闭右开， 即左删右不删
    - 2 erase(pos)  // 删除pos位置元素， 返回下一个数据位置
    - 3 remove(elem) // 删除list所有数据为elem的项
    - 4 clear()  // 删除所有元素
  
- [priority_queue优先级队列](04_stl基础/07_priority_queue优先级队列.cpp)
  - `#include <queue>`
  - 优先级队列 默认最大值优先 `priority_queue<int> p1;`  
  - 最大值优先的优先级队列完整定义 `priority_queue < int  , vector<int>, less<int >> p2; `
	- 最小值优先的优先级队列定义 `priority_queue< int, vector<int>, greater<int> > p3;  `

- [set集合模型](04_stl基础/08_set集合模型.cpp)
  - 集合模型 元素确定（唯一）  自动排序（默认从大到小） 不能位置操作 红黑树 平衡二叉树
  - 添加 `set1.insert(tmp);`
  - 遍历, 使用迭代器
  - 删除 `set1.erase(delete_tmp);`
  - 定义
    - 默认 从小到大 `set<int> set1;`
	  - 默认定义的完整定义 `set<int, less<int>> set2;`
	  -  从大到小排序 `set<int, greater<int>> set3;`
  - set 对复杂数据类型的排序 仿函数
    - 仿函数的定义 `bool operator() (const People& left, const People& right) const`
    - 重复插入问题 查看函数返回值以确定是否插入成功 （set排序关键字相同时，插入失败）
    - `pair<set<People, FuncSetPeople>::iterator, bool> pair_p4 = set1.insert(p4);`
  - set查找问题
    - 返回元素elem的迭代器的位置 `set<int>::iterator it0 = set1.find(elem); `
	  - 返回元素elem的个数 1 or 0 `int number = set1.count(elem);`
	  - 返回第一个大于等于元素elem的迭代器的位置 `set<int>::iterator it1 = set1.lower_bound(elem);`
	  - 返回第一个大于元素elem的迭代器的位置 `set<int>::iterator it2 = set1.upper_bound(elem);`
	  - 删除元素 5 `set1.erase(5);`   
	  - 返回<lower_bound, upper_bound> `pair<set<int>::iterator, set<int>::iterator> pair_set1 = set1.equal_range(5);`

- [multiset集合模型](04_stl基础/09_multiset集合模型.cpp)
  - 元素不唯一的set模型

- [map键值对集合模型](04_stl基础/10_map键值对集合模型.cpp)
  - 插入操作
    - 方法一到三，返回 `pair<iterator, bool>` 类型 
    - 方法四不论值存在与否都插入成功，且后一个值覆盖前一个值
    - 方法一 `m1.insert(pair<int, string>(1, "01"));`
	  - 方法二 `m1.insert(make_pair(3, "03"));`
	  - 方法三 `m1.insert(map<int, string>::value_type(5, "05"));`
	  - 方法四 `m1[7] = "07";`
  - 查找
    - 方法一 `_NODISCARD iterator find(const key_type& _Keyval) `
      - `if (iterator != m1.end())` 时查找成功
    - 方法二 `_NODISCARD pair<iterator, iterator> equal_range(const key_type & _Keyval)`
	    - `pari.first = lower_bound >= elem ; pari.second = upper_bound > elem`
- [容器共性](04_stl基础/12_容器的值(value)语意.cpp)
  - 值语意
    - 要确保装入容器的元素可以被拷贝
    - 重写 拷贝构造函数
    - 重载 =操作符
    - ERROR:没有可用的复制构造函数或复制构造函数声明为“explicit”  解决方法： 形参前加上 const

- [各个容器的使用时间和特点](#)
  
  |--|vector|deque|list|set|multiset|map|multimap|
  |:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
  |典型内存结构|单端数组|双端数组|双向链表|二叉树|二叉树|二叉树|二叉树|
  |可随机存取|是|是|否|否|否|对key而言是|否|
  |元素搜寻速度|慢|慢|非常慢|快|快|对key而言快|对key而言快|
  |快速安插移除|尾端|头尾两端|任何位置|--|--|--|--|
