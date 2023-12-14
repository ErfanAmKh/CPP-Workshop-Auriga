#include <iostream>
#include <cmath>

using namespace std;

long long int my_function(int n)
{
    long long int sum = 0 ;
    for (int i=1 ; i<=n ; i++)
    {
        sum += pow(i, n-i+1) ;
    }
    return sum ;
}

int main()
{
    cout << my_function(27) ;
    return 0;
}
