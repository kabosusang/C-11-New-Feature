#include<iostream>
#include<vector>
#include<complex>
using namespace std;

class Zoo
{
public: //Big3 构造函数可以有很多个 copy cto只能有一个 赋值ctos也只能有一个   
    Zoo(int i1,int i2):d1(i1),d2(i2){}
    Zoo(const Zoo&) =delete;
    Zoo(Zoo&&)=default;  //即使已经定义 但还是要编译器给的那一个
    Zoo& operator=(const Zoo&)=default;
    Zoo& operator=(const Zoo&&)=delete;
    virtual ~Zoo(){  }
private:
int d1,d2;
};