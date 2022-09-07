
#include <iostream>
#include <map>   
#include <set>
#include<vector>
using namespace std;
vector<int> v{ 1,2,3,4,5,6 };
vector<int>& getRange()  //可以定义一个函数反汇类型是容器类型 赋给auto自动推导
{
    cout << "get vector range..." << endl;
    return v;
}


int main()
{
    map<int,string> m{{1,"String01"},{2,"String02"},{3,"String03"}
    };

    //基于范围的for循环 但是因为没有每次都判断所以修改元素后可能导致遍历失败
    //两次遍历都有自己的优缺点
    for(auto& it :m) //auto推导出的是pair这个对象 
    {
        cout<<"id:"<<it.first<<" "<<"name:"<<it.second<<endl;
    }
    cout<<endl;
    //基于迭代器的for循环
    for(auto it1 = m.begin();it1!=m.end();it1++) //某种程度可以把迭代器看成一个指针 所以要用->
    {
        cout<<"id:"<<it1->first<<"name:"<<it1->second<<endl;
    }
    //set类型 只要把元素放入set中默认情况下都是只读
#if 0
set<int> st{ 1,2,3,4,5,6 };
    for (auto &item : st) 
    {
        cout << item++ << endl;		// error, 不能给常量赋值
    }
#endif
//在map里默认情况下 key也是只读的


    for (auto val : getRange())
    {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}