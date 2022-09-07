
#include <iostream>

using namespace std;

struct MYException
{
    MYException(string str) :msg(str){}
    string msg;
};

            //throw(int,double,MYException) //表示当前函数只能抛出三种类型的异常 C++17不能使用
            //throw() 可以换成关键字 noexcept 里面没有代表改函数不能抛出异常(不能往改函数外抛出异常)
void func() noexcept
{
    try
    {
        /*判断异常的代码*/
        //throw 1; //抛出异常 不会继续向下执行
                //会继续返回到func 往下找到catch 执行   可以抛出任意类型的异常
        throw MYException("string Exception");//类型为 MYException 构造函数类型为自己
    }
    catch(int e)
    {
        cout<< "throw value"<<e<<endl;
    }
    catch(MYException e)
    {
        cout<<"MYException:"<<e.msg<<endl;
    }


}

void func2() noexcept //VS里面会警告 并且不会抛出异常 noexcept 等于 throw()
                        //noexcept(常量表达式 bool类型) 可以动态抛异常
{
    throw -1;
}


int main()
{
    func();
    try
    {
        func2();
    }
    catch(int e)
    {
        cout<<"函数抛出异常:"<<e<<endl;
    }
    
    return 0;
}