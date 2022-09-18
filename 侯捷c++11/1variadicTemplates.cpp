#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

void printX()
{

}
template<typename T, typename... Types> //主要用来递归
void printX(const T& firstArg, const Types&... args)
{
     cout << "调用了特化模板" << endl;
    cout<< firstArg <<endl; //printf first argument
    printX(args...);    //call print() for remaining arguments
} // sizeof...(args) 算出这个pack有多少个
template<typename...Types>
void printX(const Types&... args)
{
     cout << "调用了泛化模板" << endl;
    size_t Seed = 0;
    printX(Seed,args...);
  
}

int main()
{
    printX(23.23,"Hello","12345",23.23,bitset<16>(1234));
    return 0;
}