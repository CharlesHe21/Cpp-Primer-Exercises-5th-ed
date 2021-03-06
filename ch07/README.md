[练习7.1](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_1.cpp)

>使用[2.6.1节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/README.md)练习定义的[Sales_data类](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/ex2_40.cpp)为1.6节（第21页）的交易处理程序编写一个新版本。

```cpp
#include<iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
    Sales_data total; //保存下一条交易记录的变量
    //读入第一条交易记录，并确保有数据可以处理
    if(total.input(cin)){
	Sales_data trans; //保存和的变量
	//读入并处理剩余交易记录
	while(trans.input(cin)){
	    //如果我们仍在处理相同的书
	    if(total.isbn() == trans.isbn())
		total.add(trans); //更新总销售额
	    else{
		//打印前一本书的结果
		total.print(cout);
		total = trans; //total现在表示下一本书的销售额
	    }
	}
	total.print(cout); //打印最后一本书的结果
    }else{
	//没有输入！警告读者
	std::cerr << "No data?!" << std::endl;
	return -1; //表示失败
    }
    return 0;
}
```

[练习7.2](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Sales_data.h)

>曾在[2.6.2节]((https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch02/README.md))的练习（第67页）中编写了一个Sales_data类，请向这个类添加combine和isbn成员。

```cpp
#include<iostream>
#include<string>
struct Sales_data {
	
    private:
	std::string bookNo;
	unsigned units_sold = 0;
	double price = 0.0;
	double revenue = 0.0;
	
    public:
	bool input(std::istream &in)
	{
	    in >> bookNo >>units_sold >>price;
	    if(!in) return false;
	    revenue = units_sold * price;
	    return true;
	}

	void add(Sales_data data)
	{
	    units_sold += data.units_sold;
	    revenue += data.revenue;
	}
		
	Sales_data& combine(const Sales_data &data)
	{
	    units_sold += data.units_sold;
	    revenue += data.revenue;
	    return *this;
	}

	void output(std::ostream &out)
	{
	    out << bookNo << " " << units_sold << " " << revenue << " " << price << std::endl;
	}

	void print(std::ostream &out)
	{
	    out << "Revenue of " << bookNo << " is " << revenue << std::endl;
	}
		
	std::string isbn() const
	{
	    return bookNo;
	}
};
```

[练习7.3](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_3.cpp)

>修改[7.1.1节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_1.cpp)（第229页）的交易处理程序，令其使用这些成员。

```cpp
#include<iostream>
#include "Sales_data.h"
using namespace std;
int main()
{
    Sales_data total; //保存下一条交易记录的变量
    //读入第一条交易记录，并确保有数据可以处理
    if(total.input(cin)){
	Sales_data trans; //保存和的变量
	//读入并处理剩余交易记录
	while(trans.input(cin)){
	    //如果我们仍在处理相同的书
	    if(total.isbn() == trans.isbn())
		total = total.combine(trans); //更新总销售额
	    else{
		//打印前一本书的结果
		total.print(cout);
		total = trans; //total现在表示下一本书的销售额
	    }
	}
	total.print(cout); //打印最后一本书的结果
    }else{
	//没有输入！警告读者
	std::cerr << "No data?!" << std::endl;
	return -1; //表示失败
    }
    return 0;
}
```

[练习7.4](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Person.h)

>编写一个名为Person的类，使其表示人员的姓名和住址。使用string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。

    见下

[练习7.5](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Person.h)

>在你的Person类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是const的呢？解释原因。

```cpp
#include<string>
using namespace std;

struct Person{

    private:
        string name;
	string address;
	
    public:
	string get_name() const
	{
	    return name;
	}
	string get_address() const
	{
	    return address;
	}
};
```

    读取姓名和地址的成员函数不需要修改对象的数据成员，因此应该是const的

[练习7.6](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Sales_data_ex_7_6.h)

>对于函数add、read和print，定义你自己的版本。

