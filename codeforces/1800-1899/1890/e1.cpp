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
const int lim = 2e5 + 5;
struct fenwick {
    ll a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    ll query(int idx) {
        ll ret = 0;
        while(idx) {
            ret += a[idx];
            idx -= idx&-idx;
        }
        return ret;
    }
};
fenwick bit;
void tc() {
    int n, m, k;
    cin >> n >> m >> k;
    pair<int, int> a[m + 1];
    for(int i = 1; i <= m; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    if(m == 1) {
        cout << n << endl;
        return;
    }
    int indiv[m + 1], cnt_dry = 0;
    memset(indiv, 0, sizeof(indiv));
    map<pair<int, int>, int> un;
    // fi -> obj num
    // se -> start/end
    vector<pair<bool, int>> v[n + 1];
    for(int i = 1; i <= m; ++i) {
        v[a[i].fi].pb(mp(0, i));
        v[a[i].se].pb(mp(1, i));
    }
    for(int i = 1; i <= n; ++i) {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
    }
    set<int> active;
    for(int i = 1; i <= n; ++i) {
        while(v[i].size() && v[i].back().fi == 0) {
            //cout << "INS " << i << " " << v[i].back().se << endl;
            active.ins(v[i].back().se);
            v[i].pop_back();
        }
        // do query after insert
        if(active.size() <= 2) {
            //cout << "DEBUG " << i << " " << active.size() << endl;
            if(active.size() == 0) 
                ++cnt_dry;
            else if(active.size() == 1)
                ++indiv[(*active.begin())];
            else
                ++un[mp(*active.begin(), *++active.begin())];
        }
        while(v[i].size() && v[i].back().fi == 1) {
            //cout << "ERASE " << i << " " << v[i].back().se << endl;
            active.erase(v[i].back().se);
            v[i].pop_back();
        }
    }
    vector<int> tmp;
    for(int i = 1; i <= m; ++i)
        tmp.pb(indiv[i]);
    sort(tmp.begin(), tmp.end());
    int res = tmp.back() + tmp[tmp.size() - 2];
    for(auto i : un) {
        res = max(res, i.se + indiv[i.fi.fi] + indiv[i.fi.se]);
    }
    cout << res + cnt_dry << endl;
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