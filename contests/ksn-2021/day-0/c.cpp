#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
//#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int main()
{
    fast_io();
    int q;
    cin >> q;
    int counter = 1, input;
    for(int i = 0; i < q; ++i)
    {
        cin >> input;
        if(input == counter)
            cout << "BENAR" << endl;
        else
            counter = 0, cout << "SALAH" << endl;
        ++counter;
    }
    return 0;
}