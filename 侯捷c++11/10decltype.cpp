#include <iostream>
#include <initializer_list>
#include <vector>
#include <map>
using namespace std;

map<string,float> coll;
decltype(coll)::value_type elem;
//3大应用
//1.用来声明一个return type
template<typename T1,typename T2>
decltype(x+y) add(T1 x, T2 y); //半成品 编译编不过 因为编译都是逐行编译器不认识x,y

template<typename T1,typename T2>
auto add(T1 x,T2 y)->decltype(x+y); //返回类型后置

//2.metaprogramming 模板里的运用
 //传入容器类型 使用容器里的定义和函数 

//3. pass the type of a lambda


int main()
{

}