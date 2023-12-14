#include <iostream>

using namespace std;

int main()
{
    cout << "enter the string." << endl ;
    string str ;
    cin >> str ;
    bool valid_input = true ;
    for (int i=0 ; i<str.size() ; i++)
    {
        if (str[i]!='0' && str[i]!='1')
        {
            valid_input = false ;
            break ;
        }
    }
    if (!valid_input)
    {
        cout << "ERROR: invalid input." << endl ;
    }
    else
    {
        int result_counter = 1 ;
        int temp_counter = 1 ;
        char digit = str[0] ;
        for (int i=1 ; i<str.size() ; i++)
        {
            if (str[i-1] != str[i])
            {
                temp_counter = 1 ;
            }
            else
            {
                temp_counter++ ;
            }
            if (temp_counter > result_counter)
            {
                result_counter = temp_counter ;
                digit = str[i] ;
            }
        }
        cout << "length: " << result_counter << endl ;
        cout << "digit: " << digit << endl ;
    }
    return 0;
}
