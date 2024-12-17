#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a positive integer number." << endl;
    int a ;
    cin >> a ;
    while (true)
    {
        if (a == 1)
        {
            cout << "reached 1" << endl ;
            break ;
        }
        if (a%2 == 0)
        {
            a = a/2 ;
        }
        else
        {
            a = 3*a+1 ;
        }
        cout << a << endl ;
    }
    return 0;
}
