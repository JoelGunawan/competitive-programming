#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC optimize("Ofast")
using namespace std;
void solve()
{
    ll n, m, in, cur = 0;
    cin >> n >> m;
    // first is the required distance, the next is the distance it will reach
    pair<ll, ll> a[n];
    ll dist;
    for(int i = 0; i < n; ++i)
    {
        cin >> in;
        if(i == 0)
            dist = in, cur += in, a[i] = {cur, cur + 2 * in * m};
        else
            cur += 2 * in, a[i] = {cur, cur + 2 * in * m};

    }
    int counter = 0, currentindex = 0;
    while(dist < a[n - 1].first)
    {
        ll maxdist = -1;
        while(currentindex < n && a[currentindex].first <= dist)
            maxdist = max(maxdist, a[currentindex++].second);
        if(maxdist == -1)
        {
            cout << -1 << endl;
            return;
        }
        else
            dist = maxdist;
        ++counter;
    }
    cout << counter << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}