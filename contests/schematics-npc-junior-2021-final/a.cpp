#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//#pragma GCC optimize("Ofast")
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> res;
    for(int i = 1; i <= 13; ++i)
        if(n % i == 0)
            res.pb(i);
    // find whether it is possible to make a sum of 13 from the elements of res
    bool ans = 0;
    vector<vector<int>> a;
    for(int i = 1; i < (1 << res.size()); ++i)
    {
        int cur = 0;
        for(int j = 0; j < res.size(); ++j)
            if(i & (1 << j))
                cur += res[j];
        if(cur == 13)
        {
            vector<int> tmp;
            for(int j = 0; j < res.size(); ++j)
                if(i & (1 << j))
                    tmp.pb(res[j]);
            a.pb(tmp);
        }
    }
    sort(a.begin(), a.end());
    if(a.size() == 0)
        cout << -1 << endl;
    else
    {
        for(int i = 0; i < a[0].size(); ++i)
            cout << a[0][i] << " ";
        cout << endl;
    }
}
int main()
{
    //fast_io();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}