#include <iostream>

using namespace std;

int main()
{
    cout << "enter first number." << endl ;
    int a ;
    cin >> a ;
    cout << "enter second number." << endl ;
    int b ;
    cin >> b ;
    for (int i=1 ; i<=min(a, b) ; i++)
    {
        if (a%i == 0 && b%i == 0)
        {
            cout << i << endl ;
        }
    }
    return 0;
}
