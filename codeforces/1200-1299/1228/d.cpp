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
const int lim = 1e5 + 5;
vector<int> edges[lim];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    set<int> s[3], unused;
    bool ans = 1;
    // first
    set<int> exist;
    for(auto i : edges[1]) {
        exist.ins(i);
    }
    s[0].ins(1);
    for(int i = 2; i <= n; ++i) {
        if(exist.count(i))
            unused.ins(i);
        else
            s[0].ins(i);
    }
    if(edges[1].size() < 2)
        cout << -1 << endl, exit(0);
    exist.clear();
    for(auto i : edges[edges[1][0]])
        exist.ins(i);
    for(int i = 2; i <= n; ++i) {
        if(unused.count(i) && exist.count(i))
            s[1].ins(i), unused.erase(i);
    }
    s[2] = unused;
    unused.clear();
    int number[n + 1];
    for(int i = 0; i < 3; ++i) {
        for(auto j : s[i])
            number[j] = i + 1;
    }
    if(s[0].size() == 0 || s[1].size() == 0 || s[2].size() == 0)
        cout << -1 << endl, exit(0);
    for(int i = 1; i <= n; ++i) {
        //cout << i << " " << edges[i].size() << " " << s[number[i] - 1].size() << endl;
        if(edges[i].size() != n - s[number[i] - 1].size())
            cout << -1 << endl, exit(0);
        for(auto j : edges[i]) {
            if(number[i] == number[j])
                cout << -1 << endl, exit(0);
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << number[i] << " ";
    cout << endl;
    return 0;
}