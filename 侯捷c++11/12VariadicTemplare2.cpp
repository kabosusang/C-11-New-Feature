#include <iostream>
#include <initializer_list>
#include <vector>
#include <map>
#include <bitset>
using namespace std;
//1.小例子 
void printX()
{

}
template<typename T,typename... Types>
void printX(const T& firstArg,const Types&... args)
{
    cout<<firstArg <<":"<<sizeof...(args)/*获取包大小*/<<endl;
    printX(args...);
    
}

//4.例子4
int maximum(int n)
{
    return n;
}
template<typename... Args>
int maximum(int n,Args&... args)
{
    return max(n,maximum(args...));
}
//6.tuple继承 
template<typename Head,typename... Args>
class tuple<Head,Args...>:private:tuple<Args...>
{
    typedef tuple<Args...> inherited;


public:
    tuple(){}
    tuple(Head v,Args... vtail):m_head(v),inherited(vtail);

    //typename Head::type head() {return m_head;} 出问题的代码
    auto head()->decltype(m_head) {return m_head;}

    inherited& tail() {return *this;} //得到inherited继承的类型指针(转型动作)
protected:
    Head m_head;

};
  


int main()
{
    printX(23.23,"Hello","12345",23.23,bitset<16>(1234));
    return 0;
}
