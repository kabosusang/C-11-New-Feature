
#include <iostream>
#include<cassert>
using namespace std;
//decltype 类型推导 是"declare type"的缩写
//和auto 不同 decltype不需要初始化 
//decltype(表达式)

class Test
{
public:
    int num =9;
    string text;
    static const int value =110;
};
//函数声明
int func_int();                 // 返回值为 int
int& func_int_r();              // 返回值为 int&
int&& func_int_rr();            // 返回值为 int&&

const int func_cint();          // 返回值为 const int
const int& func_cint_r();       // 返回值为 const int&
const int&& func_cint_rr();     // 返回值为 const int&&

const Test func_ctest();        // 返回值为 const Test

int main()
{
    /*decltype自动推导 3点细节
1.推导的如果是普通变量或者普通表达式或者类表达式 decltype类型和表达式类型一致
*/
    int a =9;
    decltype(a) b =99;  //int
    decltype(a+3.14) c =352.123;   //double
    decltype(a+b*c) d =520.123;  //double
    
    int x = 99;
    const int &y = x; 
    //a:int
    decltype(x) a = x; 
    //b:const int &
    decltype(y) b = x;
    //const int
    decltype(Test::value) c = 0;
    Test t;
    //string
    decltype(t.text) d ="Hello,World";
    //上面都是根据类型推导出一样的类型
    /*------------------------------------------------------------------------------*/
    //2.表达式是函数调用，使用 decltype 推导出的类型和函数返回值一致
    //纯右值:"Hello" ,520 对于纯右值而言，只有类类型可以携带const、volatile限定符，除此之外需要忽略掉这两个限定符

    int n=100;

    int n = 100;
    decltype(func_int()) a = 0;	//int	
    decltype(func_int_r()) b = n;	//int &
    decltype(func_int_rr()) c = 0;	//int &&
    decltype(func_cint())  d = 0;	//int 因为返回的是字面量 是纯右值 函数也不再类里面所以忽略const
    decltype(func_cint_r())  e = n;	//const int&
    decltype(func_cint_rr()) f = 0;	//const int&& 右值引用
    decltype(func_ctest()) g = Test();	//const Test

    //3.表达式是函数调用，使用 decltype 推导出的类型和函数返回值一致
    //表达式是一个左值，或者被括号 ( ) 包围，使用 decltype 推导出的是表达式类型的引用（如果有 const、volatile 限定符不能忽略）。

    const Test obj;
    //带有括号的表达式
    decltype(obj.num) a = 0;
    decltype((obj.num)) b = a; //被放到了小括号里面 因为定义了为常量对象
    //加法表达式
    int n = 0, m = 0;
    decltype(n + m) c = 0;
    decltype(n = n + m) d = n;






    return 0;
}
