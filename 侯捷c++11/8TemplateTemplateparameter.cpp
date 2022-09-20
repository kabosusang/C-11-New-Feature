#include<iostream>
#include<vector>
#include<complex>

//模板模板参数
template<typename T,
        template <class> //省略没写 应该是<class T>
        class Container
        >
class XCls
{

private:
    Container<T> c;
public:
    XCls(){
    for(long i=0;i<SIZE;++i)
        c.insert(c.end(),T());

    output_static_data(T());
    Container<T> c1(c);
    Container<T> c2(std::move(c));
    c1.swap(c2);
    }



};
