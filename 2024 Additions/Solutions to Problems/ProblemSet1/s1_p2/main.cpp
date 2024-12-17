#include <iostream>

using namespace std;

int main()
{
    int a ;
    cin >> a ;
    int sum=0 ;
    while (a>0)
    {
        sum += a%10 ;
        a /= 10 ;
    }
    cout << sum ;
    return 0;
}
