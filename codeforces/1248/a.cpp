#include <iostream>

#define ll long long

using namespace std;

void solve()
{
    ll n, m, neven = 0, nodd = 0, meven = 0, modd = 0;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        if(tmp % 2 == 0) ++neven;
        else ++nodd;
    }
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int tmp;
        cin >> tmp;
        if(tmp % 2 == 0) ++meven;
        else ++modd;
    }
    cout << neven * meven + nodd * modd << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
