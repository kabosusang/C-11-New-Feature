#include <iostream>

using namespace std;

//也可以用constexpr修饰函数 要求返回值必须是常量

// error，不是常量表达式函数
constexpr void func1()
{
    int a = 100;
    cout << "a: " << a << endl;
}

// error，不是常量表达式函数

constexpr int func2()
{
    const int a = 100;
    return a; //是变量不是常量
} 
//整个函数的函数体中，不能出现非常量表达式之外的语句（using 指令、typedef 语句以及 static_assert 断言、return 语句除外）。
// error
constexpr int func1()
{
    constexpr int a = 100;
    constexpr int b = 10;
    for (int i = 0; i < b; ++i)
    {
        cout << "i: " << i << endl;
    }
    return a + b;
}

// ok
constexpr int func2()
{
    using mytype = int; //using 定义类型
    constexpr mytype a = 100;
    constexpr mytype b = 10;
    constexpr mytype c = a * b;
    return c - (a + b);
}
// /C++11 语法中，constexpr 可以修饰函数模板，但由于模板中类型的不确定性
//因此函数模板实例化后的模板函数是否符合常量表达式函数的要求也是不确定的。如果 constexpr 修饰的模板函数实例化结果不满足常量表达式函数的要求，则 constexpr 会被自动忽略，即该函数就等同于一个普通函数。

struct Person {
    const char* name;
    int age;
};

// 定义函数模板
template<typename T>
constexpr T dispaly(T t)  //有问题了 
{
    return t;
}
//如果想用直接得到一个常量对象，也可以使用 constexpr 修饰一个构造函数，
//这样就可以得到一个常量构造函数了。常量构造函数有一个要求：构造函数的函数体必须为空，并且必须采用初始化列表的方式为各个成员赋值。

struct T
{   
    constexpr T():a(100)  //构造函数的函数体必须为空
    {

    }
    int a;
}


int main()
{
    struct Person p { "luffy", 19 };
    //普通函数 里面constexpr 无效了
    struct Person ret = dispaly(p);
    cout << "luffy's name: " << ret.name << ", age: " << ret.age << endl;

    //常量表达式函数
    constexpr int ret1 = dispaly(250);
    cout << ret1 << endl;

    constexpr struct Person p1 { "luffy", 19 };//常量对象
    constexpr struct Person p2 = dispaly(p1);
    cout << "luffy's name: " << p2.name << ", age: " << p2.age << endl;
    return 0;
}