#include <iostream>

using namespace std;
//
int array[] = {1,3,5,7,9};
double array1[3]={1.2,1.3,1.4};
struct  Person
{
    int id;
    double salary;

}zhang3{1,3000}; //c++11以前初始化
class Person
{
    public:
        Person(int num):m_num(num){}
        Person(int num,string name):m_num(num),m_name(name){}

    private:
    int m_num;
    string m_name;
};


int main(void)
{
    //c++11 不管什么类型都可以有一种统一的初始化语法
    Person t1(520);
    Person t2 = 520; //隐式类型转换
    Person t3 ={50};
    Person t4{520}; //c++11新特性

    int a1 ={1314};
    int a2{1314};
    int a2{ 1314 };
    int arr1[] = { 1, 2, 3 };
    int arr2[]{ 1, 2, 3 };

    int * p = new int{520}; //初始化int
    double b = double{52.134}; //奇怪的初始化
    int * array = new int[3]{1,2,3}; //new数组初始化

    return 0;
}
