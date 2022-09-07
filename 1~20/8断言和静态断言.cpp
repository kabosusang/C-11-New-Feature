#include <iostream>
//#include<cassert> //断言

using namespace std;
#if 0
char * createArray(int size)
{
    assert(size > 0); //不满足条件就会产生错误
    char* array = new char[size];
    return array;
}
#endif
//静态断言 必须保证是常量表达式 不需要头文件

int main()
{
    
    //char* bu = createArray(10);
    static_assert(sizeof(char*)==8,"当前操作系统不是64位"); //常量表达式所以在程序执行前就能判断
    //后面是不满足后的提示
    cout<<"Hello,World"<<endl;
    return 0;
}
