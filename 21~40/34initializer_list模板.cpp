#include <iostream>
#include<vector>
using namespace std;
//可以定义接受任意多个同一类型的函数
//std::initializer_list 可以接收某一种相同类型的 类似STL容器
//三个内部接口 begin() size() end()
void func(initializer_list<int> ls)
{
  auto it =ls.begin();
  for (;it != ls.begin();++it)
  {
    cout<<*it<<" ";
  }
    cout<<endl;
}
//QT中有很多 在类中的initializer_list
//在类中的使用
class Test
{
public:
    Test(std::initializer_list<string> list)
    {
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            cout << *it << " ";
            m_names.push_back(*it);//因为要存的类型不一样所以要遍历存入
        }
        cout << endl;
    }
private:
    vector<string> m_names;
};

int main(void)
{
    //func(1,2,3,4,5);//错误的应该用初始化列表
    func({1,2,3,4,5,6,7,8});
    return 0;
}
