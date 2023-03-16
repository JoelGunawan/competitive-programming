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
const int lim = 50005;
const int blk = 600;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // sqrt query decomp
    set<int> edges[lim];
    int n, m, q, o;
    cin >> n >> m >> q >> o;
    vector<int> tmp(o);
    for(int i = 0; i < o; ++i)
        cin >> tmp[i];
    set<int> large;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].ins(v);
        edges[v].ins(u);
    }
    int res[n + 1], val[n + 1];
    memset(val, 0, sizeof(val));
    memset(res, 0, sizeof(res));
    for(int i = 1; i <= n; ++i) {
        if(edges[i].size() >= blk)
            large.insert(i);
    }
    for(auto i : tmp) {
        val[i] = 1;
        if(edges[i].size() < blk) {
            for(auto j : edges[i])
                ++res[j];
        }
    }
    for(int i = 0; i < q; ++i) {
        char t;
        cin >> t;
        if(t == 'O') {
            int u;
            cin >> u;
            // u nambah 1
            val[u] = 1;
            if(edges[u].size() < blk) {
                for(auto j : edges[u])
                    ++res[j];
            }
        }
        else if(t == 'F') {
            int u;
            cin >> u;
            val[u] = 0;
            if(edges[u].size() < blk) {
                for(auto j : edges[u])
                    --res[j];
            }
        }
        else if(t == 'A') {
            // cek u v berubah status atau gak dulu
            int u, v;
            cin >> u >> v;
            if(edges[u].size() == blk - 1) {
                // konversi u jadi nilai blk type
                if(val[u]) {
                    for(auto j : edges[u]) {
                        --res[j];
                    }
                }
                large.ins(u);
            }
            if(edges[v].size() == blk - 1) {
                if(val[v]) {
                    for(auto j : edges[v])
                        --res[j];
                }
                large.ins(v);
            }
            edges[u].ins(v);
            edges[v].ins(u);
            if(edges[u].size() < blk) {
                res[v] += val[u];
            }
            if(edges[v].size() < blk) {
                res[u] += val[v];
            }
        }
        else if(t == 'D') {
            int u, v;
            cin >> u >> v;
            // konversi jadi non blk type
            if(edges[u].size() == blk) {
                large.erase(large.find(u));
                if(val[u]) {
                    for(auto j : edges[u]) {
                        ++res[j];
                    }
                }
            }
            if(edges[v].size() == blk) {
                large.erase(large.find(v));
                if(val[v]) {
                    for(auto j : edges[v]) {
                        ++res[j];
                    }
                }
            }
            edges[u].erase(edges[u].find(v));
            edges[v].erase(edges[v].find(u));
            if(edges[u].size() < blk)
                res[v] -= val[u];
            if(edges[v].size() < blk) {
                res[u] -= val[v];
            }
        }
        else {
            int c;
            cin >> c;
            int tmp = 0;
            for(auto x : large) {
                if(edges[c].count(x))
                    tmp += val[x];
            }
            cout << tmp + res[c] << endl;
        }
    }
    return 0;
}