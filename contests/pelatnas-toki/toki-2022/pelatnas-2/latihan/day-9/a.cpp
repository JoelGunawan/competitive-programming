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
const int lim = 200005;
struct bit {
    int a[lim];
    bit() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        while(idx < lim) 
            a[idx] += val, idx += (idx&-idx);
    }
    int query(int idx) {
        int res = 0;
        while(idx > 0) 
            res += a[idx], idx -= (idx&-idx);
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<int, int> p;
    bit bit;
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
        if(a[i] == a[1])
            bit.update(i, 1);
    }
    //cout << endl;
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int x = bit.query(l, r), y = r - l + 1 - x;
        //cout << x << " " << y << endl;
        cout << max(x, y) + 2 * min(x, y) << endl;
        /*
        map<int, int> tmp;
        for(int j = l; j <= r; ++j)
            ++tmp[a[j]];
        multiset<int> tmp2;
        for(auto i : tmp) {
            tmp2.ins(-i.se);
        }
        ll res = 0, weight = 1;
        for(auto i : tmp2) {
            //cout << i << " ";
            res += weight * -i;
            ++weight;
        }
        //cout << endl;
        cout << res << endl;
        */
    }
    return 0;
}