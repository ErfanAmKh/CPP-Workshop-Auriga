#include <iostream>
#include <cstdlib>
#include <time.h>

#define array_size 25

using namespace std;

void print_array(int arr[], int s)
{
    for (int i=0 ; i<s ; i++)
    {
        cout << arr[i] << "  " ;
    }
    cout << endl ;
}

void assign_random(int (&arr)[array_size])
{
    srand(time(0)) ;
    for (int i=0 ; i<array_size ; i++)
    {
        arr[i] = rand() % 100 ;
    }
}

int main()
{
    int a[array_size] = {} ;
    assign_random(a) ;
    print_array(a, array_size) ;
    return 0;
}
