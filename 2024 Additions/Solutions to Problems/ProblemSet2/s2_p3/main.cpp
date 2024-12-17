#include <iostream>
#include <time.h>
#include <cstdlib>

#define ARRAY_SIZE 10

using namespace std;

void sort_array(int input[], int s) ;

int main()
{
    srand(time(0)) ;
    int a[ARRAY_SIZE] ;
    for (int i=0 ; i<ARRAY_SIZE ; i++)
    {
        a[i] = rand()%20 ;
    }
    for (int i=0 ; i<ARRAY_SIZE ; i++)
    {
        cout << a[i] << '\t' ;
    }
    cout << endl << endl ;

    sort_array(a, ARRAY_SIZE) ;

    for (int i=0 ; i<ARRAY_SIZE ; i++)
    {
        cout << a[i] << '\t' ;
    }
    return 0;
}

void sort_array(int input[], int s)
{
    for (int i=0 ; i<s ; i++)
    {
        int min_val = input[i] ;
        int min_index = i ;
        for (int j=i+1 ; j<s ; j++)
        {
            if (input[j] < min_val)
            {
                min_val = input[j] ;
                min_index = j ;
            }
        }
        swap(input[i], input[min_index]) ;
    }
}
