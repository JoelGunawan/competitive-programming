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
struct node {
    int l = -1, r = -1, cnt = 0;
};
ll res = 0;
struct trie_obj {
    vector<node> nd = {node()};
    void update(int num, int depth, int idx) {
        ++nd[idx].cnt;
        //cout << "UPDATE " << num << " " << depth << " " << idx << endl;
        if(depth == -1) {
            return;
        }
        if((1 << depth) & num) {
            // go right
            if(nd[idx].r == -1)
                nd[idx].r = nd.size(), nd.pb(node());
            update(num, depth - 1, nd[idx].r);
        }
        else {
            // go left
            if(nd[idx].l == -1)
                nd[idx].l = nd.size(), nd.pb(node());
            update(num, depth - 1, nd[idx].l);
        }
    }
    int dfs_min(int idx, int num, int depth) {
        //cout << idx << " " << nd[idx].l << " " << nd[idx].r << endl;
        if(depth == -1)
            return 0;
        if((1 << depth) & num) {
            // kalo ada yang sama, pergi ke situ
            if(nd[idx].r == -1)
                return dfs_min(nd[idx].l, num, depth - 1) + (1 << depth);
            else
                return dfs_min(nd[idx].r, num, depth - 1);
        }
        else {
            if(nd[idx].l == -1)
                return dfs_min(nd[idx].r, num, depth - 1) + (1 << depth);
            else
                return dfs_min(nd[idx].l, num, depth - 1);
        }
    }
    int dfs_max(int idx, int num, int depth) {
        if(depth == -1)
            return 0;
        if((1 << depth) & num) {
            // kalo ada yang sama, pergi ke situ
            if(nd[idx].l != -1)
                return dfs_max(nd[idx].l, num, depth - 1) + (1 << depth);
            else
                return dfs_max(nd[idx].r, num, depth - 1);
        }
        else {
            if(nd[idx].r != -1)
                return dfs_max(nd[idx].r, num, depth - 1) + (1 << depth);
            else
                return dfs_max(nd[idx].l, num, depth - 1);
        }
    }
    // dari situ pergi ke par, terus nanti di tiap index, kita merge semuanya pairwise? -> no, we find closest to a certain object :D
};
const int lim = 1e5 + 5;
bool vis[lim];
vector<pair<int, int>> edges[lim];
vector<int> arr;
void dfs(int nd, int cur = 0) {
    vis[nd] = 1;
    arr.pb(cur);
    for(auto i : edges[nd]) {
        if(!vis[i.fi]) {
            dfs(i.fi, cur ^ i.se);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // nlog^2 def possible with trie merging
    // HLD tapi isinya trie?
    // jadi nanti tiap path HLD dicari ke root pathnya berapa
    // buat trie yang rootnya 1
    // nanti buat minimum xor itu cari xor yang paling deket
    // buat maximum xor itu cari xor yang paling jauh
    // cari minimum xor itu kyk cari LCA?
    // atau bs lgsg ke parentnya aja, cari yang paling deket
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].pb(mp(v, w));
        edges[v].pb(mp(u, w));
    }
    dfs(1);
    trie_obj trie;
    trie.update(arr[0], 29, 0);
    int mx_res = 0, mn_res = 2e9;
    for(int i = 1; i < arr.size(); ++i) {
        mx_res = max(mx_res, trie.dfs_max(0, arr[i], 29));
        mn_res = min(mn_res, trie.dfs_min(0, arr[i], 29));
        trie.update(arr[i], 29, 0);
    }
    cout << mn_res << " " << mx_res << endl;
    return 0;
}