#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n == 1)
        {
            cout << 'a' << endl;
            continue;
        }
        for(int i = 0; i < n / 2; ++i)
            cout << 'a';
        cout << 'b';
        if(n & 1)
            cout << 'c';
        for(int i = 0; i < n / 2 - 1; ++i)
            cout << 'a';
        cout << endl;
    }
}