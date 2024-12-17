#include <iostream>

using namespace std;

int input_array[100] = {} ;

int main()
{
    cout << "enter size of your array (<100)" << endl ;
    int s ;
    cin >> s ;
    if (s<1 || s>100)
    {
        cout << "ERROR size out of range." << endl ;
    }
    else
    {
        cout << "enter your array" << endl ;
        for (int i=0 ; i<s ; i++)
        {
            cin >> input_array[i] ;
        }
        for (int i=0 ; i<s/2 ; i++)
        {
            swap(input_array[i], input_array[s-i-1]) ;
        }
        cout << "Reversed array: " << endl ;
        for (int i=0 ; i<s ; i++)
        {
            cout << input_array[i] << "   " ;
        }
        cout << endl ;
    }
    return 0;
}
