#include<map>
#include <iostream>
#include<cassert>
using namespace std;
/*1.stl容器的变量
 map插入数据的另一种方法
 map<int,string> mp;
mp.insert(make_pair(1,"ace"));

2.泛型编程 虽然不能推导模板
但可以再里面调用

template<class T> 函数模板

*/
class T1
{
public:
    static int get()
    {
        return 10;
    }
};

class T2
{
public:
    static string get()
    {
        return "hello, world";
    }
};


template<class T>  //Vecteor mao list 都有对应模板
void func(void)
{
    auto ret =T::get(); //这种情况能使用 可以用返回值推导ret实际的类型
    cout << "val: " << ret << endl;
}

int main()
{
 map<int,string> mp;
 mp.insert(make_pair(1,"Num01"));
 mp.insert(make_pair(2,"Num02"));
 mp.insert(make_pair(3,"Num03"));
//map<int,string>::iterator it = mp.begin(); //定义迭代器很麻烦 
auto it =mp.begin();  //通过调用begin()函数 自动获得迭代器iterator的类型
for(;it!=mp.end();++it)
{
    cout <<"key:"<<it->first<<",value:"<<it->second<<endl;
    
}
 func<T1>(); //auto使用模板推导出的类型没有问题
 func<T2>();



    return 0;
}
