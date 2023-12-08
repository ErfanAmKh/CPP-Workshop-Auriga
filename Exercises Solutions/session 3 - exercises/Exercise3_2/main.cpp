#include <iostream>

using namespace std;

int fifo_array[5] = {} ;

int main()
{
    while (true)
    {
        cout << "enter number." << endl ;
        int input ;
        cin >> input ;
        if (input == -999)
        {
            break ;
        }
        for (int i=0 ; i<4 ; i++)
        {
            fifo_array[i] = fifo_array[i+1] ;
        }
        fifo_array[4] = input ;
        int sum = 0 ;
        cout << "last 5 data: " ;
        for (int i=0 ; i<5 ; i++)
        {
            sum += fifo_array[i] ;
            cout << fifo_array[i] << "   " ;
        }
        cout << endl ;
        cout << " Average: " << sum/5.0 << endl ;
    }
    cout << "Exited." << endl ;
    return 0;
}
