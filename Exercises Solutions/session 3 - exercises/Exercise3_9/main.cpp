#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int input)
{
    if (input < 2)
    {
        return false ;
    }
    else
    {
        for (int i=sqrt(input)+1 ; i>=2 ; i--)
        {
            if (input % i == 0)
            {
                return false ;
            }
        }
        return true ;
    }
}

int main()
{
    cout << is_prime(554645) << endl ;
    return 0;
}
