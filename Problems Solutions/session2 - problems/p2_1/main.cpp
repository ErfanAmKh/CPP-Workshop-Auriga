#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

const int array_size = 20 ;

int main()
{
    srand(time(0)) ;
    int my_array[array_size] = {} ;
    cout << "initial state: " << endl ;
    for (int i=0 ; i<array_size ; i++)
    {
        my_array[i] = rand()%100 ;
        cout << my_array[i] << "  " ;
    }
    cout << endl ;
    for (int i=0 ; i<array_size-1 ; i++)
    {
        if (i%2==0)
        {
            if (my_array[i]>my_array[i+1])
            {
                swap(my_array[i], my_array[i+1]) ;
            }
        }
        else
        {
            if (my_array[i]<my_array[i+1])
            {
                swap(my_array[i], my_array[i+1]) ;
            }
        }
    }
    cout << "final state: " << endl ;
    for (int i=0 ; i<array_size ; i++)
    {
        cout << my_array[i] << "  " ;
    }
    return 0;
}
