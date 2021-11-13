#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    int counter = 0, number;
    for(int i = 0; i < q; ++i)
    {
        cin >> number;
        ++counter;
        if(number == counter)
            cout << "BENAR" << endl;
        else
            cout << "SALAH" << endl, counter = 0;
    }
    return 0;
}