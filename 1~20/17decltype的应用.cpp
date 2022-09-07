
#include <iostream>
#include<list>
using namespace std;

//主要运用于泛型编程 用decltype进行推导
template <typename T>
class Container
{
public:
    void func(T& c)
    {
        for (m_it = c.begin(); m_it != c.end(); ++m_it)
        {
            cout <<"value:"<< *m_it << endl;
        }
        cout << endl;
    }
private:
    decltype(T().begin()) m_it;    // 这里不能确定迭代器类型 编译器不承认 在这里要进行类型的自动推导
};                                  //T() 声明一个函数对象 T().begin()因为begin()反回值是iterator 

int main()
{
    list<int> lst{1,2,3,4,5,6,7};  //初始化list
    // list<int>::iterator it = lst.begin(); //begin返回类型是iterator 可以用decltype
    const list<int> lst1{1,2,3,4,5,6,7};
    Container<list<int>> obj;
    Container<const list<int>> c1;  //遍历常量迭代器就是 const iterator
    obj.func(lst);
    c1.func(lst1);
    return 0;

    
}

