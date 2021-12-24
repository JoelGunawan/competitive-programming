// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
int par[200005], furthest_leaf[200005], furthest_leaf_node[200005], children_cnt[200005];
bool vis[200005];
int dfs(int node = 1) {
    vis[node] = 1;
    for(auto i : edges[node]) {
        if(!vis[i]) {
            par[i] = node;
            int tmp = dfs(i) + 1;
            if(tmp > furthest_leaf[node]) {
                furthest_leaf[node] = tmp;
                furthest_leaf_node[node] = furthest_leaf_node[i];
            }
            ++children_cnt[node];
        }
    }
    return furthest_leaf[node];
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    for(int i = 0; i <= n + 5; ++i)
        furthest_leaf_node[i] = i;
    dfs();
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    // fi dist to furthest leaf, se node
    vector<pair<int ,int>> a(n);
    for(int i = 1; i <= n; ++i) {
        a[i - 1] = mp(furthest_leaf[i], i);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll removed = 0, red_cnt = 0;
    // red tries to make removed - red_cnt == red_cnt
    // and maximize such value
    // bsta removed dan red_cnt
    // coba red_cnt = x
    // removednya paling besar
    ll res = -1e15;
    int optional = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(!vis[a[i].se] && k > 0) {
            removed += a[i].fi + 1;
            --k;
            ++red_cnt;
            int tmp = furthest_leaf_node[a[i].se];
            while(!vis[tmp]) {
                //cout << tmp << " " << par[tmp] << endl;
                vis[tmp] = 1;
                tmp = par[tmp];
                --children_cnt[tmp];
                if(children_cnt[tmp] == 0)
                    // this is allowed to be chosen as something that has removed = 0
                    ++optional;
            }
            //cout << removed << " " << red_cnt << " " << n - removed << endl;
            if(red_cnt >= n - removed) {
                // we can use optional to maximize
                // optional is maximizing right side
                // while minimizing left side
                ll w = removed - red_cnt, r = red_cnt, b = n - removed;
                r -= b;
                ll mid = (r + w) / 2;
                if(r < mid) {
                    ll total = r + w;
                    r = min(r + min(optional, k), mid);
                    w = total - r;
                }
                res = max(res, r * w);
            }
            else {
                // blue can bully and choose optimally
                // since we can prove that blue can choose any node that is not removed individually
                // then we can just simply state
                // that blue will select
                // a number x
                // such that
                // (removed - red_cnt + x) * (red_cnt - (n - removed - x)) is minimum
                // result is negative
                // we can remove from blue and add to w
                ll w = removed - red_cnt, r = red_cnt, b = (n - removed);
                b -= r;
                ll mid = (b + w) / 2;
                if(w < mid) {
                    ll total = w + b;
                    w = min(w + b, mid);
                    b = total - w;
                }
                res = max(res, -1ll * w * b);
            }
        }
    }
    cout << res << endl;
    return 0;
}