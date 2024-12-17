#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0)) ;
    // Create Dynamic Memory
    int *p = new int[5] ;

    // Fill the array with random numbers
    for (int i=0 ; i<5 ; i++)
    {
        *(p+i) = rand()%30 ;
    }

    // Print array
    for (int i=0 ; i<5 ; i++)
    {
        cout << *(p+i) << '\t' ;
    }
    cout << endl ;

    // Find & Save the minimum number
    int min_number = *p ;
    for (int i=1 ; i<5 ; i++)
    {
        if (*(p+i) < min_number)
        {
            min_number = *(p+i) ;
        }
    }

    // Free the Dynamic Memory
    delete [] p ;

    // Print result
    cout << min_number << endl ;
    return 0;
}
