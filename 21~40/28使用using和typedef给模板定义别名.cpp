#include <iostream>
#include <map>
using namespace std;
//using 比typedef能定义模板的类型
//map: int-int int-double int-string

template<typename T>
//typedef map<int, T> mapType; //语法上不允许这样直接用 但可以用类包裹起来
struct MyMap
{
    typedef map<int, T> mapType; //这样语法上允许
};
//using定义
template<typename T>
using MMap =map<int,T>; //简洁 不需要像typedef一样要用结构体包装

int main(void)
{
    MyMap<int>::mapType mm1; //通过模板结构体中map定义类型
    mm1.insert(make_pair(1,1));//复制
    MyMap<double>::mapType mm2;
    MyMap<string>::mapType mm3;
    mm3.insert(make_pair(1,"Hellow"));

    map<int,int> m;//首先想到模板 后面这个类型 int double string 用模板替代 泛型编程
    map<int,double> m1;
    map<int,string> m2;

    MMap<string> mm4; //using 定义模板
    




    m2.insert(make_pair(1,"Hellow")); //插入数据

    return 0;
}