```cpp
#include<iostream>
#include<string>
using namespace std;
struct Sales_data {
	
    public:
	string bookNo;
	unsigned units_sold = 0;
	double price = 0.0;
	double revenue = 0.0;
		
	Sales_data& combine(const Sales_data &data)
	{
	    units_sold += data.units_sold;
	    revenue += data.revenue;
	    return *this;
	}
		
	string isbn() const
	{
	    return bookNo;
	}
		
	double avg_price() const
	{
	    if(units_sold)
		return revenue/units_sold;
	    else
		return 0;
	}
};

Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
    Sales_data sum = item1;
    return sum.combine(item2);
}

istream &read(istream &in, Sales_data &item)
{
    double price = 0.0;
    in >> item.bookNo >>item.units_sold >>item.price;
    item.revenue = item.units_sold * item.price;
    return in;
}

ostream &print(ostream &out, Sales_data &item)
{
    out<<"ISBN: "<<item.isbn()<<" sold out "<<item.units_sold<<" pieces, revenue is: "<<item.revenue<<", average price is: "
       <<item.avg_price();
    return out;
}
```

[练习7.7](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_7.cpp)

>使用这些新函数重写[7.1.2节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_3.cpp)（第233页）练习中的交易处理程序。

```cpp
#include<iostream>
#include "Sales_data_ex_7_6.h"
using namespace std;
int main()
{
    Sales_data total; //保存下一条交易记录的变量
    //读入第一条交易记录，并确保有数据可以处理
    if(read(cin,total)){
	Sales_data trans; //保存和的变量
	//读入并处理剩余交易记录
	while(read(cin,trans)){
	    //如果我们仍在处理相同的书
	    if(total.isbn() == trans.isbn())
		total = total.combine(trans); //更新总销售额
	    else{
		//打印前一本书的结果
		print(cout,total);
		total = trans; //total现在表示下一本书的销售额
	    }
	}
	print(cout,total); //打印最后一本书的结果
    }else{
	//没有输入！警告读者
	std::cerr << "No data?!" << std::endl;
	return -1; //表示失败
    }
    return 0;
}
```

