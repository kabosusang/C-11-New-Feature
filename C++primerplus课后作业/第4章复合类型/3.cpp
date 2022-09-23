#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    char F_name[20];
    char L_name[20];
    char Buff_Name[40];
    cout << "Entry your first name:" ;
    cin >> F_name;
    cout << "Entry your last name:" ;
    cin >> L_name;
    cout << "Here's the information in a single string:" ;
    strcpy(Buff_Name,F_name);
    memset(Buff_Name+(strlen(F_name)),',',1);
    strcat(Buff_Name,L_name);

    cout << Buff_Name;


    return 0;
}