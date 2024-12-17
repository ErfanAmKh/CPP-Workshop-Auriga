#include <iostream>

using namespace std;

int main()
{
    int input, counter=0;
    double sum = 0, M=0 ;
    cin >> input ;
    while (input != -99999)
    {
        sum = M*counter + input ;
        M = sum / (++counter) ;
        cout <<"The average until now is: " << M << endl ;
        cin >> input ;
    }
    cout << "end" << endl ;
    return 0;
}
