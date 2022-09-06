#include <iostream>
using namespace std;

//final 只能修饰虚函数 加了final 能阻止子类重写这个函数
//final 只能修饰虚函数 在子类中加final 不让继承子类的类重写
class Base 
{
    public:
    virtual void test()
    {
        cout<<"Base class...";
    }

};

class Child  :public Base
{
public:
    void test() //final //final关键字 不允许子类继续重写 加在函数后
    {
        cout<<"Child class...";
    }


};

class GrandChild final:public Child //在类后面加final 这个类不允许被别人继承
{
public:
    void test()
    {
        cout<<"GrandChild class...";
    }

};

int main()
{
    GrandChild G;
 
    G.test();
}
