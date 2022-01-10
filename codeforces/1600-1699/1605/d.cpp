// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
vector<int> edges[200005];
bool vis[200005];
int ans[200005];
int odd_cnt, even_cnt;
vector<int> odd, even;
void dfs(int nd = 1, bool depth = 0) {
    vis[nd] = 1;
    if(depth)
        ++even_cnt;
    else
        ++odd_cnt;
    for(auto i : edges[nd]) {
        if(!vis[i])
            dfs(i, !depth);
    } 
}
void fill_dfs(int nd = 1, bool depth = 0) {
    if(depth)
        ans[nd] = even.back(), even.pop_back();
    else
        ans[nd] = odd.back(), odd.pop_back();
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            fill_dfs(i, !depth);
    }
}
void tc() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        edges[i].clear(), vis[i] = 0, ans[i] = 0;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    odd_cnt = 0, even_cnt = 0;
    dfs();
    vector<int> cnt;
    for(int i = 1; i <= n; ++i) {
        if((i&-i) == i)
            cnt.pb(1);
        else
            ++cnt.back();
    }
    // find a way to construct min between even and odd from cnt
    for(int i = 0; i < (1 << cnt.size()); ++i) {
        int tmp = 0;
        for(int j = 0; j < cnt.size(); ++j) {
            if((1 << j) & i)
                tmp += cnt[j];
        }
        if(tmp == even_cnt) {
            for(int j = 0; j < cnt.size(); ++j)  {
                for(int k = 1 << j; k <= min(n, (1 << (j + 1)) - 1); ++k) {
                    if((1 << j) & i)
                        even.pb(k);
                    else
                        odd.pb(k);
                }
            }
            break;
        }
    }
    for(int i = 1; i <= n; ++i)
        vis[i] = 0;
    fill_dfs();
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}