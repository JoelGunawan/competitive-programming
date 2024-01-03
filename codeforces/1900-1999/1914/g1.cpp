// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
        if(dsu.fh(c[1]) == dsu.fh(c[2 * n])) {
            cout << 1 << " ";
            int cnt = 0;
            for(int i = 1; i <= n; ++i) {
                if(dsu.fh(i) == dsu.fh(c[1]))
                    ++cnt;
            }           
            cout << 2 * cnt << endl;
        }
        else {
            cout << 2 << " ";
            int left = 0, right = 0;
            for(int i = 1; i <= n; ++i) {
                if(dsu.fh(i) == dsu.fh(c[1]))
                    ++left;
                if(dsu.fh(i) == dsu.fh(c[2 * n]))
                    ++right;
            }
            cout << 4ll * left * right << endl;
        }
    }
    return 0;
}