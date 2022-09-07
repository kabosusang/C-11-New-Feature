#include <iostream>
using namespace std;

struct Base
{
    Base():a(250) //更好的初始化 构造函数初始化
    {
    }
    int a{4};
    int b = 1;
    double cc = 1.23;
    char aa ='a';
    string str = "Hellow";  // 初始化
    string str1{"World"}; //另一种初始化方法
    //string str2("Hello,World"); //语法上不成立

    static int c ;
    static const double d ;
    static const char * const e ;

    //C++98标准:变量是静态常量,并且类型是整形或枚举类型
    const static int f =0;//静态整形或枚举可以在类内初始化
};
int Base::c = 8;//静态成员变量一定要在类外进行初始化 静态成员为所有类对象所共享 静态成员函数没有隐藏的this指针，不能访问任何非静态成员
                //静态成员也是类的成员，受public、protected、private访问限定符的限制

const double Base::d = 3.14;  
const char* const e ="i am lufy";



int main()
{
    Base qe;
    cout<<"a value:"<<qe.a<<endl;
    return 0;
}