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
    printValue(forward<T>(v));  9//这个v看前面的那个T的类型 T是左值引用v就是左值
    cout << endl;
}

int main(void)
{
    testForward(520);//右值引用 推导出1.printValue(v)为左值 2.printValue(move(v))为右值
    //3.printValue(forward<T>(v));
    //当T为左值引用类型时，u将被转化成T类型的左值引用。
    //当T为左值时，u将被转化成T类型的右值。
    //当T为右值时，可以不考虑这种情况
    int num = 1314;
    testForward(num);
    testForward(forward<int>(num));//因为int不是左值引用 所以num是左值 forward只能决定传入的num是左值还是右值
    testForward(forward<int&>(num));
    testForward(forward<int&&>(num));


    return 0;
}