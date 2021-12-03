#include <bits/stdc++.h>
#define lim 100001
#define ll long long
#define endl "\n"
#define ins insert
#define fi first
#define se second
#define pb push_back
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll debt[n + 1];
    memset(debt, 0, sizeof(debt));
    for(int i = 0; i < m; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;
        debt[u] -= d;
        debt[v] += d;
    }
    set<pair<ll, int>> a;
    for(int i = 1; i <= n; ++i)
    {
        if(debt[i] != 0)
            a.ins({debt[i], i});
    }
    vector<pair<int, pair<int, ll>>> ans;
    while(a.size() > 0)
    {
        pair<ll, int> start = *a.begin(), last = *--a.end();
        a.erase(--a.end());
        a.erase(a.begin());
        ans.pb({start.se, {last.se, min(abs(start.fi), last.fi)}});
        if(abs(start.fi) > last.fi)
            a.ins({start.fi + last.fi, start.se});
        else if(abs(start.fi) < last.fi)
            a.ins({start.fi + last.fi, last.se});
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i].fi << " " << ans[i].se.fi << " " << ans[i].se.se << endl;
    return 0;
}