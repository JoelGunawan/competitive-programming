#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n > 0)
        cout << "positif";
    else if(n == 0)
        cout << "nol";
    else
        cout << "negatif";
    cout << endl;
    return 0;
}