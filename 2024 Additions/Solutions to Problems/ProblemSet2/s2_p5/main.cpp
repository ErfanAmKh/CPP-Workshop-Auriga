#include <iostream>
#include <vector>

using namespace std;

void concatenate(vector<int> &first, vector<int> &second) ;

int main()
{
    vector<int> a = {1, 2, 3, 4, 5} ;
    vector<int> b = {-1, 10, 20, 999} ;
    concatenate(a, b) ;
    cout << "elements: " ;
    for (int i : a)
    {
        cout << i << '\t' ;
    }
    cout << endl ;
    cout << "size: " << a.size() << endl ;
    return 0;
}

void concatenate(vector<int> &first, vector<int> &second)
{
    for (int i=0 ; i<second.size() ; i++)
    {
        first.push_back(second.at(i)) ;
    }
}
