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
    pair<ll, ll> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    if(n < 200) {
        for(int abc = 1; abc <= max(n * n, 100); ++abc) {
            for(int j = 0; j < n; ++j) {
                if(a[j].fi > a[j].se) {
                    ll diff = a[j].fi - a[j].se;
                    if(diff & 1)
                        ++diff;
                    if(a[j].se == 0 && a[j].fi & 1)
                        diff -= 2;
                    a[j].fi -= diff;
                    a[(j + 1) % n].fi += diff / 2;
                    //cout << a[j].fi << " " << a[j].se << " " << diff << endl;
                }
            }
            //cout << endl;
        }
    }
    else {
        for(int abc = 1; abc <= 100; ++abc) {
            for(int j = 0; j < n; ++j) {
                if(a[j].fi > a[j].se) {
                    ll diff = a[j].fi - a[j].se;
                    if(diff & 1)
                        ++diff;
                    if(a[j].se == 0 && a[j].fi & 1)
                        diff -= 2;
                    a[j].fi -= diff;
                    a[(j + 1) % n].fi += diff / 2;
                    //cout << a[j].fi << " " << a[j].se << " " << diff << endl;
                }
            }
            //cout << endl;
        }
    }
    for(int i = 0; i < n; ++i) {
        if(a[i].fi != a[i].se)
            cout << "No" << endl, exit(0);
    }
    cout << "Yes" << endl;
    return 0;
}