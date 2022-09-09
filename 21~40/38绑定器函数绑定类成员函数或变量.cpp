#include <iostream>
#include <functional>
using namespace std;

//什么东西经过绑定器都能变成函数 调用用()
// 绑定非类成员函数/变量
//auto f = std::bind(可调用对象地址, 绑定的参数/占位符);
// 绑定类成员函/变量
//auto f = std::bind(类函数/成员地址, 类实例对象地址, 绑定的参数/占位符);
class Test
{
public:
        void output(int x,int y)
        {
            cout<< "x: " <<x<<"y: "<<y<<endl;
        }
public:
int m_number = 100;

};


int main(void)
{
    //成员函数绑定
    Test t;
    auto f2 =bind(&Test::output,&t,520,placeholders::_1);
    function<void(int,int)> f22 =bind(&Test::output,&t,520,placeholders::_1);
    f2(1314);

    //成员变量
    auto f3 = bind(&Test::m_number,&t);
    function<int&(void)> f33= bind(&Test::m_number,&t); //反函数
    //要可读可写所以用 int& 类型以及和 f3不相等了 

    cout<<f3()<<endl;
    f3() = 666;
    cout << f3() <<endl;

    return 0;
}