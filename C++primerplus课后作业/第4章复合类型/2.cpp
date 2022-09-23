#include <iostream>
#include <string>
using namespace std;



int main()
{
    const int Arsize = 20;
    
    //char name[Arsize]; 旧版
    //char dessert[Arsize];
    string name;
    string dessert;

    cout << "Enter your name:\n" ;
    //cin.getline(&name,Arsize);
    getline(cin,name);
    cout << "Enter your favorite dessert:\n";
    //cin.getline(&dessert,Arsize);
     getline(cin,dessert);
    cout << "I have some delicious " << dessert ;
    cout << " for you, " << name << ".\n";
    return 0;




}
