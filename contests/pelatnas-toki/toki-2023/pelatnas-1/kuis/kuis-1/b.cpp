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
    // sorting greedy
    // choose yang paling kecil
    // choose 2 -> kasus khusus dimana 1 bisa ditukar 2?
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    // diff, indexes
    vector<pair<int, vector<int>>> d;
    for(int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];
    int p;
    cin >> p;
    pair<int, int> c[p + 1];
    for(int i = 1; i <= p; ++i)
        cin >> c[i].fi >> c[i].se;
    bool used[n + 1];
    memset(used, 0, sizeof(used));
    for(int i = 1; i <= p; ++i) {
        vector<int> tmp = {c[i].fi, c[i].se};
        d.pb(mp(a[c[i].fi] + a[c[i].se] - (b[c[i].fi] + b[c[i].se]), tmp));
        used[c[i].fi] = 1, used[c[i].se] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        if(!used[i]) {
            vector<int> tmp = {i};
            d.pb(mp(2 * (a[i] - b[i]), tmp));
        }
    }
    sort(d.begin(), d.end());
    int cur = 0, target = n / 2;
    ll res = 0;
    bool calc[n + 1];
    memset(calc, 0, sizeof(calc));
    for(int i = 0; i < d.size() && cur < target; ++i) {
        if(d[i].se.size() + cur > target) {
            // coba cari prev occur of one and cur occur of one
            int lastone = -1, nxtone = -1;
            for(int j = i - 1; j >= 0; --j) {
                if(d[j].se.size() == 1) {
                    lastone = j;
                    break;
                }
            }
            for(int j = i + 1; j < d.size(); ++j) {
                if(d[j].se.size() == 1) {
                    nxtone = j;
                    break;
                }
            }
            // kalo ada, coba bandingkan lebih optimal banding 2 or not
            if(nxtone == -1) {
                // pasti hapus lastone, sekarang dipake
                res -= a[d[lastone].se.front()];
                calc[d[lastone].se.front()] = 0;
                for(auto j : d[i].se)
                    res += a[j], calc[j] = 1;
                
            }
            else if(lastone == -1) {
                // pakai nextone, sekarang ga dipake
                res += a[d[nxtone].se.front()];
                calc[d[nxtone].se.front()] = 1;
            }
            else {
                // nxtone ada, lastone ada
                // bandingkan lebih optimal nxtone dan lastone atau cur pair
                if((d[nxtone].fi + d[lastone].fi) / 2 > d[i].fi) {
                    // lebih optimal ambil cur
                    calc[d[lastone].se.front()] = 0;
                    res -= a[d[lastone].se.front()];
                    for(auto j : d[i].se) {
                        res += a[j], calc[j] = 1;
                    }
                }
                else {
                    res += a[d[nxtone].se.front()];
                    calc[d[nxtone].se.front()] = 1;
                }
            }
            break;
        }
        else {
            cur += d[i].se.size();
            for(auto j : d[i].se)
                res += a[j], calc[j] = 1;
        }
    }
    for(int i = 1; i <= n; ++i)
        if(!calc[i])
            res += b[i];
    cout << res << endl;
    return 0;
}