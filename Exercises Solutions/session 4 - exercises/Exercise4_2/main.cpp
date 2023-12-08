#include <iostream>

using namespace std;

int main()
{
    cout << "enter size of arrays." << endl ;
    int s ;
    cin >> s ;
    int a[s] = {} ;
    int b[s] = {} ;
    cout << "enter first array: " << endl ;
    for (int i=0 ; i<s ; i++)
    {
        cin >> a[i] ;
    }
    cout << "enter second array: " << endl ;
    for (int i=0 ; i<s ; i++)
    {
        cin >> b[i] ;
    }
    bool they_are_similar = false ;
    int counter = s ;
    for (int i=0 ; i<s ; i++)
    {
        for (int j=0 ; j<counter ; j++)
        {
            if (a[i] == b[j])
            {
                counter-- ;
                swap(b[j], b[counter]) ;
                break ;
            }
        }
    }
    if (counter == 0)
    {
        they_are_similar = true ;
        cout << "they are similar." << endl ;
    }
    else
    {
        cout << "they are not similar." << endl ;
    }
    return 0;
}
