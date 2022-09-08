#include <iostream>

using namespace std;
//继承构造函数提高优化
class Base
{
public:
    Base(int i) :m_i(i) {}
    Base(int i, double j) :m_i(i), m_j(j) {}
    Base(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}

    int m_i;
    double m_j;
    string m_k;
};

class Child : public Base
{
public:
    //Child(int i) :Base(i) {} c++11以前的调用父类构造函数
    //Child(int i, double j) :Base(i, j) {}
    //Child(int i, double j, string k) :Base(i, j, k) {}
    using Base::Base; //后面的Base是构造函数的名字

    //using Base::父类函数  可以调用父类的函数

};

int main(void)
{
     Child c(520, 13.14, "i love you");//直接用父类的构造函数初始化数据
    cout << "int: " << c.m_i << ", double: " 
         << c.m_j << ", string: " << c.m_k << endl;



    return 0;
}