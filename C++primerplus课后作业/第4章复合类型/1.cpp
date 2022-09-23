#include <iostream> 
using std::cout;
using std::cin;
using std::string;
using std::endl;
int main()
{   
    char F_name[20];
    char L_name[20];
    char Grade;
    char age;

    cout << "What is your first name? ";
    cin.get(F_name,20);
    cin.get(); //处理掉输入流里的Entry
    cout << "What is your last name? ";
    cin.get(L_name,20);
    cin.get(); //处理掉输入流里的Entry
    cout << "What letter grade do you deserve> ";
    cin >> Grade;
    cin.get();
    cout << "What is your age ? ";
    cin >> age;
    cin.get();
    cout << "name: " << L_name <<"," << F_name << endl;
    cout << "Grade: " << Grade << endl;
    cout << "age: " << age << endl;

    return 0;



}