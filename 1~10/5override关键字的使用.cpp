#include <iostream>
using namespace std;

class Base 
{
    public:
    virtual void test()
    {
        cout<<"Base class...";
    }

};

class Child :public Base
{
public:
     void test() 
    {
        cout<<"Child class...";
    }  


};

class GrandChild :public Child 
{
public:
    void test() override //重写父类函数 实现多态 保证编译的时候即使发现错误
    {
        cout<<"GrandChild class...";
    }

};


int main()
{
    Child* G =nullptr;
    G = new GrandChild;
    G->test();
    delete G;

    return 0;
}