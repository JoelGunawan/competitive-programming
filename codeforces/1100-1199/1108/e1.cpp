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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    // find the amount of segments that are not touching the current index
    // O(nm)
    // lazy max query segtree
    // O(n^2m) for easy, O(nmlogn) for hard
    int a[n];
    pair<int, int> segments[m];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        segments[i] = mp(--u, --v);
    }
    int res = 0, res_idx = -1;
    for(int i = 0; i < n; ++i) {
        // choose all segments that do not intersect with the current segment
        // and decrease all the values by 1
        for(int j = 0; j < m; ++j) {
            if(!(i >= segments[j].fi && i <= segments[j].se)) {
                for(int k = segments[j].fi; k <= segments[j].se; ++k)
                    --a[k];
            }
        }
        int minimum = 1e9;
        for(int j = 0; j < n; ++j)  
            minimum = min(minimum, a[j]);
        //cout << maximum << " " << minimum << endl;
        for(int j = 0; j < m; ++j) {
            if(!(i >= segments[j].fi && i <= segments[j].se)) {
                for(int k = segments[j].fi; k <= segments[j].se; ++k)
                    ++a[k];
            }
        }
        if(a[i] - minimum >= res)
            res_idx = i, res = a[i] - minimum;
    }
    cout << res << endl;
    vector<int> ans;
    for(int i = 0; i < m; ++i) {
        if(!(res_idx >= segments[i].fi && res_idx <= segments[i].se))
            ans.pb(i + 1);
    }
    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}