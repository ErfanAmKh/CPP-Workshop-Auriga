#include <iostream>

using namespace std;

int main()
{
    long long unsigned int k, n ;
    cout << "k: " ;
    cin >> k ;
    cout << "n: " ;
    cin >> n ;
    long long unsigned int num = 1 ;
    for (int i=k+1 ; i<=n ; i++)
    {
        num *= i ;
    }
    long long unsigned int denom = 1 ;
    for (int i=1 ; i<=(n-k) ; i++)
    {
        denom *= i ;
    }
    cout << num / denom << endl ;
    return 0;
}
