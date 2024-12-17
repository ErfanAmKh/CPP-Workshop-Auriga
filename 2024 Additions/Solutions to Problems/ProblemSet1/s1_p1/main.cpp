#include <iostream>

using namespace std;

int main()
{
    cout << "What is the exchange rate of the dollar today? (in Toman)" << endl ;
    double exchange_rate ;
    cin >> exchange_rate ;
    cout << "Now enter a price: ($)" ;
    double dollar ;
    cin >> dollar ;
    cout << "The price in Toman is: " << dollar * exchange_rate << endl ;
    return 0;
}
