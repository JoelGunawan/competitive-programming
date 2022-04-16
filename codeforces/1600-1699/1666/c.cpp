// header file
#include <bits/stdc++.h>
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
vector<vector<int>> ans;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pair<int, int> a[3];
    for(int i = 0; i < 3; ++i)
        cin >> a[i].fi >> a[i].se;
    sort(a, a + 3);
    if(a[0].se > a[2].se) {
        if(a[1].se <= a[0].se && a[1].se >= a[2].se) {
            ans.pb({a[0].fi, a[0].se, a[1].fi, a[0].se});
            ans.pb({a[1].fi, a[0].se, a[1].fi, a[2].se});
            ans.pb({a[1].fi, a[2].se, a[2].fi, a[2].se});
        }
        else if(a[1].se > a[0].se) {
            ans.pb({a[0].fi, a[0].se, a[2].fi, a[0].se});
            ans.pb({a[2].fi, a[0].se, a[2].fi, a[2].se});
            ans.pb({a[1].fi, a[0].se, a[1].fi, a[1].se});
        }
        else {
            ans.pb({a[0].fi, a[0].se, a[0].fi, a[2].se});
            ans.pb({a[0].fi, a[2].se, a[2].fi, a[2].se});
            ans.pb({a[1].fi, a[2].se, a[1].fi, a[1].se});
        }
    }
    else {
        if(a[1].se <= a[2].se && a[1].se >= a[0].se) {
            ans.pb({a[0].fi, a[0].se, a[1].fi, a[0].se});
            ans.pb({a[1].fi, a[0].se, a[1].fi, a[2].se});
            ans.pb({a[1].fi, a[2].se, a[2].fi, a[2].se});
        }
        else if(a[1].se > a[2].se) {
            ans.pb({a[0].fi, a[0].se, a[0].fi, a[2].se});
            ans.pb({a[0].fi, a[2].se, a[2].fi, a[2].se});
            ans.pb({a[1].fi, a[2].se, a[1].fi, a[1].se});
        }
        else {
            ans.pb({a[0].fi, a[0].se, a[2].fi, a[0].se});
            ans.pb({a[2].fi, a[0].se, a[2].fi, a[2].se});
            ans.pb({a[1].fi, a[0].se, a[1].fi, a[1].se});
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans) {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}