// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
int fact[2 * (int)1e5 + 1];
int mod = 1e9 + 7;
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = mul(tmp, tmp);
        return b & 1 ? mul(tmp, a) : tmp;
    }
}
ll inv(ll a) {
    return powmod(a, mod - 2);
}
ll c(ll a, ll b) {
    return mul(fact[a], mul(inv(fact[b]), inv(fact[a - b])));
}
void tc() {
    int n, m;
    cin >> n >> m;
    int cnt[31]; memset(cnt, 0, sizeof(cnt));
    pair<int, pair<bool, int>> sweep[2 * m];
    for(int i = 0; i < m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        sweep[2 * i] = mp(l, mp(0, x));
        sweep[2 * i + 1] = mp(r, mp(1, x));
    }
    sort(sweep, sweep + 2 * m);
    int arr[31];
    memset(arr, 0, sizeof(arr));
    int idx = 0;
    for(int i = 1; i <= n; ++i) {
        while(idx < 2 * m && sweep[idx].fi == i && !sweep[idx].se.fi) {
            for(int j = 0; j < 31; ++j) {
                if(!(sweep[idx].se.se & (1 << j)))
                    ++cnt[j];
            }
            ++idx;
        }
        int tmp = 0;
        for(int j = 0; j < 31; ++j) {
            if(cnt[j] == 0)
                ++arr[j];
        }
        while(idx < 2 * m && sweep[idx].fi == i && sweep[idx].se.fi) {
            for(int j = 0; j < 31; ++j) {
                if(!(sweep[idx].se.se & (1 << j)))
                    --cnt[j];
            }
            ++idx;
        }
    }
    ll res = 0;
    for(int i = 0; i < 31; ++i) {
        if(arr[i] > 0)
            res = (res + mul(mul(powmod(2, arr[i] - 1), powmod(2, n - arr[i])), 1 << i)) % mod;
    } 
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    fact[0] = 1;
    for(int i = 1; i <= 2 * 1e5; ++i) 
        fact[i] = (1ll * fact[i - 1] * i) % mod;
    while(t--) {
        tc();
    }
    return 0;
}