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
const int lim = 1e3 + 5;
int mod = 998244353;
struct disjoint_set {
    int h[lim], sz[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            h[y] = x;
            sz[x] += sz[y];
        }
        return x != y;
    }
};
ll sub(ll a, ll b) {
    a -= b;
    a %= mod;
    a += mod;
    a %= mod;
    return a;
}
ll add(ll a, ll b) {
    return (a + b) % mod;
}
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        // make a dsu
        // nanti connectnya O(1) aja
        disjoint_set dsu;
        int c[2 * n + 1];
        for(int i = 1; i <= 2 * n; ++i)
            cin >> c[i];
        int l[n + 1], r[n + 1];
        memset(l, -1, sizeof(l));
        for(int i = 1; i <= 2 * n; ++i) {
            if(l[c[i]] == -1)
                l[c[i]] = i;
            else
                r[c[i]] = i;
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                if((l[i] < l[j] && l[j] < r[i] && r[i] < r[j]) || (l[j] < l[i] && l[i] < r[j] && r[j] < r[i]))
                    dsu.merge(i, j);
            }
        }
        //cout << "TEST" << endl;
        //cout.flush();
        // make n^2 dp
        int ccl[n + 1], ccr[n + 1];
        fill(ccl, ccl + n + 1, 1e9);
        fill(ccr, ccr + n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            ccl[dsu.fh(i)] = min(ccl[dsu.fh(i)], l[i]);
            ccr[dsu.fh(i)] = max(ccr[dsu.fh(i)], r[i]);
        }
        //cout << "HERE" << endl;
        //cout.flush();
        int maxpr[2 * n + 1], cc[2 * n + 1];
        memset(maxpr, -1, sizeof(maxpr));
        for(int i = 1; i <= n; ++i) {
            if(dsu.fh(i) == i) {
                //cout << ccl[i] << " " << ccr[i] << endl;
                //cout.flush();
                if(maxpr[ccr[i]] == -1 || maxpr[ccr[i]] > ccl[i])
                    maxpr[ccr[i]] = ccl[i], cc[ccr[i]] = i;
            }
        }
        //cout << "BEFORE DP INIT" << endl;
        //cout.flush();
        int dp[2 * n + 1];
        fill(dp, dp + 2 * n + 1, 1e9);
        dp[0] = 0;
        //cout << "BEFORE DP" << endl;
        //cout.flush();
        for(int i = 1; i <= 2 * n; ++i) {
            if(maxpr[i] != -1)
                dp[i] = min(dp[i], dp[maxpr[i] - 1] + 1);
        }
        vector<int> used;
        int cur = 2 * n;
        while(cur > 0) {
            used.pb(cc[cur]);
            cur = maxpr[cur] - 1;
        }
        ll res = 1;
        for(auto i : used) {
            //cout << "DEBUG " << i << " " << dsu.sz[dsu.fh(i)] << endl;
            res = mul(res, mul(2, dsu.sz[dsu.fh(i)]));
        }
        cout << dp[2 * n] << " " << res << endl;
        //cout.flush();
    }
    return 0;
}