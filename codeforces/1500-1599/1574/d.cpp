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
vector<int> c[11];
set<vector<int>> banned;
pair<int, vector<int>> ans;
map<vector<int>, bool> vis;
void f(vector<int> &idx) {
    if(vis[idx])
        return;
    vis[idx] = 1;
    if(banned.find(idx) == banned.end()) {
        int res = 0;
        for(int i = 0; i < idx.size(); ++i) {
            //cout << idx[i] << " ";
            res += c[i][idx[i]];
        }
        //cout << endl;
        //cout << res << endl;
        ans = max(ans, mp(res, idx));
    }
    else {
        for(int i = 0; i < idx.size(); ++i) {
            if(idx[i] > 0) {
                --idx[i];
                f(idx);
                ++idx[i];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> tmp;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for(int j = 0; j < x; ++j) {
            int y;
            cin >> y;
            c[i].pb(y);
        }
        tmp.pb(x - 1);
    }
    int m;
    cin >> m;
    vector<int> tmp2(n);
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j)
            cin >> tmp2[j], --tmp2[j];
        banned.ins(tmp2);
    }
    f(tmp);
    for(auto i : ans.se)
        cout << i + 1 << " ";
    cout << endl;
    return 0;
}