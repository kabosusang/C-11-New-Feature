#include <iostream>

using namespace std;
//初始化列表初始化两种情况 1.聚合体类型 2.非聚合体要求

//普通数组可以看做一个聚合体类型
int x[]{1,3,4,5};
//满足以下条件的类(class struct union)可以被看做是一个聚合类型
//1.无用户自定义构造函数
//2.无私有或保护的非静态数据成员
struct T1
{   
    int x;
    long y;
protected:
    int z;

}{1,100,2};  //error  类中有私有成员 不能这样初始化非聚合类型
struct T2
{   
    int x;
    long y;
protected:
    static int z ;

}t{1,100};  //error  因为类中有static成员 初始化要写到类外面
                //正确写法{1,100}
                //int  T2::z =1;  写到类外面
  
//3.无基类 无虚函数



int main(void)
{
    
    return 0;
}
