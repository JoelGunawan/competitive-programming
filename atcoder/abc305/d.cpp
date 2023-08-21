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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int pref[n + 1];
    pref[0] = 0;
    for(int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1];
        if(i & 1)
            pref[i] += a[i] - a[i - 1];
    }
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int cl = ub(a + 1, a + n + 1, l) - a - 1, cr = ub(a + 1, a + n + 1, r) - a - 1;
        //cout << cl << " " << cr << endl;
        if(cl == cr) {
            if(cl % 2 == 0)
                cout << r - l << endl;
            else
                cout << 0 << endl;
            continue;
        }
        int res = pref[cr] - pref[cl + 1];
        //cout << pref[cl + 1] << " " << pref[cr] << endl;
        //cout << res << " " << cl << " " << cr << " " << a[cl] << " " << a[cr] << endl;
        // consider left
        if(cl % 2 == 0) {
            //cout << "ADD L " << a[cl] << " " << l << endl;
            res += a[cl + 1] - l;
        }
        if(cr % 2 == 0) {
            //cout << "ADD R " << a[cr] << " " << r << endl;
            res += r - a[cr];
        }
        cout << res << endl;
    }
    return 0;
}