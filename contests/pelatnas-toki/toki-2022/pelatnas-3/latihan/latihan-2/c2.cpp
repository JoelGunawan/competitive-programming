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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    multiset<pair<int, pair<int, int>>> x, y, z;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        x.ins(mp(a, mp(b, c)));
        y.ins(mp(b, mp(a, c)));
        z.ins(mp(c, mp(a, b)));
    }
    bool changed = 1;
    while(x.size() && y.size() && z.size() && changed) {
        changed = 0;
        while(x.size() && ((*--x.end()).se.fi >= (*--y.end()).fi || (*--x.end()).se.se >= (*--z.end()).fi))
            x.erase(--x.end()), changed = 1;
        if(!x.size())
            break;
        while(y.size() && ((*--y.end()).se.fi >= (*--x.end()).fi || (*--y.end()).se.se >= (*--z.end()).fi))
            y.erase(--y.end()), changed = 1;
        if(!y.size())
            break;
        while(z.size() && ((*--z.end()).se.fi >= (*--x.end()).fi || (*--z.end()).se.se >= (*--y.end()).fi))
            z.erase(--z.end()), changed = 1;
    }
    if(!x.size() || !y.size() || !z.size())
        cout << -1 << endl;
    else
        cout << (*--x.end()).fi + (*--y.end()).fi + (*--z.end()).fi << endl;
    return 0;
}