#include <iostream>

using namespace std;

double find_max(double a, double b, double c)
{
    if (a>=b && a>=c)
    {
        return a ;
    }
    else if (b>=c)
    {
        return b ;
    }
    else
    {
        return c ;
    }
}

int main()
{
    cout << find_max(15.5, 17.4, 15.5) << endl ;
    return 0;
}
