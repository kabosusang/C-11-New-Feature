#include<iostream>
#include<vector>
using namespace std;
//using std::vector;//using打开两种写法


void example(int,int){}
typedef void(*func)(int,int); //C语言就有的函数指针
func func_1= example;//指向函数
 
//和上面一样
using func1 = void(*)(int,int);
func1 func2= example; //和上面功能相同

struct Base1 final{
    virtual void f() final; //final不想让人重写

}; //final不想让人继承


int main() noexcept //不抛出异常
{



}