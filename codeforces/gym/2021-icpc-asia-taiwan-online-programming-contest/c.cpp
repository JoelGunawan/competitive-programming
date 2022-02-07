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
const int lim = 200001;
struct bit {
    int a[lim];
    bit() {
        memset(a, 0, sizeof(a));
    }
    void update(int index, int value) {
        while(index < lim) {
            a[index] += value;
            index += (index&-index);
        }
    }
    int query(int left, int right) {
        return private_query(right) - private_query(left - 1);
    }
    int private_query(int idx) {
        int res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= (idx&-idx);
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    ll res = 0;
    bit bit;
    for(int i = 0; i < n; ++i) {
        bit.update(p[i], 1);
        res += bit.query(p[i] + 1, n);
    }
    cout << res << endl;
    return 0;
}