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
const int lim = 1e5 + 5;
struct bit {
    ll a[lim];
    bit() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += (idx&-idx);
        }
    }
    ll query(int idx) {
        ll res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= (idx&-idx);
        }
        return res;
    }
    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    bit a, b;
    int a1[lim], b1[lim];
    memset(a1, 0, sizeof(a1));
    memset(b1, 0, sizeof(b1));
    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, y;
            cin >> x >> y;
            ++a1[x];
            ++b1[y];
            if(a1[x] == 1)
                a.update(x, 1);
            if(b1[y] == 1)
                b.update(y, 1);
        }
        else if(t == 2) {
            int x, y;
            cin >> x >> y;
            --a1[x];
            --b1[y];
            if(a1[x] == 0)
                a.update(x, -1);
            if(b1[y] == 0)
                b.update(y, -1);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if(a.query(x1, x2) == x2 - x1 + 1 || b.query(y1, y2) == y2 - y1 + 1)
                cout << "Yes" << endl;
            else    
                cout << "No" << endl;
        }
    }
    return 0;
}