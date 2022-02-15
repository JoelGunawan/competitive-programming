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
    int m;
    cin >> m;
    vector<int> arrays[m];
    map<int, int> cnt;
    for(int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int j = 0; j < n; ++j)
            cin >> a[j], ++cnt[a[j]];
        arrays[i] = a;
    }
    bool exists = 1;
    for(auto i : cnt)
        if(i.se & 1)
            exists = 0;
    if(exists)
        cout << "YES" << endl;
    else
        cout << "NO" << endl, exit(0);
    // if the count of something in an array is even, split evenly
    // else choose depending on the previous??
    map<int, vector<pair<int, int>>> occurence;
    vector<vector<char>> ans(m);
    for(int i = 0; i < m; ++i) {
        vector<char> cur(arrays[i].size(), '*');
        bool vis[arrays[i].size()];
        memset(vis, 0, sizeof(vis));
        vector<pair<int, int>> tmp(arrays[i].size());
        for(int j = 0; j < arrays[i].size(); ++j) {
            tmp[j] = mp(arrays[i][j], j);
        }
        sort(tmp.begin(), tmp.end());
        for(int j = 0; j < tmp.size() - 1; ++j) {
            if(tmp[j].fi == tmp[j + 1].fi && tmp[j].se == tmp[j + 1].se - 1) {
                vis[tmp[j].se] = 1;
                vis[tmp[j + 1].se] = 1;
                cur[tmp[j].se] = 'L';
                cur[tmp[j + 1].se] = 'R';
                ++j;
                //cout << i << " " << j << endl;
                //cout << i << " " << j + 1 << endl;
            }
        }
        for(int j = 0; j < arrays[i].size(); ++j) {
            if(!vis[j]) {
                occurence[arrays[i][j]].pb(mp(i, j));
            }
        }
        ans[i] = cur;
    }
    int deficit[m];
    memset(deficit, 0, sizeof(deficit));
    for(auto tmp : occurence) {
        vector<pair<int, int>> arr = tmp.se;
        vector<pair<int, pair<int, int>>> x;
        for(auto i : arr)
            x.pb(mp(deficit[i.fi], i));
        sort(x.begin(), x.end());
        for(int idx = 0; idx < x.size() / 2; ++idx) {
            pair<int, int> cur = x[idx].se;
            ++deficit[cur.fi];
            ans[cur.fi][cur.se] = 'L';
        }
        for(int idx = x.size() / 2; idx < x.size(); ++idx) {
            pair<int, int> cur = x[idx].se;
            --deficit[cur.fi];
            ans[cur.fi][cur.se] = 'R';
        }
    }
    for(auto i : ans) {
        for(auto j : i)
            cout << j;
        cout << endl;
    }
    return 0;
}