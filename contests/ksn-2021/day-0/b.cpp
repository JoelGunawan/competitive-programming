#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int main()
{
    fast_io();
    int q, k;
    cin >> q >> k;
    vector<int> a;
    for(int i = 0; i < q; ++i)
    {
        int in;
        cin >> in;
        for(int j = 0; j < 10000; ++j)
            in += 1;
        a.pb(in);
    }
    for(int i = 0; i < q; ++i)
    {
        int c;
        c = a[i] - 10000;
        bool ans = 1;
        int res = 0;
        for(int j = 0; j < 30; ++j)
            if(((1 << j) & k) && !((1 << j) & c))
            {
                ans = 0;
                break;
            }         
        if(ans)
            cout << c << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}