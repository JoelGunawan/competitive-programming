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
const int lim = 1e6 + 5;
struct disjoint_set {
    int h[lim], sz[lim];
    disjoint_set() {
        fill(sz, sz + lim, 1);
        memset(h, -1, sizeof(h));
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }

    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    pair<int, int> a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i].fi >> a[i].se;
    disjoint_set dsu;
    // sort by smallest r but have a set sorted by l
    set<pair<int, int>> s;
    for(int i = 1; i <= n; ++i)
        s.ins(a[i]), swap(a[i].fi, a[i].se);
    sort(a + 1, a + n + 1);
    bool valid = 1;
    for(int i = 1; i <= n; ++i) {
        // sorted by smallest R
        // s is sorted by smallest L
        int l = a[i].se, r = a[i].fi;
        s.erase(mp(l, r));
        while(s.lb(mp(l, 0)) != s.end() && (*s.lb(mp(l, 0))).fi <= r) {
            if(!dsu.merge(a[i].se, (*s.lb(mp(l, 0))).fi))   
                valid = 0;
            //cout << "MERGE " << a[i].se << " " << a[i].fi << " " << (*s.lb(mp(l, 0))).fi << " " << (*s.lb(mp(l, 0))).se << endl;
            l = (*s.lb(mp(l, 0))).fi + 1;
        }
        if(!valid)
            break;
    }
    cout << (valid && dsu.sz[dsu.fh(a[1].se)] == n ? "YES" : "NO") << endl; 
    return 0;
}