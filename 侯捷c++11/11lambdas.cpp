#include <iostream>
#include <initializer_list>
#include <vector>
#include <map>
using namespace std;

int main()
{
    /*[]{
        cout<<"Hello lambda"<<endl;
    }*/ //定义一个lambda
    []{
        cout<<"Hello lambda"<<endl;
    }();//();就是调用起来

    auto I = []{
        cout<<"Hello lambda2"<<endl;
    };
    I(); //调用 上面只能调用一次
        //可以认为lambda本身就是一个函数对象

    int id =0;
    auto f = [id]() mutable{
        cout<<id<<endl;
        ++id;
    };
    id =42;
    f();
    f();
    cout<<id<<endl;



}
/*lambda 表达式的捕获列表可以捕获一定范围内的变量，具体使用方式如下：

    [] - 不捕捉任何变量
    [&] - 捕获外部作用域中所有变量，并作为引用在函数体内使用 (按引用捕获)
    [=] - 捕获外部作用域中所有变量，并作为副本在函数体内使用 (按值捕获)
        拷贝的副本在匿名函数体内部是只读的
    [=, &foo] - 按值捕获外部作用域中所有变量，并按照引用捕获外部变量 foo(只有foo引用)
    [bar] - 按值捕获 bar 变量，同时不捕获其他变量(指定变量)
    [&bar] - 按引用捕获 bar 变量，同时不捕获其他变量
    [this] - 捕获当前类中的 this 指针
        让 lambda 表达式拥有和当前类成员函数同样的访问权限
        如果已经使用了 & 或者 =, 默认添加此选项

。*/

/*
opt 选项， 不需要可以省略

    mutable: 可以修改按值传递进来的拷贝（注意是能修改拷贝，而不是值本身）
    exception: 指定函数抛出的异常，如抛出整数类型的异常，可以使用 throw ();

返回值类型：在 C++11 中，lambda 表达式的返回值是通过返回值后置语法来定义的。

函数体：函数的实现，这部分不能省略，但函数体可以为空。 

*/