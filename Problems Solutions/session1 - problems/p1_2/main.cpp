#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Welcome to calculator program. " << endl ;
    cout << "enter first number. (for trigonometry calculation use degree not radian) " << endl ;
    double a ;
    cin >> a ;
    cout << "enter operator. (+, -, *, /, sin, cos, pow, sqrt) " << endl ;
    string op ;
    cin >> op ;
    if (op == "sin")
    {
        cout << "Result: " << sin(a*(M_PI/180.0)) << endl ;
    }
    else if (op == "cos")
    {
        cout << "Result: " << cos(a*(M_PI/180.0)) << endl ;
    }
    else if (op == "sqrt")
    {
        cout << "Result: " << sqrt(a) << endl ;
    }
    else
    {
        cout << "enter second number. " << endl ;
        double b ;
        cin >> b ;
        if (op == "pow")
        {
            cout << "Result: " << pow(a, b) << endl ;
        }
        else if (op == "+")
        {
            cout << "Result: " << a+b << endl ;
        }
        else if (op == "-")
        {
            cout << "Result: " << a-b << endl ;
        }
        else if (op == "*")
        {
            cout << "Result: " << a*b << endl ;
        }
        else if (op == "/")
        {
            cout << "Result: " << a/b << endl ;
        }
        else
        {
            cout << "ERROR: operation is not valid. " << endl ;
        }
    }
    return 0;
}
