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
    int n, m;
    cin >> n >> m;
    // fi.fi -> posisi
    // fi.se -> start/not (start -> 0, end -> 1)
    // se -> day
    vector<pair<pair<int, int>, int>> sweep[n + 1];
    int k;
    cin >> k;
    for(int i = 1; i <= k; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        for(int j = 0; j <= r; ++j) {
            ll delta = sqrt(1ll * r * r - 1ll * j * j);
            sweep[x - j].pb(mp(mp(y - delta, 0), i));
            sweep[x - j].pb(mp(mp(y + delta, 1), i));
            if(j != 0) {
                sweep[x + j].pb(mp(mp(y - delta, 0), i));
                sweep[x + j].pb(mp(mp(y + delta, 1), i));
            }
        }
    }
    ll res = 1ll * n * m * k;
    for(int i = 1; i <= n; ++i) {
        ll cur = 0;
        sort(sweep[i].begin(), sweep[i].end());
        //cout << "ROW " << i << endl;
        set<int> x; int last = 0;
        for(auto j : sweep[i]) {
            //cout << j.fi.fi << " " << j.fi.se << " " << j.se << endl;
            if(x.size() == 0)
                last = j.fi.fi - 1, x.ins(j.se);
            else if(j.fi.se) {
                // end
                res -= 1ll * (*--x.end()) * (j.fi.fi - last);
                cur += 1ll * (*--x.end()) * (j.fi.fi - last);
                last = j.fi.fi;
                x.erase(j.se);
            }
            else {
                // start
                if(last != j.fi.fi - 1) {
                    res -= 1ll * (*--x.end()) * (j.fi.fi - last - 1);
                    cur += 1ll * (*--x.end()) * (j.fi.fi - last - 1);
                    last = j.fi.fi - 1;
                }
                x.ins(j.se);
            }
        }
        //cout << cur << endl;;
    }
    cout << res << endl;
    return 0;
}