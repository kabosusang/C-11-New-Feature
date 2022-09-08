#include <iostream>

using namespace std;
//和聚合类定义相反 都可以看是聚合类
//如果想要给非聚合类初始化 要给类一个构造函数
struct  T1
{
public:
       T1(int id,string name):m_id(id),m_name(name){};
        
private:
        int m_id;
        string m_name;

};
T1 getOerson()
{
    return {520,"kabo"}; //会调用构造函数初始化 返回一个匿名对象

}
struct T3
{
    int x;
    double y;
private:
    int z;

}; //非聚合类型
struct T4
{
    T3 t1; //看成整体
    double x1;
    int y1;

}; //聚合类型





int main(void)
{
    T1 t1{1,"Hello"}; //会调用构造函数初始化
    T4 t4{{},3.14,123};//T3不能这样初始化 就把他置空 想要初始化就在T3写构造函数

    return 0;
}

