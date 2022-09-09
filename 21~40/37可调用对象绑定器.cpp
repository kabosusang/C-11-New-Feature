#include <iostream>
#include<functional>
using namespace std;
//std::bind用来将可调用对象与其参数一起进行绑定。绑定后的结果可以使用std::function进行保存，并延迟调用到任何我们需要的时候。通俗来讲，它主要有两大作用：

    //将可调用对象与其参数一起绑定成一个仿函数。
   // 将多元（参数个数为n，n>1）可调用对象转换为一元或者（n-1）元可调用对象，即只绑定部分参数。

// 绑定非类成员函数/变量 包括静态函数
//auto f = std::bind(可调用对象地址, 绑定的参数/占位符);
// 绑定类成员函/变量
//auto f = std::bind(类函数/成员地址, 类实例对象地址, 绑定的参数/占位符);

//占位符 placeholders_x
void output(int x,int y)
{
    cout << x << " " << y <<endl;
}
void callFunc(int x,int y, const function<void(int,int)>& f) //通过绑定器可以得到一个可调用对象
{
    if (x % 2 == 0)
    {
        f(x,y);
    }
}
void output_add(int x,int y)
{
    cout << "x:" <<x  <<" y:"<<y<<endl;;
}

int main(void)
{
    bind(output,1,2)(); //最后的()相当于调用了这个仿函数
    bind(output,placeholders::_1,2)(10);  //如果用了占位符 后面调用的时候要指定实参
    //bind(output,2,placeholders::_2)(10);  //错误的 应为_2会在实参列表里面找第二个实参
    bind(output,2,placeholders::_2)(10,20);  //10传递进来不起作用 都是使用绑定进来的数值 所以是2

    bind(output,placeholders::_1,placeholders::_2)(10,20); //10,20
    bind(output,placeholders::_2,placeholders::_1)(10,20); //20,10
    
    
    for(int i =0;i<10;++i)
    {
        //绑定outputadd
       auto f = bind(output_add,i+100,1+200);
        callFunc(i,i,f);
        //优化
        auto f1 = bind(output_add,placeholders::_1,placeholders::_2);
        callFunc(i,i,f);
    }
    
    
    
    
    return 0;
}
