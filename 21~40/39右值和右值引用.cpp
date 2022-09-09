#include <iostream>

using namespace std;
//lvaue左值   rvalue右值
//左值能取地址 右值不能取地址
//左值引用不占用空间
int&& c =5;//右值引用 不能对5进行取地址操作所以5是右值

int main(void)
{ 
    const int&& d =6;
    //左值
    int num =9;
    //左值引用
    int& a =num;//a不占用额外的内存地址a是num的别名
    //右值 :常量 常量字符串
    //右值引用
    int&& b =8;
    //常量左值引用 const constexpr(推荐这个但必须是常量)
    const int& c =num;
    const int& g =b; //可以用右值初始化
    const int& h =d; //可以用右值引用初始化、
    const int& i =a; 
  //也就是说常量左值引用是万能的
    //常量右值引用
    
    const int&& e =b;//错误写法

    int&& f =b; //写法也错误  右值引用只能通过右值初始化



    
    return 0;
}

