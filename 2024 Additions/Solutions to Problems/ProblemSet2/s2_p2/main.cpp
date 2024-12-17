#include <iostream>

using namespace std;

int main()
{
    string input ;
    getline(cin, input) ;
    string output = input + input + input ;
    int o_count = 0 ;
    for (int i_count=0 ; i_count<input.length()-2 ; )
    {
        if (input[i_count] == 'b' && input[i_count+1] == 'i' && input[i_count+2] == 'g')
        {
            i_count += 3 ;
            output[o_count] = 'e' ; o_count++;
            output[o_count] = 'n' ; o_count++;
            output[o_count] = 'o' ; o_count++;
            output[o_count] = 'r' ; o_count++;
            output[o_count] = 'm' ; o_count++;
            output[o_count] = 'o' ; o_count++;
            output[o_count] = 'u' ; o_count++;
            output[o_count] = 's' ; o_count++;

        }
        else
        {
            output[o_count] = input[i_count] ;
            o_count++ ;
            i_count++ ;
        }
    }

    for (int i=0 ; i<o_count ; i++)
    {
        cout << output[i] ;
    }
    cout << endl ;
    return 0;
}
