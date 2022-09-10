#include <iostream>
#include<list>
using namespace std;
//move 转移 
/*在 C++11 添加了右值引用，并且不能使用左值初始化右值引用，
如果想要使用左值初始化一个右值引用需要借助 std::move () 函数，
使用std::move方法可以将左值转换为右值。使用这个函数并不能移动任何东西，
而是和移动构造函数一样都具有移动语义，将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存拷贝。
*/
//c++右值种类: 纯右值 将亡值

//move把左值进行转移 给右值引用初始化

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
    Test&& t1 =getObj();         

    Test&& t3 =t2; //语法上不对 右值引用会转移成左值
    Test&& t4 =move(t1);//资源转移
    Test&& t5 = move(t);//左值引用最终还是左值

    list<string> ls1{
        "Hello","world","nihao","shijie",
        "ace","sabo","luffy"
    };

    list<string> ls2 = ls1;  //拷贝  如果后面不用ls1了 就可以进行资源的转移
    list<string> ls2 = move(ls1); //资源转移

    //场景 1.右值引用初始化  2.资源的转移


    return 0;
}