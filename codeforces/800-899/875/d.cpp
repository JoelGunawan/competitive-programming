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
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // memo tiap bit on itu ada dimana aja
    // terus nnti cari di suatu range tertentu angka x ada berapa kemunculan
    // buat mapping buat simpan vector occurrence doang
    // i miss her :(
    vector<int> loc[30];
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 30; ++j) {
            if((1 << j) & a[i])
                loc[j].pb(i);
        }
    }
    vector<int> mapping;
    for(int i = 1; i <= n; ++i)
        mapping.pb(a[i]);
    sort(mapping.begin(), mapping.end());
    mapping.resize(unique(mapping.begin(), mapping.end()) - mapping.begin());
    vector<int> lc[mapping.size()];
    for(int i = 1; i <= n; ++i)
        lc[lb(mapping.begin(), mapping.end(), a[i]) - mapping.begin()].pb(i);
    ll res = 0;
    int memo[30];
    memset(memo, 0, sizeof(memo));
    for(int i = 1; i <= n; ++i) {
        // cari first occurence of everything ke belakang dmn
        // nanti klo udh change, kita ganti search criterianya
        int dis = 0;
        vector<pair<int, int>> v;
        // fi -> tempat, se -> bit ke berapa
        for(int j = 0; j < 30; ++j) {
            // klo misal j ada di belakang, memo index itu sebagai index ganti
            if((1 << j) & a[i])
                memo[j] = i;
            if(memo[j])
                v.pb(mp(memo[j], j));
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int r = i;
        if(v.size())
            r = v.front().fi;
        for(int j = 0; j < v.size(); ++j) {
            if(j != 0 && v[j].fi != v[j - 1].fi) {
                // calculate dr v[j].fi + 1 ke r
                // calculate yg tidak sama dengan dis ada berapa
                // query(v[j].fi + 1, r, dis)
                int tot = r - v[j].fi;
                if(binary_search(mapping.begin(), mapping.end(), dis)) {
                    int idx = lb(mapping.begin(), mapping.end(), dis) - mapping.begin();
                    if(ub(lc[idx].begin(), lc[idx].end(), i) != lc[idx].begin())
                        tot = max(0, r - max(*--ub(lc[idx].begin(), lc[idx].end(), i), v[j].fi));
                }
                res += tot;
                r = v[j].fi;
            }
            dis |= 1 << v[j].se;
        }
        int tot = r;
        if(binary_search(mapping.begin(), mapping.end(), dis)) {
            int idx = lb(mapping.begin(), mapping.end(), dis) - mapping.begin();
            if(ub(lc[idx].begin(), lc[idx].end(), i) != lc[idx].begin())
                tot = max(0, r - max(0, *--ub(lc[idx].begin(), lc[idx].end(), i)));
        }
        res += tot;
    }
    cout << res << endl;
    return 0;
}