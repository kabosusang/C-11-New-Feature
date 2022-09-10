#include <iostream>

using namespace std;
//&&的特性 模板T&& 或者 auto&&  为定义引用类型
//通过右值推导 得到的是一个右值引用
//其他都是左值引用(包括右值引用)
template<typename T>
void f(T&& param);
void f1(const T&& param);//const T&&不需要推导 就是右值引用
f(10); 	//右值引用
int x = 10;
f(x); //左值引用类型
f1(x); //f1永远不变  右值引用

int main(void)
{
    int x = 520, y = 1314;
    auto&& v1 = x; //左值
    auto&& v2 = 250; //右值
    decltype(x)&& v3 = y;   // error 因为不是模板也不是auto 只是个右值引用
    cout << "v1: " << v1 << ", v2: " << v2 << endl;

int&& a1 = 5; //右值引用
auto&& bb = a1; //通过右值引用推导未定义的引用类型就是左值引用
auto&& bb1 = 5; //右值应用

int a2 = 5;
int &a3 = a2;//左值引用
auto&& cc = a3;//左值引用
auto&& cc1 = a2;//左值引用

const int& s1 = 100; //右侧的值如果有const 加上const
const int&& s2 = 100;
auto&& dd = s1;//const 左值引用
auto&& ee = s2;//const int& 左值引用

const auto&& x = 5;


    return 0;
}