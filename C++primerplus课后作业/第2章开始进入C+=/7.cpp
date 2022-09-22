#include <iostream>
using std::cout;
using std::cin;

void ComplexHM(char& h, short& m)
{
    cout << "Time : " << h <<":" << m;

}


int main()
{
    char hour_1 = 0;
    short minute_1 = 0;

    cout<<"Enter the number of hours: " ;
    cin >>hour_1;
    cout<<"Enter the number of minutes: " ;
    cin >>minute_1;

    ComplexHM(hour_1,minute_1);
    return 0;
}