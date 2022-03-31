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
    int n, k;
    cin >> n >> k;
    int a[n], c[k + 1];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 1; i <= k; ++i)
        cin >> c[i];
    sort(a, a + n);
    reverse(a, a + n);
    multiset<pair<int, int>> cnt;
    vector<vector<int>> ans;
    for(int i = 0; i < n; ++i) {
        if(cnt.size() == 0) {
            cnt.ins(mp(1, 0));
            ans.pb({a[i]});
        }
        else {
            pair<int, int> tmp = *cnt.begin();
            if(tmp.fi >= c[a[i]]) {
                cnt.ins(mp(1, ans.size()));
                ans.pb({a[i]});
            }
            else {
                cnt.erase(cnt.begin());
                cnt.ins(mp(tmp.fi + 1, tmp.se));
                ans[tmp.se].pb(a[i]);
            }
        }
    }
    cout << cnt.size() << endl;
    for(auto i : ans) {
        cout << i.size() << " ";
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}