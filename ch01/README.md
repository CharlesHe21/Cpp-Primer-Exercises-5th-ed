[# 练习1.1](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_1.cpp)

>查阅你使用的编译器的文档，确定它所使用的文件命名约定。编译并运行第2页的main程序。

```
int main()
{
    return 0;
}
```

[# 练习1.2](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_2.cpp)

>改写程序，让它返回-1。返回值-1通常被当作程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。

```
int main()
{
    return -1;
}
```

[# 练习1.3](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_3.cpp)

>编写程序，在标准输出上打印Hello, World。

```
#include<iostream>
int main()
{
    std::cout<<"Hello, World"<<std::endl;
    return 0;
}
```

[# 练习1.4](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_4.cpp)

>我们的程序使用加法运算符+来将两个数相加。编写程序使用乘法运算符\*，来打印两个数的积。

```
#include<iostream>
int main()
{
    int v1,v2;
    std::cin>>v1>>v2;
    std::cout<<"The product of "<<v1<<" and "<<v2<<" is "<<v1*v2<<std::endl;
    return 0;
}
```

[# 练习1.5](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch01/ex1_5.cpp)

>我们将所有输出操作