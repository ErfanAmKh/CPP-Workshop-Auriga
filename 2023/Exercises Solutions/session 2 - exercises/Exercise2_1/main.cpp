#include <iostream>

using namespace std;

int main()
{
    int input ;
    cout << "enter a positive integer. " << endl ;
    cin >> input ;
    if (input < 0)
    {
        cout << "ERROR" << endl ;
    }
    else
    {
        long long int result = 1 ;
        for (int i=1 ; i<=input ; i++)
        {
            result *= i ;
        }
        cout << result << endl ;
    }
    return 0;
}
