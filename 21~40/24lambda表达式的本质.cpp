#include <iostream>
#include <functional>
using namespace std;
//lambda表达式的类型在C++11中会被看做是一个带operator()的类，即仿函数。
//按照C++标准，lambda表达式的operator()默认是const的，一个const成员函数是无法修改成员变量值的。
using func_ptr = int(*)(int);
// 没有捕获任何外部变量的匿名函数
func_ptr f = [](int a) //如果[]里没有东西 可以用作函数指针 如果有值就只能用作反函数
{
    cout<<a<<endl;
    return a;  
};
// 函数调用  lambda函数可以放到auto 也可以放到function  auto得到一个反函数   而function得到一个包装器对象 包装器对象可以爆装auto推导出来的类型
      //func_ptr f2 = [=](int a) //等号就有问题了 []里加东西编译器会把他看成仿函数 
function<void> ff = [=](int x)   //包装器function<>        
{
    cout<<x<<endl;
     
};
function<void> ff = bind([=](int x)   //绑定器bind  placeholders 占位符
{
    cout<<x<<endl;
     
},placeholders::_1);

int main(void)
{
    f(1314);
    ff(520);
    return 0;
}
