#include <vector>
#include <iostream>
#include <cstdio>
#include <list>
#include<string>
using namespace std;



int main()
{
    vector<list<int> > a1;//旧写法
    vector<list<int>> a2; //不用加空格
    
    // C++11里面NULL变成了0   不再是void*类型
    //nullptr是新的空指针

    auto i =42; 
    auto l = [](int x)->bool{

    };

    list<string> c;

    c.push_back("Hello");
    list<string>::iterator ite;
    ite = find(c.begin(),c.end(),"Hello");

    auto ite1 = find(c.begin(),c.end(),"Hello"); //auto推导


}