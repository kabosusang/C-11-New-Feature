#include <iostream>

using namespace std;
//用于修饰常量表达式
//c++11以前 const修饰 只读 常量
auto f =[](){return 1;};

struct Test
{
    int id;
    int num;
};
void func(const int num)
{
    int a1 = 510;
    int a2 = 250;
    const int cout =24; //const定义的常量 
    int array[cout];
    //int array[a1]; //数组定义里面只能指定常量
   // int array[num]; //也会报错 参数的num只是不能修改num的值
    //只有常量表达式才能通过constexpr来修饰
const int m = f();  // 不是常量表达式，m的值只有在运行时才会获取。 一般常量在编译后才能执行
const int i=520;    // 是一个常量表达式
const int j=i+1;    // 是一个常量表达式

constexpr int i=520;    // 是一个常量表达式
constexpr int j=i+1;    // 是一个常量表达式 
 //结论 在定义常量的时候可以使用const 也可以使用constexpr c++11以后推荐使用constexpr了
 //constexpr不能定义struct class对象
}

int main(void)
{
    constexpr Test T1{1,1};//c++11以后可以这样初始化类
    //T1.id =12;//编译器提示可修改的必须是左值(就是可修改的变量)
    return 0;
}
