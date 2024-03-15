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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i] = mp(x, y);
    }
    // pertama -> tempat/posisi/waktu
    // kedua -> tipe operasi
    pair<int, bool> b[2 * n];
    for(int i = 0; i < n; ++i) {
        b[2 * i] = mp(a[i].fi, 1);
        b[2 * i + 1] = mp(a[i].se, 0);
    }
    sort(b, b + 2 * n);
    int res_cnt = 0, res_year, cur_cnt = 0;
    for(int i = 0; i < 2 * n; ++i) {
        if(b[i].se)
            ++cur_cnt;
        else
            --cur_cnt;
        if(cur_cnt > res_cnt) {
            res_cnt = cur_cnt, res_year = b[i].fi;
        }
    }
    cout << res_year << " " << res_cnt << endl;
    return 0;
}