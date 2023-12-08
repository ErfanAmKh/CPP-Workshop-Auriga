#include <iostream>
#include <cstdlib>
#include <time.h>
#include <limits.h>

using namespace std;

const int array_size = 15 ;

int main()
{
    srand(time(0)) ;
    int my_array[array_size] = {} ;
    for (int i=0 ; i<array_size ; i++)
    {
        my_array[i] = rand()%20 ;
    }
    cout << "My array: " << endl ;
    for (int i=0 ; i<array_size ; i++)
    {
        cout << my_array[i] << "  " ;
    }
    cout << endl ;
    int the_biggest = INT_MIN ;
    int second_biggest = INT_MIN ;
    for (int i=0 ; i<array_size ; i++)
    {
        if (my_array[i] > the_biggest)
        {
            second_biggest = the_biggest ;
            the_biggest = my_array[i] ;
        }
        else if (my_array[i] < the_biggest && my_array[i] > second_biggest)
        {
            second_biggest = my_array[i] ;
        }
    }
    cout << "Result: " << second_biggest << endl ;
    return 0;
}
