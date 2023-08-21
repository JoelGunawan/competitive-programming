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
const int lim = 2e5 + 5;
vector<int> edges[lim];
int target;
bool vis[lim], active[lim];
void dfs(int nd) {
    vis[nd] = 1, active[nd] = 1;
    for(auto i : edges[nd]) {
        if(active[i]) {
            target = nd;
            return;
        }
        else if(target != 0)
            return;
        if(!vis[i])
            dfs(i);
    }
    active[nd] = 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        edges[i].pb(a[i]);
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) 
            dfs(i);
        if(target != 0) {
            vector<int> v;
            v.pb(target);
            while(a[v.back()] != v.front())
                v.pb(a[v.back()]);
            cout << v.size() << endl;
            for(auto i : v)
                cout << i << " ";
            cout << endl;
            return 0;
        }
    }
    return 0;
}