#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    ll dp[n + 1]; memset(dp, 0, sizeof(dp));
    // first is start, second is end, third is price
    pair<int, pair<int, int>> paket[m];
    for(int i = 0; i < m; ++i)
        cin >> paket[i].fi >> paket[i].se.fi >> paket[i].se.se;
    sort(paket, paket + m);
    // first is incurred price, second is start, third is end
    priority_queue<pair<ll, pair<int, int>>> pq;
    int paket_index = 0;
    for(int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + s;
        while(pq.size() > 0 && pq.top().se.se < i)
            pq.pop();
        while(paket_index < m && paket[paket_index].fi == i) 
            pq.push(mp(-(dp[i - 1] + paket[paket_index].se.se), mp(paket[paket_index].fi, paket[paket_index].se.fi))), paket_index++;
        if(pq.size() > 0)
            dp[i] = min(dp[i], -pq.top().fi);
    }
    cout << dp[n] << endl;
    return 0;
}