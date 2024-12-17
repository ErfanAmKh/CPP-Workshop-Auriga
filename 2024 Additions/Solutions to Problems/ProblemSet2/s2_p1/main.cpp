#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

#define MATRIX_SIZE 7

int main()
{
    srand(time(0)) ;
    int A[MATRIX_SIZE][MATRIX_SIZE] ;
    for (int i=0 ; i<MATRIX_SIZE ; i++)
    {
        for (int j=0 ; j<MATRIX_SIZE ; j++)
        {
            A[i][j] = (rand()%41)-20 ;
        }
    }

    for (int i=0 ; i<MATRIX_SIZE ; i++)
    {
        for (int j=0 ; j<MATRIX_SIZE ; j++)
        {
            cout << A[i][j] << '\t' ;
        }
        cout << endl ;
    }

    cout <<"\n\n-----------------------------------\n\n" ;

    int B[MATRIX_SIZE][MATRIX_SIZE] ;
    for (int i=0 ; i<MATRIX_SIZE ; i++)
    {
        for (int j=0 ; j<MATRIX_SIZE ; j++)
        {
            int up, down, left, right;

            if ( (i-1) < 0 )
            {
                up = A[MATRIX_SIZE-1][j] ;
            }
            else
            {
                up = A[i-1][j] ;
            }

            if ( (i+1) >= MATRIX_SIZE )
            {
                down = A[0][j] ;
            }
            else
            {
                down = A[i+1][j] ;
            }

            if ( (j-1) < 0 )
            {
                left = A[i][MATRIX_SIZE-1] ;
            }
            else
            {
                left = A[i][j-1] ;
            }

            if ( (j+1) >= MATRIX_SIZE )
            {
                right = A[i][0] ;
            }
            else
            {
                right = A[i][j+1] ;
            }

            B[i][j] = up+down+left+right ;
        }
    }

    for (int i=0 ; i<MATRIX_SIZE ; i++)
    {
        for (int j=0 ; j<MATRIX_SIZE ; j++)
        {
            cout << B[i][j] << '\t' ;
        }
        cout << endl ;
    }

    return 0;
}
