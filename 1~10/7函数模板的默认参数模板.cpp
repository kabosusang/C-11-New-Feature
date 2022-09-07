#include <iostream>
using namespace std;

template<typename T=int, T=122>  //c++11可以给模板默认类型 默认参数
void func(T t)
{

    cout<<"Current value:"<<t<<endl;
}
template<typename T=long,typename U=int>
void func1(T t= 'A',U u = 'B')//默认参数 不能用于推导
{

    cout<<"T:"<<t<<"U:"<<u<<endl;
}


int main()
{
    //自动推导 根据传递的实参 只有根据实参推导不出来 才会用默认的模板类型
    func1('a','b');//<char char>
    func1<int>('a','b');//<int,char>
    func1<char>('a','b');//<char,int>
    func1<int,char>('a','b');//<int,char>
    func1<char,int>('a','b');//<char,int>
    func1();//<long,int> 默认参数 A B
    //如果是类必须加<>

}