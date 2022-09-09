#include <iostream>
#include <functional>
using namespace std;
class  A
{
public:
    A(const function<void(int,string)>& f):calllback(f)
    {

    }
    void notifu(int id,string name)
    {
        calllback(id,name); //调用 类似回调函数
    }

private:
    function<void(int,string)> calllback;

};


void print(int num, string name)
{
    cout<<"num:"<<num<<" "<<"name:"<<name<<endl;
}


using func_ptr = void(*)(int, string);
class Test
{
public:


    static void world1(int a,string s) 
    {
        cout<<"number1:"<<a<<" "<<"name1:"<<s<<endl;
    }
    static void world(int a ,string name)
    {
         cout<<"number2:"<<a<<" "<<"name2:"<<name<<endl;
    }
   void operator()(string msg)
   {
         cout << "msg: " << msg << endl;
   }
    operator func_ptr()
    {
        return world1;
    }

};



    //调用35中的三种函数比较麻烦 我们可以把它们打包成一种 直接指定一个函数就可以 
    //把函数参数定义统一的一种类型 制定好 放入模板函数
    //类的成员函数想要被打包必须要使用绑定器

    //std::function<返回值类型(参数类型列表)> diy_name = 可调用对象;
    //1.包装普通函数
    //2.包装类的静态函数
    //3.包装仿函数


 int main(void)
{
        //1.包装普通函数
    function<void(int,string)> f1 =print; //只是打包 不会调用
        //2.包装类的静态函数
    function<void(int,string)> f2 =Test::world; 
        //3.包装仿函数
    Test ta;
    function<void(string)> f3 = ta;  //打包的时候参数类型不一致 可以构造函数加个类型
        //4.包装转换为函数指针的对象
    Test tb;
    function<void(int,string)> f4 = tb; 

    //得到 f1 f2 f3 f4

    //调用
    f1(1,"ace");
    f2(2,"sabo");
    f3("luffy");
    f4(3,"Hello");

    A aa(print); //间接调用函数
    aa.notifu(1,"ace");

    A ab(Test::world);
    aa.notifu(2,"sabo");

    A ac(tb);
    ac.notifu(3,"lufei");


 }