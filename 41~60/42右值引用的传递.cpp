#include <iostream>

using namespace std;
int&& a =6;//右值引用
int&& b =a;//错误因为a没有名字没有地址   
//右值引用进行传递 就会具名化

//拿着右值引用进行传递会看成左值引用

//1.左值和右值 左值引用和右值引用不相同
//2.编译器会将已命名的右值引用视为左值
//3.auto&& T&& 自动推导 


int main(void)
{
    
    return 0;
}