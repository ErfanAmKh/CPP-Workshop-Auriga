#include <iostream>

using namespace std;

int main()
{
    int a, b ;
    cin >> a ;
    cin >> b ;
    int counter = 0 ;
    if (a<=b)
    {
        for (int i=a+1 ; i<b ; i++)
        {
            int input = i ;
            int digit_counter = 0 ;
            int sum = 0 ;
            while (input!=0)
            {
                digit_counter++ ;
                if (digit_counter%2 == 0)
                {
                    sum += input%10  ;
                }
                else
                {
                    sum -= input%10  ;
                }
                input /= 10 ;
            }
            if (digit_counter%2 == 1)
            {
                sum = -sum ;
            }
            if (sum == 1)
            {
                //cout << i << endl ;
                counter++ ;
            }
        }
    }
    else
    {
        for (int i=b+1 ; i<a ; i++)
        {
            int input = i ;
            int digit_counter = 0 ;
            int sum = 0 ;
            while (input!=0)
            {
                digit_counter++ ;
                if (digit_counter%2 == 0)
                {
                    sum += input%10  ;
                }
                else
                {
                    sum -= input%10  ;
                }
                input /= 10 ;
            }
            if (digit_counter%2 == 1)
            {
                sum = -sum ;
            }
            if (sum == 1)
            {
                //cout << i << endl ;
                counter++ ;
            }
        }
    }
    cout << counter ;
    return 0;
}
