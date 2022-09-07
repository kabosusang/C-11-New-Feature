#include <iostream>
#include <map>

//关于 map 和c++11对模板的优化

int main()
{
 std::map<int ,std::string> person;

//赋值 key = 0  value = "lewis01"
    person[0] = "lewis0"; //第一种方法 对map赋值 数组的形式如果key值重复会覆盖原数据
    person[0] = "lewis10";

    person.insert(std::pair<int,std::string>(1,"lewis1")); //第二种方法 pair 往map插入数据
    person.insert(std::map<int ,std::string>::value_type(2,"lewis2")); //第三种方法 用map自带value_type插入数据
    person.insert(std::map<int ,std::string>::value_type(2,"lewis3"));//key值重复插不进去数据
    //第四种  person.insert(make_pair(1,"ace"));
   

    //读取map中的内容 方法一
    //std::map<int ,std::string>::iterator it; //定义个迭代器 it
    //for(it = person.begin();it!=person.end();it++){
       // std::cout <<it->first<<":"<< it->second<<std::endl;
   // }//运用迭代器实现输出 map如果key值重复是插不进去的

    //读取map中的内容 方法二
    #if 0
    for(auto it=person.begin();it !=person.end();it++)
    {
        std::cout <<it->first<<":"<< it->second<<std::endl;
    }
    #endif

    //方法三 c++11以后新方法
    for(auto it:person){
        std::cout<<it.first<<":"<<it.second<<std::endl;
    }

    //判断数据是否插入成功
    std::pair<std::map<int,std::string>::iterator,bool> insert_pair;
    insert_pair = person.insert(std::pair<int,std::string>(3,"lewis4")); // person.insert 返回值pair<iterator, bool>
    std::cout<<"是否插入成功:"<<std::boolalpha<<insert_pair.second <<std::endl; //判断 

    //获取map中的元素
    std::map<int,std::string>::iterator it1;
    it1 = person.find(1); //1 是 key值 反汇类型是iterator对象
    if(it1!= person.end())
    {
        std::cout<<it1->second<<std::endl;
    }
    else{
        std::cout<<"not find"<<std::endl;
    }
    //删除map元素的 方法1
     std::map<int,std::string>::iterator it2;
     it2 = person.find(1);
     person.erase(it2);

    //直接通过key值删除 方法2
    person.erase(2);
    //查看容器剩余值
    for(auto it :person){
         std::cout<<"-------------------"<<std::endl;
        std::cout<<it.first<<it.second<<std::endl;
    }



    return 0;
}