#include <iostream>
#include <functional>

using namespace std;
//可以把对象 以函数的形式掉用 成为可调用对象
//1.函数指针
int print(int a, double b)
{
    cout << a << b << endl;
    return 0;
}
// 定义函数指针
int (*func)(int, double) = &print;

 //2.operator()重载了()
struct Test1
{
    // ()操作符重载
    void operator()(string msg)
    {
        cout << "msg: " << msg << endl;
    }
};
//3.是一个可被转换为函数指针的类对象
using func_ptr = void(*)(int, string);
struct Test2
{
    Test2(){}
    static void print(int a, string b)
    {
        cout << "name: " << b << ", age: " << a << endl;
    }
    static void word(int a,string b)
    {
        cout<<"word函数执行了"<<endl;
    }
    void world1(int a,string b)
    {
        cout<<"world1被执行了"<<endl;
    }

    // 将类对象转换为函数指针
    operator func_ptr() //代表是一个函数
    {
        return print;  //转换返回函数地址 类型必须根函数指针相同
    }    
    int m_id =520;               //返回print 间接的函数被执行了
};


int main(void)
{
    Test1 t1;
    t1("我是要成为海贼王的男人!!!");	// 仿函数 使用重载符

     Test2 t;
    // 对象转换为函数指针, 并调用
    t(19, "Monkey D. Luffy"); //转换函数指针 可以传函数()的参数
    //类的函数指针 类的普通用成员指针
    //指针指向的函数如果是非静态成员 必须要等对象存在了才能指向他
    //不然就在类中定义静态函数 static
    func_ptr ptr2 = Test2::word; //换成静态的就行了
    //另一种方法就是指定作用域 指向类成员的函数指针
    using Teptr = void(Test2::*)(int,string);

    Teptr  f1 = Test2::world1;//因为函数名本身就是地址 取地址符可写可不写
    //类的成员指针
    using Teptr2 = int Test2::*;
    Teptr2 pt = &Test2::m_id; //因为是成员函数所以要取地址

    //f1 pt 都属于这个类
    Test2 ttt;
   // ttt.*f1(1,"ace"); //因为*优先级比()优先级低
    (ttt.*f1)(1,"ace"); //真奇怪的写法

    ttt.*pt =100;
    cout<<"m_id:"<<ttt.m_id<<endl;










    return 0;
}
