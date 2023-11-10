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
void tc() {
    int m;
    cin >> m;
    int n[m + 1];
    ll l[m + 1], r[m + 1], sum[m + 1];
    ll total = 0;
    vector<ll> a[m + 1], c[m + 1];
    vector<ll> coord_compress;
    ll lsum = 0, rsum = 0;
    for(int i = 1; i <= m; ++i) {
        cin >> n[i] >> l[i] >> r[i];
        sum[i] = 0;
        lsum += l[i], rsum += r[i];
        for(int j = 1; j <= n[i]; ++j) {
            ll x;
            cin >> x;
            a[i].pb(x);
            coord_compress.pb(x);
        }
        for(int j = 1; j <= n[i]; ++j) {
            ll x;
            cin >> x;
            c[i].pb(x);
            total += x;
            sum[i] += x;
        }
    }
    if(rsum - lsum + 1 > coord_compress.size()) {
        cout << 0 << endl;
        return;
    }
    sort(coord_compress.begin(), coord_compress.end());
    coord_compress.resize(unique(coord_compress.begin(), coord_compress.end()) - coord_compress.begin());
    for(ll i = lsum; i <= rsum; ++i) {
        if(!binary_search(coord_compress.begin(), coord_compress.end(), i)) {
            cout << 0 << endl;
            return;
        }
    }
    //cout << "HERE" << endl;
    //cout.flush();
    for(int i = 1; i <= m; ++i) {
        for(int j = 0; j < n[i]; ++j)
            a[i][j] = lb(coord_compress.begin(), coord_compress.end(), a[i][j]) - coord_compress.begin();
    }
    int cnt = coord_compress.size();
    vector<pair<int, ll>> locs[cnt];
    for(int i = 1; i <= m; ++i) {
        for(int j = 0; j < a[i].size(); ++j) {
            locs[a[i][j]].pb(mp(i, c[i][j]));
        }
    }
    ll res = 1e18;
    //cout << lsum << " " << rsum << endl;
    for(int i = 0; i < cnt; ++i) {
        // try current coord compress idx
        if(coord_compress[i] >= lsum && coord_compress[i] <= rsum) {
            ll cur_res = 0, cur_sz = rsum;
            // there is a way to make
            for(auto j : locs[i]) {
                // fi -> idx
                // se -> count of cur elem
                // mandatory take
                cur_sz -= r[j.fi] - l[j.fi];
                ll margin = l[j.fi] - (sum[j.fi] - j.se);
                //cout << cur_sz << " " << margin << endl;
                if(margin <= 0) {
                    cur_sz += min(r[j.fi] - l[j.fi], -margin);
                }
                else {
                    cur_res += margin;
                }
            }
            //cout << "DEBUG " << coord_compress[i] << " " << cur_sz << " " << cur_res << endl;
            res = min(res, max(cur_res, coord_compress[i] - cur_sz + cur_res));
        }
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}