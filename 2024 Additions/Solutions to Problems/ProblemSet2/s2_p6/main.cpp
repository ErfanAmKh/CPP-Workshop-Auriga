#include <iostream>

using namespace std;

void kron(int m, int n, int *a, int p, int q, int *b, int k, int l, int *result) ;

int main()
{
    int A[2][3] = { {1, -4, 7}, {-2, 3, 3} } ;
    int B[4][4] = { {8, -9, -6, 5}, {1, -3, -4, 7}, {2, 8, -8, -3}, {1, 2, -5, -1} } ;
    int C[8][12] = {0} ;
    kron(2, 3, (int *)A, 4, 4, (int *)B, 8, 12, (int *)C) ;
    for (int i=0 ; i<8 ; i++)
    {
        for (int j=0 ; j<12 ; j++)
        {
            cout << C[i][j] << '\t' ;
        }
        cout << endl ;
    }
    return 0;
}

void kron(int m, int n, int *a, int p, int q, int *b, int k, int l, int *result)
{
    if (k != m*p)
    {
        cout << "Dimension Error." << endl ;
        return ;
    }
    if (l != n*q)
    {
        cout << "Dimension Error." << endl ;
        return ;
    }
    for (int i=0 ; i<k ; i++)
    {
        for (int j=0 ; j<l ; j++)
        {
            int b_part_i = i%p ;
            int b_part_j = j%q ;
            int a_part_i = i/p ;
            int a_part_j = j/q ;
            *((result+i*l) + j) = (*((a+a_part_i*n) + a_part_j)) * (*((b+b_part_i*q) + b_part_j)) ;
        }
    }
}
