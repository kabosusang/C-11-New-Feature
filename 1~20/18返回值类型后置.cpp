#include <iostream>
using namespace std;


template <typename R, typename T, typename U>
R add(T t, U u) //返回值R类型
{
    return t + u;
}
template <typename T, typename U> //因为已经推导出来了 所以可以把定义的R模板删除
auto add1(T t, U u)->decltype(t+u)//auto必须初始化类型 所以用decltype auto->被decltype初始化了
{
    return t + u;
}

int main()
{
    int x =520;
    double y =13.14;
    auto ret = add<decltype(x+y),int,double>(x,y); //后面()是初始化模板 
    //不符合逻辑 因为有时候不能看到返回值x+y
    auto ret2 = add1(x,y); //<int,double>去掉 把模板参数给删掉
    cout<<"ret:"<<ret<<endl;
    cout<<"ret2:"<<ret2<<endl;
    return 0;
}