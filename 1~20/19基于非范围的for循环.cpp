#include <iostream>
#include <vector>

using namespace std;

//新的for循环
/*  格式:
for (declaration : expression)  //只会访问一次
{
    // 循环体
}
declaration 表示遍历声明，在遍历过程中，当前被遍历到的元素会被存储到声明的变量中。
expression 是要遍历的对象，它可以是表达式、容器、数组、初始化列表等。
*/
int main()
{
    vector<int> vt{1,2,3,4,5,6,7,8,9};
 
    for ( auto it = vt.begin(); it!=vt.end(); it++)
    {
        cout<<*it<<" ";
        /* code */
    }
    cout<<endl;
    for(auto &item : vt) //这是一个拷贝过程vt会拷贝到item 为了提升效率 把item改成item&
    {
        cout<<item++<<" ";
    }
    cout<<endl;
     for(const auto &item : vt)  //改成只读会提升效率
    {
        cout<<item<<" ";
    }
    

    return 0;
}
