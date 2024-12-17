#include <iostream>

using namespace std;

double sum = 0 ;
int counter = 0 ;

int main()
{
    while (true)
    {
        cout << "enter number." << endl ;
        double num ;
        cin >> num ;
        if (num == -999)
        {
            break ;
        }
        sum += num ;
        counter++ ;
        cout << "Total Average: " << sum / counter << endl ;
    }
    cout << "Done." << endl ;
    return 0;
}
