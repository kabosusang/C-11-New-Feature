#include <iostream>

using namespace std;
//forward  模板函数
// 函数原型
template <class T> T&& forward (typename remove_reference<T>::type& t) noexcept;
template <class T> T&& forward (typename remove_reference<T>::type&& t) noexcept;

// 精简之后的样子
std::forward<T>(t);
//如果模板类型是左值引用类型 推导为左值
//
template<typename T>
void printValue(T& t)
{
    cout << "l-value: " << t << endl;
}

template<typename T>
void printValue(T&& t) //未定义类型的引用
{
    cout << "r-value: " << t << endl;
}

template<typename T>
void testForward(T && v)//未定义类型的引用
{
    printValue(v);
    printValue(move(v));
    printValue(forward<T>(v));  //这个v看前面的那个T的类型 T是左值引用v就是左值
    cout << endl;
}

int main(void)
{
    testForward(520);//右值引用 推导出1.printValue(v)为左值 2.printValue(move(v))为右值
    //3.printValue(forward<T>(v));

    int num = 1314;
    testForward(num);
    testForward(forward<int>(num));
    testForward(forward<int&>(num));
    testForward(forward<int&&>(num));


    return 0;
}