#include <iostream>
#include <cstring>
#include <string>

using namespace std;


int main()
{
    string F_name;
    string L_name;
    
    cout << "Entry your first name:" ;
    cin >> F_name;
    cout << "Entry your last name:" ;
    cin >> L_name;
    
    cout << "Here's the information in a single string:" ;
    F_name.push_back(',');
    F_name+=L_name; //做了运算符重载
    cout << F_name;


    return 0;
}