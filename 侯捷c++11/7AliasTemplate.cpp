#include<iostream>
#include<vector>
#include<complex>

//想象中的代码
template<typename Containent,typename T>
void test_moveable(Containent cntr,T elem)
{
Containent<T> c; //天方夜谭
for(long i=0;i<SIZE;++i)
    c.insert(c.end(),T());

    output_static_data(T());
    Container<T> c1(c);
    Container<T> c2(std::move(c));
    c1.swap(c2);

}
