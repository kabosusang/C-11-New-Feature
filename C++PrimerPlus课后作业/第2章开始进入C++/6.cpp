#include <iostream>
using namespace std;
double Light_Year = 0;
  
double ChangeLighYe(double L_Y)
{
    return L_Y*63240;
}

int main()
{
    cout <<"Entry the number of light years: ";
    cin >> Light_Year;
    cout<<Light_Year<<" Light years = " <<ChangeLighYe(Light_Year)<<" astronomical units" ;

    return 0;
}