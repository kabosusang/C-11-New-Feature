#include <iostream>
using namespace std;

int main()
{
    int Temp ; 
    cout<< "Please enter a Celsius value: ";
    cin >> Temp ;
    cout << Temp << " degrees Celsius is " << (Temp*1.8)+32.0 
    <<" degrees Fahrenheit";
    
    return 0;

}