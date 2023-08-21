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
struct segment {
    int l = 1e9, r = 0, cnt = 0;
    vector<pair<int, int>> v;
    void getLR() {
        l = 1e9, r = 0;
        cnt = 0;
        //cout << "GET " << endl;
        for(auto i : v) {
            l = min(l, i.fi);
            r = max(r, i.se);
            //cout << "DEB " << i.fi << " " << i.se << endl;
            cnt += i.se - i.fi + 1;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    pair<int, int> a[m + 1];
    for(int i = 1; i <= m; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    // small m -> coba cari aja intersect sm tiap previous segment, terus nanti tiap segment buat "type" baru aja
    vector<segment> b;
    b.push_back(segment());
    b.back().v.pb(mp(1, n));
    b.back().getLR();
    for(int i = 1; i <= m; ++i) {
        int cl = a[i].fi, cr = a[i].se;
        for(auto &seg : b) {
            // if there is some intersect between
            if(!(seg.r < cl || seg.l > cr)) {
                segment cur;
                // berarti ada intersect
                // tiap segment yg intersect keluarin aja
                // terus buat jadi segment baru
                vector<pair<int, int>> ns, os;
                for(auto p : seg.v) {
                    if(p.se < cl || p.fi > cr) {
                        os.pb(p);
                    }
                    else {
                        // there is intersect
                        int l = p.fi, r = p.se;
                        //cout << "CUR " << l << " " << r << endl;
                        if(max(l, cl + 1) < min(r, cr - 1))
                            ns.pb(mp(max(l, cl + 1), min(r, cr - 1)));
                        if(l < cl) {
                            os.pb(mp(l, cl - 1));
                        }
                        if(r > cr) {
                            os.pb(mp(cr + 1, r));
                        }
                    }
                }
                seg.v.clear();
                seg.v = os;
                seg.getLR();
                for(auto i : ns)
                    cur.v.pb(i);
                cur.getLR();
                b.pb(cur);
            }
        }
        int res = 0;
        for(auto i : b) {
            res += i.cnt / 2;
        }
        cout << res << endl;
    }
    return 0;
}