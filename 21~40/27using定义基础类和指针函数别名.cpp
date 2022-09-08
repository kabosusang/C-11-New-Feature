#include <iostream>

using namespace std; //1.using namespace 命名空间
//2.显示父类的重载函数
//3.去定义类型的别名 typedef 旧的类型 新的类型  using 旧的类型 = 新的类型
int mytest(int a, string b)
{
    cout<<"a:"<<a<<"b:"<<b<<endl;
    return 0;
}
typedef int (*ptr1)(int,string); //可读性比较差
using ptr2 = int(*)(int,string); //两者使用方法完全相同


int main(void)
{
    ptr1 f =mytest;
    ptr2 f1 =mytest;
    f(10,"hello");
    f1(10,"hello");
    return 0;
}
