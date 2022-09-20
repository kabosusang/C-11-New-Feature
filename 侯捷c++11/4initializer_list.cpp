#include <iostream>
#include <initializer_list>
#include <vector>

void print(const std::initializer_list<int> vals)
{
    for( auto p = vals.begin(); p!=vals.end();p++ )
        std::cout<<*p<<"\n";
    for(auto& item : vals)
        std::cout<<item<<"\n";
}


int main()
{
   
    print({1,3,4,5,7,8,123,88});

}