[练习7.8](#)

>为什么read函数将其Sales_data参数定义成普通的引用，而print将其参数定义成常量引用？

    read函数要改变其参数的数据成员的值（输入），所以是普通引用
    print函数只需读取参数的数据成员而不需要改变它们，所以是常量引用

[练习7.9](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Person_ex7_9.cpp)

>对于[7.1.2节](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex7_4.cpp)（第233页）练习中的代码，添加读取和打印Person对象的操作。

```cpp
#include<iostream>
#include<string>
using namespace std;

struct Person{
    public:
        string name;
	string address;

	string get_name() const
	{
	    return name;
	}
	string get_address() const
	{
	    return address;
	}
};

istream &read(istream &in, Person &person)
{
    in>>person.name>>person.address;
    return in;
}

ostream &print(ostream &out, const Person &person)
{
    out<<person.name<<" "<<person.address;
    return out;
}
```

[练习7.10](#)

>在下面这条if语句中，条件部分的作用是什么？

```cpp
if (read(read(cin, data1), data2))
```

    首先输入data1，再用返回的cin输入data2，相当于cin>>data1>>data2

[练习7.11](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex_7_11.cpp)

>在你的[Sales_data类](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Sales_data_ex_7_11.h)中添加构造函数，然后编写一段程序令其用到每个构造函数。

    由于只接受一个istream作为参数的构造函数需要使用read函数，而read又以Sales_data作为参数，由于它们的声明关系，该构造函数需要先声明，再定义

```cpp
#include<iostream>
#include<string>
using namespace std;

struct Sales_data {

    Sales_data() = default;
    Sales_data(const string &s):bookNo(s){}
    Sales_data(const string &s, unsigned u, double p):
	        bookNo(s), units_sold(u), price(p), revenue(u*p){}
    Sales_data(istream &in);
		
    string bookNo;
    unsigned units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
		
    Sales_data& combine(const Sales_data &data)
    {
	units_sold += data.units_sold;
	revenue += data.revenue;
	return *this;
    }
		
    string isbn() const
    {
	return bookNo;
    }
		
    double avg_price() const
    {
	if(units_sold)
	    return revenue/units_sold;
	else
	    return 0;
    }
};

Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
    Sales_data sum = item1;
    return sum.combine(item2);
}

istream &read(istream &in, Sales_data &item)
{
    double price = 0.0;
    in >> item.bookNo >>item.units_sold >>item.price;
    item.revenue = item.units_sold * item.price;
    return in;
}

ostream &print(ostream &out, Sales_data &item)
{
    out<<"ISBN: "<<item.isbn()<<" sold out "<<item.units_sold<<" pieces, revenue is: "<<item.revenue<<", average price is: "   
       <<item.avg_price();
    return out;
}

Sales_data::Sales_data(istream &in)
{
    read(in, *this);
}
```

```cpp
#include<iostream>
#include "Sales_data_ex_7_11.h"
using namespace std;

int main()
{
    Sales_data s1;
    Sales_data s2("bookno1");
    Sales_data s3("bookno1", 2, 1.5);
    Sales_data s4(cin);
	
    print(cout,s1);
    cout<<endl;
    print(cout,s2);
    cout<<endl;
    print(cout,s3);
    cout<<endl;
    print(cout,s4);
    cout<<endl;
}
```

[练习7.12](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Sales_data_ex_7_12.h)

>把只接受一个istream作为参数的构造函数定义移到类的内部。

    没有友元，只能出此下策

```cpp
Sales_data(istream &in)
{
    double price = 0.0;
    in >> bookNo >>units_sold >>price;
    revenue = units_sold * price;
}
```

[练习7.13](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/ex_7_13.cpp)

>使用istream构造函数重写第229页的程序。

    需要注意，构造函数没有返回值

```cpp
#include<iostream>
#include "Sales_data_ex_7_12.h"
using namespace std;
int main()
{	

    if(cin){	
	Sales_data total(cin);
        while(cin){
	    Sales_data trans(cin);
            if(total.isbn() == trans.isbn())
		total = total.combine(trans);
	    else{
                print(cout,total);
		total = trans;
	    }
	}
	print(cout,total);
    }else{

	std::cerr << "No data?!" << std::endl;
	return -1;
    }
    return 0;
}
```

[练习7.14](#)

>编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。

    略

[练习7.15](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Person_ex7_15.cpp)

>为你的Person类添加正确的构造函数。

```cpp
#include<iostream>
#include<string>
using namespace std;

struct Person{
	    
	Person() = default;
	Person(const string n):name(n){}
	Person(const string n, const string a):name(n),address(a){}
	Person(istream&);
		
	string name;
	string address;

	string get_name() const
	{
	    return name;
	}
	string get_address() const
	{
	    return address;
	}
};

istream &read(istream &in, Person &person)
{
    in>>person.name>>person.address;
    return in;
}

ostream &print(ostream &out, const Person &person)
{
    out<<person.name<<" "<<person.address;
    return out;
}

Person::Person(istream &in)
{
    read(in, *this);
}
```

[练习7.16](#)

>在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在public说明符之后？什么样的成员应该定义在private说明符之后？

    没有
    类的接口使用public定义，只能被类的成员函数访问的成员使用private定义

[练习7.17](#)

>使用class和struct时有区别吗？如果有，是什么？

    有，唯一区别是默认的访问权限，class是private，struct是public

[练习7.18](#)

>封装有何含义？它有什么用处？

    封装实现了类的接口和实现的分离。封装后的类隐藏了它的实现细节，也就是说，类的用户只能使用接口而无法访问实现部分。

[练习7.19](#)

>在你的Person类中，你将把哪些成员声明成public的？哪些成员声明成private的？解释你这样做的原因。

    目前name和address成员都是public的，因为有read函数需要写入它们的值，如果只使用构造函数而不使用read函数，则name和address都应是private的

[练习7.20](#)

>友元在什么时候有用？请分别列举出使用友元的利弊。

友元在非类成员函数需要访问类的私有成员时使用
友元方便非类成员函数访问类的私有成员，但同时也破坏了封装

[练习7.21](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Sales_data_ex_7_21.h)

>修改你的Sales_data类使其隐藏实现的细节。你之前编写的关于Sales_data操作的程序应该继续使用，借助类的新定义重新编译该程序，确保其工作正常。

```cpp
#include<iostream>
#include<string>
using namespace std;

class Sales_data {
		
    friend istream &read(istream&, Sales_data&);

    Sales_data() = default;
    Sales_data(const string &s):bookNo(s){}
    Sales_data(const string &s, unsigned u, double p):
              bookNo(s), units_sold(u), price(p), revenue(u*p){}
			
    public:
	Sales_data(istream &in)
	{
	    double price = 0.0;
	    in >> bookNo >>units_sold >>price;
	    revenue = units_sold * price;
        }
		
	string bookNo;
	unsigned units_sold = 0;
	double price = 0.0;
	double revenue = 0.0;
		
	Sales_data& combine(const Sales_data &data)
	{
	    units_sold += data.units_sold;
	    revenue += data.revenue;
	    return *this;
	}
		
	string isbn() const
	{
	    return bookNo;
	}
		
	double avg_price() const
	{
	    if(units_sold)
		return revenue/units_sold;
	    else
		return 0;
	}
};

Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
    Sales_data sum = item1;
    return sum.combine(item2);
}

istream &read(istream &in, Sales_data &item)
{
    double price = 0.0;
    in >> item.bookNo >>item.units_sold >>item.price;
    item.revenue = item.units_sold * item.price;
    return in;
}

ostream &print(ostream &out, Sales_data &item)
{
    out<<"ISBN: "<<item.isbn()<<" sold out "<<item.units_sold<<" pieces, revenue is: "<<item.revenue<<", average price is: "   
       <<item.avg_price();
    return out;
}
```

[练习7.22](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Person_ex_7_22.h)

>修改你的Person类使其隐藏实现的细节。

```cpp
#include<iostream>
#include<string>
using namespace std;

class Person{
	   
    friend istream &read(istream&, Person&);
		
    string name;
    string address;
		
    public:
	Person() = default;
	Person(const string n):name(n){}
	Person(const string n, const string a):name(n),address(a){}
	Person(istream&)
	{
	    read(in, *this);
	}
	    
	string get_name() const
	{
	    return name;
	}
	string get_address() const
	{
	    return address;
	}
};

istream &read(istream &in, Person &person)
{
    in>>person.name>>person.address;
    return in;
}

ostream &print(ostream &out, const Person &person)
{
    out<<person.name<<" "<<person.address;
    return out;
}
```

[练习7.23](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Screen.h)

>编写你自己的Screen类。

    见下

[练习7.24](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Screen.h)

>给你的Screen类添加三个构造函数：一个默认构造函数；另一个构造函数接受宽和高的值，然后将contents初始化成给定数量的空白；第三个构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容。

```cpp
#include<string>
using namespace std;

class Screen
{
    public:
        typedef string::size_type pos;
	Screen()=default;
	Screen(pos h, pos w):height(h),width(w),contents(h*w, ' '){}
	Screen(pos h, pos w, char c):height(h),width(w),contents(h*w, c){}
	char get() const
	{
	    return contents[cursor];
	}
	Screen &move(pos r, pos c)
	{
	    cursor = r*width + c;
	    return *this;
	}
		
    private:
        pos height=0, width=0, cursor=0;
	string contents;	
};
```

[练习7.25](#)

>Screen能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能，为什么？

    可以，Screen的数据成员都是可以使用默认版本的拷贝和赋值操作的

[练习7.26](#)

>将Sales_data::avg_price定义成内联函数。

```cpp
inline double avg_price() const
{
    if(units_sold)
	return revenue/units_sold;
    else
	return 0;
}
```

[练习7.27](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/blob/master/ch07/Screen_ex_27.h)

>给你自己的Screen类添加move、set和display函数，通过执行下面的代码检验你的类是否正确。

```cpp
Screen myScreen(5, 5, 'X');
myScreen.move(4, 0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```

```cpp
#include<iostream>
#include<string>
using namespace std;

class Screen
{
    public:
        typedef string::size_type pos;
	Screen()=default;
	Screen(pos h, pos w):height(h),width(w),contents(h*w, ' '){}
	Screen(pos h, pos w, char c):height(h),width(w),contents(h*w, c){}
	char get() const
	{
	    return contents[cursor];
	}
	Screen &move(pos r, pos c)
	{
	    cursor = r*width + c;
	    return *this;
	}
		
	inline Screen &set(char c)
	{
	    contents[cursor] = c;
	    return *this;
	}
	inline Screen &set(pos r, pos c, char ch)
	{
	    contents[r*width+c] = ch;
	    return *this;
	}
		
	Screen &display(ostream &os)
	{
	    do_display(os);
	    return *this;
	}
		
	const Screen &display(ostream &os) const
	{
	    do_display(os);
	    return *this;
	}
		
		
    private:
	pos height=0, width=0, cursor=0;
	string contents;
	void do_display(ostream &os) const
	{
	    os<<contents;
	}
	
};
```

[练习7.28](#)

>如果move、set和display函数的返回类型不是Screen&而是Screen，则在上一个练习中将会发生什么情况？

    两次display的内容不同，因为move、set和display返回的都是当前对象的拷贝，而不是当前对象的引用

[练习7.29](#)

>修改你的Screen类，令move、set和display函数返回Screen并检查程序的运行结果，在上一个练习中你的推测正确吗？

    Yes

[练习7.30](#)

>通过this指针使用成员的做法虽然合法，但是有点多余。讨论显式地使用指针访问成员的优缺点。

    优点：程序可读性强
    缺点：多余

[练习7.31](#)

>定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为X的对象。

```cpp
class X
{
    Y *p;
};
class Y
{
    X x;
};
```

[练习7.32](https://github.com/CharlesHe21/Cpp-Primer-Exercises-5th-ed/edit/master/ch07/ex7_32.h)

>定义你自己的Screen和Window_mgr，其中clear是Window_mgr的成员，是Screen的友元。

```cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Window_mgr
{
    public:
        using ScreenIndex = vector<Screen>::size_type;
	void clear(ScreenIndex);
    private:
	vector<Screen> screens{Screen(24, 80, ' ')};
};

class Screen
{
    public:
	friend void Window_mgr::clear(ScreenIndex);
	typedef string::size_type pos;
	Screen()=default;
	Screen(pos h, pos w):height(h),width(w),contents(h*w, ' '){}
	Screen(pos h, pos w, char c):height(h),width(w),contents(h*w, c){}
	char get() const
	{
	    return contents[cursor];
	}
	Screen &move(pos r, pos c)
	{
	    cursor = r*width + c;
	    return *this;
	}
		
	inline Screen &set(char c)
	{
	    contents[cursor] = c;
	    return *this;
	}
	inline Screen &set(pos r, pos c, char ch)
	{
	    contents[r*width+c] = ch;
	    return *this;
	}
		
	Screen &display(ostream &os)
	{
	    do_display(os);
	    return *this;
	}
		
	const Screen &display(ostream &os) const
	{
	    do_display(os);
	    return *this;
	}
		
		
    private:
	pos height=0, width=0, cursor=0;
	string contents;
	void do_display(ostream &os) const
	{
	    os<<contents;
	}
	
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = Screens[i];
    s.contents = string(s.height * s.width, ' ');
}
```

[练习7.33](#)

>如果我们给Screen添加一个如下所示的size成员将会发生什么情况？如果出现了问题，请尝试修改它。

```diff
+ Screen::pos Screen::size() const
- pos Screen::size() const
{
    return height * width;
}
```

    pos是Screen内定义的别名，在类外使用需要指明它是哪个类的成员

[练习7.34](#)

>如果我们把第256页Screen类的pos的typedef放在类的最后一行会发生什么情况？

    显示pos未定义

[练习7.35](#)

>解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。如果代码存在错误，尝试修改它。

```diff
typedef string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type); // typedef double Type
    Type initVal(); // typedef double Type
private:
    int val;
};
+ Exercise::Type Exercise::setVal(Type parm) {
- Type Exercise::setVal(Type parm) { // typedef string Type & typedef double Type
    val = parm + initVal();
    return val;
}
```

[练习7.36](#)

>下面的初始值是错误的，请找出问题所在并尝试修改它。

```diff
struct X {
+ 初始化顺序和定义顺序相同
+   X (int i, int j): base(i), rem(i % j) {}
-   X (int i, int j): base(i), rem(base % j) {}
    int rem, base;
};
```

[练习7.37](#)

>使用本节提供的Sales_data类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有数据成员的值。

```cpp
Sales_data first_item(cin); // 第3，数据成员值由输入决定
int main() {
    Sales_data next; // 第1，bookNo为""
    Sales_data last("9-999-99999-9"); //第 1，bookNo为"9-999-99999-9"
}
```

[练习7.38](#)

>有些情况下我们希望提供cin作为接受istream&参数的构造函数的默认实参，请声明这样的构造函数。

```cpp
//以Sales_data构造函数为例
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```

[练习7.39](#)

>如果接受string的构造函数和接受istream&的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？

    不合法，造成构造函数的二义性

[练习7.40](#)

>从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。  
(a)Book  
(b)Date  
(c)Employee  
(d)Vehicle  
(e)Object  
(f)Tree  

```cpp
class Book {
private:
    string bookNo; // ISBN号
    vector<string> author; // 作者（可能有多个）
    string publisher; // 出版社
    int version; // 版本号
    Date publishDate; // 出版时间
    double price; // 定价
    int pageSize; // 页数
    //...
public:
    Book(std::istream &is = std::cin) { read(is, *this); }
    Book(string b, vector<string> a, string p, int v, Date pd, double pr, int ps )
        : bookNo(b), author(a), publisher(p), version(v), publishDate(pd), price(pr), pageSize(ps) {}
    Book() {}
    //...
};
```

[练习7.41](#)

>使用委托构造函数重新编写你的Sales_data类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建Sales_data对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。

    略

[练习7.42](#)

>对于你在利纳希7.40（参见7.5.1节，第261页）中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。

```cpp
Book(): Book("", {""}, "", 1, "", 0, 0) {}
```

[练习7.43](#)

>假定有一个名为NoDefault的类，它有一个接受int的构造函数，但是没有默认构造函数。定义类C，C有一个NoDefault类型的成员，定义C的默认构造函数。

```cpp
//假设这个NoDefault类型的成员是b_member
C(int i=0):b_member(i)
{
    //...
}
```

[练习7.44](#)

>下面这条声明合法吗？如果不，为什么？

```cpp
vector<NoDefault> vec(10);
```

    不合法，NoDefault没有默认构造函数，程序默认初始化vector

[练习7.45](#)

>如果上一个练习中定义的vector的元素类型是C，则声明合法吗？为什么？

    合法，C有默认的构造函数

[练习7.46](#)

>下面哪些论断是不正确的？为什么？  
(a)一个类必须至少提供一个构造函数。  
(b)默认构造函数是参数列表为空的构造函数。  
(c)如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。  
(d)如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。

    (a)错，可以没有构造函数，此时编译器会生成默认构造函数
    (b)错，参数列表可以不为空但是有默认实参
    (c)错，不提供默认构造函数在对象被默认初始化或值初始化时会出现错误
    (d)错，编译器不会自动生成默认构造函数

[练习7.47](#)
