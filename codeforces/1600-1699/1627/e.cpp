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
    // travel between floors -> only ladders
    // travel within floors -> manual
    // for each floor with ladders and stuff, find intersection with previous
    // jadi semacam cht style, tp g terlalu kyk cht
    int n, m, k;
    cin >> n >> m >> k;
    // fi -> index, se -> cost
    vector<pair<int, ll>> floor[n + 1];
    int pen[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> pen[i];
    // v -> outgoing, floor -> incoming
    // fi.fi -> b, fi.se -> h, se.fi -> c, se.se -> d
    vector<pair<pair<int, int>, pair<int, int>>> v[n + 1];
    for(int i = 1; i <= k; ++i) {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;
        v[a].pb(mp(mp(b, h), mp(c, d)));
    }
    for(int i = 1; i <= n; ++i)
        sort(v[i].begin(), v[i].end());
    floor[1].pb(mp(1, 0));
    // nanti di proses supaya di streamline, terus nnti di binser, cari yg sesuai
    // technically bs monotonic stack algo tp terlalu ribet (dan logn ga terlalu ngaruh)
    for(int i = 1; i <= n; ++i) {
        // proses floor dlu
        sort(floor[i].begin(), floor[i].end());
        vector<pair<int, ll>> cur;
        for(auto j : floor[i]) {
            if(cur.empty())
                cur.pb(j);
            else {
                // if cost di cur pake sblum lebih bagus drpd cost cur
                if(1ll * pen[i] * (j.fi - cur.back().fi) + cur.back().se <= j.se) {
                    // ga usah push back
                }
                else {
                    // pasti push back, terus while dia overwrite kirinya, pop
                    while(cur.size() && 1ll * pen[i] * (j.fi - cur.back().fi) + j.se <= cur.back().se)
                        cur.pop_back();
                    cur.pb(j);
                }
            }
        }
        floor[i] = cur;
        if(floor[i].size()) {
            for(auto j : v[i]) {
                // ambil dr floor
                // binser dr floor cost paling optimal, kalo kosong, ignore
                int l = 0, r = floor[i].size() - 1;
                while(l < r) {
                    int mid = (l + r) / 2;
                    // cek mid sm mid + 1, lebih optimal ambil mana
                    // isi v
                    // fi.fi -> b (index), fi.se -> h (health increase), se.fi -> c (target floor), se.se -> d (target index)
                    if(1ll * pen[i] * abs(j.fi.fi - floor[i][mid].fi) + floor[i][mid].se 
                    <= 1ll * pen[i] * abs(j.fi.fi - floor[i][mid + 1].fi) + floor[i][mid + 1].se)
                        r = mid;
                    else
                        l = mid + 1;
                }
                floor[j.se.fi].pb(mp(j.se.se, 1ll * pen[i] * abs(j.fi.fi - floor[i][l].fi) + floor[i][l].se - j.fi.se));
            }
        }
    }
    if(floor[n].size()) {
        // pakai back nya
        cout << floor[n].back().se + 1ll * (m - floor[n].back().fi) * pen[n] << endl;
    }
    else {
        cout << "NO ESCAPE" << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}