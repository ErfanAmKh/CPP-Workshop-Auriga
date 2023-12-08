#include <iostream>

using namespace std;

int main()
{
    for (int i=10 ; i<=99 ; i++)
    {
        int MSB = i/10 ;
        int LSB = i%10 ;
        if ( i % (MSB+LSB) == 0 )
        {
            cout << i << endl ;
        }
    }
    return 0;
}
