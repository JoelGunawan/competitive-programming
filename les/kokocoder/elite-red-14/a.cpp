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
set<int> edges[lim];
bool a[lim];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].ins(v);
        if(v > u)
            a[u] = 1;      
        edges[v].ins(u);
        if(u > v)
            a[v] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        cnt += a[i];
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, y;
            cin >> x >> y;
            edges[x].ins(y);
            edges[y].ins(x);
            if(x > y) {
                if(!a[y])
                    ++cnt;
                a[y] = x;
            }
            else {
                if(!a[x])
                    ++cnt;
                a[x] = y;
            }
        }
        else if(t == 2) {
            int x, y;
            cin >> x >> y;
            edges[x].erase(y);
            edges[y].erase(x);
            if(a[x]) {
                if(edges[x].ub(x) == edges[x].end())
                    a[x] = 0, --cnt;
            }
            if(a[y]) {
                if(edges[y].ub(y) == edges[y].end())
                    a[y] = 0, --cnt;
            }
        }
        else {
            cout << n - cnt << endl;
        }
    }
    return 0;
}