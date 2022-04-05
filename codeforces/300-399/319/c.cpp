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
#define ld long double
using namespace std;
struct line {
    ll m, c;
    line(ll a, ll b) {
        m = a;
        c = b;
    }
    ll eval(ll x) {
        return m * x + c;
    }
    ld intersect(line a) {
        return (ld)(a.m - m) / (c - a.c);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    // select whether it's worth it to unlock a tree or not
    // find minimum cost of unlocking tree
    // fucking pelatnas problem <3
    // kita start dari awal, yang awal pasti kita unlock
    // find minimum dari cost[j] * height[i] + dp[j]
    // yang lainnya bisa di unlock nanti pake harga 0 -> don't count
    deque<line> cht = {line(b[0], 0)};
    ll dp[n];
    for(int i = 1; i < n; ++i) {
        while(cht.size() >= 2 && cht[0].eval(a[i]) >= cht[1].eval(a[i]))
            cht.pop_front();
        // calc dp[i]
        dp[i] = cht[ans].eval(a[i]);
        while(cht.size() >= 2 && cht.back().intersect(line(b[i], dp[i])) >= cht.back().intersect(cht[cht.size() - 2]))
            cht.pop_back();
        cht.pb(line(b[i], dp[i]));
    }
    cout << dp[n - 1] << endl;
    return 0;
}