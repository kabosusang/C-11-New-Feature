
#include <iostream>
#include<cassert>
using namespace std;


//auto 不是万能的  不能作为函数的形参(如果没有调用)
//1.不能用类的非静态成员变量的初始化 2.类的非常量的静态成员不能在函数内部初始化
/*
    class Test
    {
        auto v1 =0; //error        
        static auto v2 =0; //error
        static const auto v3 =0 //ok

    }
    因为只有加static const auto才能推导出函数的类型
    int func()
{
    int array[] = {1,2,3,4,5};  // 定义数组
    auto t1 = array;            // ok, t1被推导为 int* 类型
    auto t2[] = array;          // error, auto无法定义数组
    auto t3[] = {1,2,3,4,5};;   // error, auto无法定义数组
}
*/

//不能用auto 关键字定义数组
//不能用auto 推导出模板参数
//template<typename T>
//struct Test{
//Test<auto> t1 = t;  error, 无法推导出模板类型
// };


int main()
{
    return 0;
}
