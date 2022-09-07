#include <iostream>
#include <functional>
using namespace std;

class Test
{
public:
    void output(int x, int y)
    {
        int a =0;
        int b =0;
        //重点::你在程序这里写了lambda函数只是定义 并没有被调用 只有在[]() ret->{}(这里写了小括号才被调用)  ;
        //调用格式[=](int z){}(10); 要是前面指定了参数 后面小括号里面要写实参
        //auto x1 = [] {return m_number; };                      // error
        auto x2 = [=] {return m_number + x + y; /*x++不被允许*/};  // ok 采用值拷贝的方式拷贝进来的数据都是只读的(自己复制了一份) m_number + x + y
        auto x23 = [=]() mutable {return m_number + x + y; x++;/*加了mutable就能修改只读数据了*/};  
        auto x3 = [&] {return m_number + x + y; };             // ok
        auto x4 = [this] {return m_number; };                  // ok
        //auto x5 = [this] {return m_number + x + y; };          // error
        auto x6 = [this, x, y] {return m_number + x + y; };    // ok
        auto x7 = [this] {return m_number++; };                // ok
    };
    int m_number = 100;

};