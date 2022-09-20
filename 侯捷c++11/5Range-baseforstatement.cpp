#include <iostream>
#include <vector>

class C
{
    public:
    explicit C(const string& Str){} //进制编译器自动转换
};



using namespace std;
void NewForLoop()
{
    vector<double> vec{2.3,12.2,3.0};

    for(int i:{2,3,4,5,6,7,8}) //新式for循环
        cout<< i <<endl;

    for(auto& elem : vec)
        elem*=3;

}



int main()
{
    NewForLoop();
}