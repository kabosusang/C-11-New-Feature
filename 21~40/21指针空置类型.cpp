#include <iostream>

using namespace std;
void func(char *p)
{
    cout<<"char* func"<<endl;
}

void func(int p)
{
    cout<<"int func"<<endl;
}

int main(void)
{
    //因为nullptr会像C语言里面void* 一样会隐式转换
    //某些情况下 c++会产生歧义
    int* ptr1 =nullptr;
    char* ptr2 =nullptr;
    double* ptr3 =NULL;
    void* ptr4 =NULL;

    int* ptr5 = (int* )ptr4; //c++不允许隐式转换
    func(10);
    func(nullptr);
    //func(NULL); //g++会报错 C++里面NULL不是void * 而是数值0
    
    return 0;
}
