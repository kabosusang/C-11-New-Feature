#include <iostream>

using namespace std;
//右值引用能延长某块内存的存活时间
int&& value = 520;
class Test
{
public:
    Test():m_num(new int(100))
    {
        cout<< "construct:my name is jerry"<<endl;
        printf("m_num 地址: %p\n",&m_num);
    }
    Test(const Test& a) : m_num(new int(*a.m_num))
    {
        cout<< "copy construct:my name is tom"<<endl;
    }
    ~Test()
    {
        cout<< "destruct Test class .."<<endl;
        delete m_num;
    }
    Test(Test&& a):m_num(a.m_num)  //移动构造->另一个对象的堆内存
    {                               //浅拷贝
        a.m_num=nullptr;//这样就可以继续使用了 后面delete的就是nullptr了
        
        cout<<"move vonstruct"<<endl;   
    }

    int* m_num =0;
};
Test getObj()
{
        Test t; //这里t并没有使用 只是复制给外面的t
        return t;//添加一个右值构造函数(移动函数)
}


int main(void)
{
    Test t =getObj(); //这里getObj里面的t对象执行结束也会被析构 初始化外面的t的时候又做了个拷贝构造
        


    return 0;
}
