#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int input)
{
    if (input < 2)
    {
        return false ;
    }
    else if (input == 2)
    {
        return true ;
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

void func(int n)
{
    bool prime_num = is_prime(n) ;
    if (prime_num)
    {
        cout << "The number is PRIME." << endl ;
    }
    else
    {
        cout << "Prime divisors: " << endl ;
        for (int i=2 ; i<(n/2)+1 ; i++)
        {
            if (n%i == 0 && is_prime(i))
            {
                cout << i << "  " ;
            }
        }
        cout << endl ;
    }
}

int main()
{
    func(127) ;
    return 0;
}
