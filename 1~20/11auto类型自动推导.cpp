
#include <iostream>
#include<cassert>
using namespace std;

//关键字 auto  decltype来表示函数的返回值
//当变量不是指针或者引用类型时，推导的结果中不会保留 const、volatile 关键字
//当变量是指针或者引用类型时，推导的结果中会保留 const、volatile 关键字


int main()
{   
    //没有const修饰
    auto x =3.14; //double
    auto y = 520; //int
    auto z ='a'; //char
    //错误组合 auto nb;  auto double nbl;

    int temp =110;

    auto* a =&temp; //自动推导成int *
    auto b =temp; //自动推导成int

    //有const修饰
    int tmp = 250;
    const auto a1 =tmp; //a1:const int

    auto a2 =a1;//因为里面不是指针也不是引用 所有const被忽略
    const auto& a3 =tmp; //保留const
    auto& a4 =a3; //a4:const int类型的应用

    auto* pt4 =&a1; //a4:const int* const int*只能修改指针指向的地址不能修改指针指向地址里面的值


    return 0;
}
