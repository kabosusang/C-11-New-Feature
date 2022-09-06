#include <iostream>
using namespace std;

int main()
{
    // 有符号
    long n =100L; //一般在长整型后面加个L或l
    // 等价于
    // long int
    // signed long int 
    long long num1 = 11111LL; //2个LL
    // signed long long 
    // long long int
    // signed long long int

    unsigned long long num2 = 1111ULL; //后缀ULL
    // unsigned long long int

    //long long 类型最少占8个字节
    //超长整形C++中对应的宏
    //LONG_MAX LONG_MIN LLONG_MAX LLONG_MIN ULONG_MAX ULLONG_MAX
    cout<<"long long MAX:"<<LLONG_MAX
        <<",long long MIN:"<<LLONG_MIN
        <<",unsigned long long MAX:"<< ULLONG_MAX <<endl;

    char c =6;
    long long d = c ; //隐式类型转换 会把小转大

    //自定义类型
    typedef int aa;
    aa bb =5;
    int num = bb;
    long long num3 =num;
    //有符号int 无符号 int (有符号整形转换成无符号整形)
    unsigned int num4 =num1;

    //其他整形 
    //signed char 
    //short int
    //int
    //long int
    //long long int
    return 0;
}