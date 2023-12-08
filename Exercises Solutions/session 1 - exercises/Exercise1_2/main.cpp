#include <iostream>

using namespace std;

int main()
{
    cout << "enter the price (Toman)" << endl ;
    int input ;
    cin >> input ;
    double outDollar = input / 50000 ;
    cout << "The price in dollar is: " << outDollar << endl ;
    return 0;
}
