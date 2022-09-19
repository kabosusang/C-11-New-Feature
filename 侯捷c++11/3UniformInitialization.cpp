#include<iostream>
#include<vector>
#include<complex>
using namespace std;


int main()
{
    int values[]{1,2,3};  //一致性的初始化
    vector<int> v{2,3,4,5,6,7};
    vector<string> cities{
        "Hello","World"
    };
    complex<double> c{4.0,3.0}; 

    //Initializer Lists 
    //可以用来设初值
    int i; //不知道初值
    int j{}; //设初值是0
    int* p; //不知道初值
    int* q{}; //nullptr


    int x1(5.3); //OK
    int x2 = 5.3; //OK
    int x3{5.0}; //ERROR  没有默认转换
  
    char c1{7};

}