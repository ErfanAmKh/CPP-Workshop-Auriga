#include <iostream>

#define array_size 7

using namespace std;

void update_array(int (&arr)[array_size])
{
    int a0 = arr[0] ;
    int a1 = arr[1] ;
    for (int i=0 ; i<array_size-2 ; i++)
    {
        arr[i] = arr[i] + arr[i+1] + arr[i+2] ;
    }
    arr[array_size-2] = arr[array_size-2] + arr[array_size-1] + a0 ;
    arr[array_size-1] = arr[array_size-1] + a0 + a1 ;
}

int main()
{
    int a[array_size] = {1, 2, 3, 4, 5, 6, 7} ;
    cout << "Before update: " << endl ;
    for (int i=0 ; i<array_size ; i++)
    {
        cout << a[i] << "  " ;
    }
    cout << endl ;
    update_array(a) ;
    cout << "After update: " << endl ;
    for (int i=0 ; i<array_size ; i++)
    {
        cout << a[i] << "  " ;
    }
    cout << endl ;
    return 0;
}
