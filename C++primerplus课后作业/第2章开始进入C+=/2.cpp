#include <iostream>
using namespace std;

long INlongDistance(long distance)
{
    return distance*220;
}


int main()
{
    long I_distance = 0;
    cin >> I_distance;
    cout << INlongDistance(I_distance) << endl;
    cin.get();
    return 0;
}