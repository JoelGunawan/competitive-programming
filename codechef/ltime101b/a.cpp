#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n = 1; int power;
        cin >> power;
        for(int i = 0; i < power; ++i)
            n *= 2;
        ll tmp = 1;
        cout << tmp;
        while(tmp < n)
            cout << " " << tmp, tmp *= 2;
        cout << endl;
    }
    return 0;
}