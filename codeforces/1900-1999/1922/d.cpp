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
struct disjoint_set {
    vector<int> h, sz, l, r;
    disjoint_set(int size) {
        h = vector<int>(size + 1, -1);
        sz = vector<int>(size + 1, 1);
        for(int i = 0; i <= size + 1; ++i)
            l.pb(i), r.pb(i);
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    int size(int nd) {
        return sz[fh(nd)];
    }
    int right(int nd) {
        return r[fh(nd)];
    }
    int left(int nd) {
        return l[fh(nd)];
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            l[x] = min(l[x], l[y]);
            r[x] = max(r[x], r[y]);
            h[y] = x;
        }
        return x != y;
    }
};
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n + 2], d[n + 1];
        a[0] = a[n + 1] = 0;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        for(int i = 1; i <= n; ++i)
            cin >> d[i];
        vector<int> check[n + 2];
        for(int i = 1; i <= n; ++i) {
            check[1].pb(i);
        }
        bool erased[n + 2];
        disjoint_set dsu(n);
        memset(erased, 0, sizeof(erased));
        vector<int> erase[n + 2];
        bool done[n + 2];
        memset(done, 0, sizeof(done));
        for(int i = 1; i <= n; ++i) {
            for(auto j : erase[i]) {
                if(j < 1 || j > n)
                    continue;
                erased[j] = 1;
                if(erased[j - 1])
                    dsu.merge(j - 1, j);
                if(erased[j + 1])
                    dsu.merge(j + 1, j);
            }
            int cnt = 0;
            for(int k = 0; k < check[i].size(); ++k) {
                int j = check[i][k];
                //cout << "CHECK " << j << endl;
                if(j == n + 1 || j == 0 || done[j])
                    continue;
                done[j] = 1;
                if(erased[j]) {
                    //cout << "NEW PUSH " << dsu.right(j) << " " << dsu.left(j) << endl;
                    check[i].pb(dsu.right(j) + 1);
                    check[i].pb(dsu.left(j) - 1);
                    continue;
                }
                int at = 0;
                if(!erased[j - 1]) {
                    at += a[j - 1];
                }
                else {
                    int l = dsu.left(j - 1);
                    if(l > 0)
                        at += a[l - 1];
                }
                if(!erased[j + 1]) {
                    at += a[j + 1];
                }
                else {
                    int r = dsu.right(j + 1);
                    if(r < n + 1)
                        at += a[r + 1];
                }
                if(at > d[j]) {
                    erase[i + 1].pb(j), ++cnt;
                    check[i + 1].pb(j + 1);
                    check[i + 1].pb(j - 1);
                    //cout << "PUSH " << j - 1 << " " << j + 1 << endl;
                }
            }
            for(auto j : check[i]) {
                if(j >= 1 && j <= n)
                    done[j] = 0;
            }
            cout << cnt << " ";
        }
        cout << endl;
    }
}