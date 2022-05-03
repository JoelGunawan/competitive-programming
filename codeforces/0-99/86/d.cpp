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
struct Query {
    int l, r, pos;
};
int sqrtn;
bool comp(Query a, Query b) {
    int ba = a.l / sqrtn, bb = b.l / sqrtn;
    return ba != bb ? ba < bb : a.r < b.r;
}
ll sqr(ll a) {
    return a * a;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n >> t;
    sqrtn = sqrt(n);
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int cnt[(int)1e6 + 1];
    memset(cnt, 0, sizeof(cnt));
    Query queries[t];
    for(int i = 0; i < t; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].pos = i;
    }
    ll ans[t];
    sort(queries, queries + t, comp);
    int l = 1, r = 0;
    ll res = 0;
    for(Query q : queries) {
        while(r < q.r) {
            ++cnt[a[++r]];
            res += a[r] * (sqr(cnt[a[r]]) - sqr(cnt[a[r]] - 1));
        }
        while(r > q.r) {
            --cnt[a[r]];
            res += a[r] * (sqr(cnt[a[r]]) - sqr(cnt[a[r]] + 1));
            --r;
        }
        while(l < q.l) {
            --cnt[a[l]];
            res += a[l] * (sqr(cnt[a[l]]) - sqr(cnt[a[l]] + 1));
            ++l;
        }
        while(l > q.l) {
            ++cnt[a[--l]];
            res += a[l] * (sqr(cnt[a[l]]) - sqr(cnt[a[l]] - 1));
        }
        ans[q.pos] = res;
    }   
    for(auto i : ans)
        cout << i << endl;
    return 0;
}