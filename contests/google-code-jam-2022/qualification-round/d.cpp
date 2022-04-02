// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
const int lim = 1e5 + 5;
ll f[lim], p[lim], cnt[lim], init_cnt[lim], res;
vector<ll> a[lim];
void dfs(int nd, ll val) {
    //printf("%d %d\n", nd, val);
    if(nd == 0) {
        res += val;
        return;
    }
    --cnt[nd];
    a[nd].pb(val);
    if(cnt[nd] <= 0) {
        // propagate to next
        sort(a[nd].begin(), a[nd].end());
        for(int i = 1; i < a[nd].size(); ++i)
            res += a[nd][i];
        dfs(p[nd], max(a[nd][0], f[nd]));
    }
}

void solve() {
    res = 0;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        init_cnt[i] = f[i] = p[i] = cnt[i] = 0;
        a[i].clear();
    }
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &f[i]);
    for(int i = 1; i <= n; ++i)
        scanf("%lld", &p[i]), ++cnt[p[i]], ++init_cnt[p[i]];
    for(int i = 1; i <= n; ++i) {
        if(init_cnt[i] == 0)
            dfs(i, 0);
    }
    printf("%lld\n", res);
}

int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}