#include <iostream>

using namespace std;

int main()
{
    double input_grade ;
    cout << "enter your grade out of 20. " << endl ;
    cin >> input_grade ;
    string output_grade ;
    if (input_grade>=0 && input_grade<10)
    {
        output_grade = "F" ;
    }
    else if (input_grade>=10 && input_grade<12)
    {
        output_grade = "D" ;
    }
    else if (input_grade>=12 && input_grade<14)
    {
        output_grade = "C" ;
    }
    else if (input_grade>=14 && input_grade<17)
    {
        output_grade = "B" ;
    }
    else if (input_grade>=17 && input_grade<=20)
    {
        output_grade = "A" ;
    }
    else
    {
        output_grade = "ERROR! your grade is out of range." ;
    }
    cout << output_grade << endl ;
    return 0;
}
