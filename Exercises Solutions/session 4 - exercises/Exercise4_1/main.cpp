#include <iostream>

using namespace std;

/*
    columns:m
    ........
    ........
    ........    rows:n
    ........
    ........
*/

int main()
{
    cout << "enter number of rows: " << endl ;
    int n ;
    cin >> n ;
    cout << "enter number of columns: " << endl ;
    int m ;
    cin >> m ;
    int matrix[n][m] ;
    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<m ; j++)
        {
            cin >> matrix[i][j] ;
        }
    }
    int transposed_matrix[m][n] ;
    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            transposed_matrix[i][j] = matrix[j][i] ;
        }
    }
    cout << "\n\n Result: \n" ;
    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            cout << transposed_matrix[i][j] << "  " ;
        }
        cout << endl ;
    }
    return 0;
}
