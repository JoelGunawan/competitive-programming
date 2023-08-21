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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    pair<int, int> a[m + 1];
    for(int i = 1; i <= m; ++i)
        cin >> a[i].fi >> a[i].se;
    // trik: cek perubahan itu ada di mana aja
    // simpan prefix 0 and 1, cek common itu mana aja
    // nnti ada kasus khusus untuk no change
    int pref[2][n + 1];
    pref[0][0] = pref[1][0] = 0;
    for(int i = 1; i <= n; ++i) {
        pref[0][i] = pref[0][i - 1];
        pref[1][i] = pref[1][i - 1];
        ++pref[s[i] - '0'][i];
    }
    // jadi udh ada pref, cek range
    vector<pair<int, int>> v;
    for(int i = 1; i <= m; ++i) {
        if(pref[0][a[i].se] - pref[0][a[i].fi - 1] == 0 || pref[1][a[i].se] - pref[1][a[i].fi - 1] == 0) {
            v.pb(mp(0, 0));
        }
        else {
            int z = pref[0][a[i].se] - pref[0][a[i].fi - 1], o = pref[1][a[i].se] - pref[1][a[i].fi - 1];
            int l = a[i].fi, r = a[i].se, ans = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(pref[1][mid] - pref[1][a[i].fi - 1]) {
                    // ada coba cri left
                    r = mid - 1;
                    ans = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            int cl = ans;
            l = a[i].fi, r = a[i].se, ans = -1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(pref[0][a[i].se] - pref[0][mid - 1]) {
                    // ada coba cri right
                    l = mid + 1;
                    ans = mid;
                }
                else
                    r = mid - 1;
            }
            int cr = ans;
            if(cl <= cr)
                v.pb(mp(cl, cr));
            else
                v.pb(mp(0, 0));
        }
    }
    //for(auto i : v)
    //    cout << i.fi << " " << i.se << endl;
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    cout << v.size() << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}