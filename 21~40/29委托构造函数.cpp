#include <iostream>

using namespace std;
//c++11新的构造函数 委托构造函数 继承构造函数
//委托构造函数能调用其他构造函数
class Test
{
public:
    Test() {};
    Test(int max) //重载
    {
        this->m_max = max > 0 ? max : 100;
    }

    Test(int max, int min):Test(max)  //委托构造函数 为了优化代码尽量不要写到函数体里面
    {
        //this->m_max = max > 0 ? max : 100;              // 冗余代码
        this->m_min = min > 0 && min < max ? min : 1;   
    }

    Test(int max, int min, int mid):Test(max,min)  //委托构造函数
    {
        //this->m_max = max > 0 ? max : 100;             // 冗余代码 c++11以前只能把这些给封装起来当成小函数来调用
        //this->m_min = min > 0 && min < max ? min : 1;  // 冗余代码 c++11就可以用委托构造函数
        this->m_middle = mid < max && mid > min ? mid : 50;
    }
    //注意:链状调用是可以的 切记不要构成死循环

    int m_min;
    int m_max;
    int m_middle;
};


int main(void)
{
    
    return 0;
}

