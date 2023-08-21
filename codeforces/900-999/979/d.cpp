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
    node *l, *r;
    int mn = 1e9, mx = -1e9;
};
struct trie_struct {
    node *head = new node();
    void update(node *nd, int idx, int val) {
        nd->mn = min(nd->mn, val);
        nd->mx = max(nd->mx, val);
        if(idx == -1) 
            return;
        // on
        if((1 << idx) & val) {
            if(!nd->r)
                nd->r = new node();
            update(nd->r, idx - 1, val);
        }
        // off
        else {
            if(!nd->l)
                nd->l = new node();
            update(nd->l, idx - 1, val);
        }
    }
    int query(node *nd, int idx, int target, int limit) {
        // find maximum xor with target, berarti cri yg berlawanan sama target tp dibawah value limitnya
        if(idx == -1)
            return 0;
        if((1 << idx) & target) {
            // prioritize ke off
            if(nd->l)
                return query(nd->l, idx - 1, target, limit) + (1 << idx);
            else
                return query(nd->r, idx - 1, target, limit);
        }
        else {
            // prioritize ke on
            if(nd->r && nd->r->mn <= limit) 
                return query(nd->r, idx - 1, target, limit) + (1 << idx);
            else
                return query(nd->l, idx - 1, target, limit);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int q;
    cin >> q;
    const int lim = 1e5 + 5, blk = 305;
    bool exist[lim];
    set<int> a[blk];
    memset(exist, 0, sizeof(exist));
    trie_struct trie[blk];
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int u;
            cin >> u;
            exist[u] = 1;
            for(int i = 1; i <= 300; ++i) {
                if(u % i == 0) {
                    a[i].ins(u);
                    trie[i].update(trie[i].head, 16, u);
                }
            }
        }
        else {
            int x, k, s;
            cin >> x >> k >> s;
            // case work:
            // gcd(x, k) != k -> always -1
            if(__gcd(x, k) != k) {
                cout << -1 << endl;
                continue;
            }
            // berarti klo gni mgkn ada jwbn
            // v harus kelipatan k_i dan x_i + v <= s_i
            // maximize x_i xor v
            // find "distance" dr x_i ke v yg terjauh
            // jadi antara min/max v value
            // bagi jadi blok of size 300
            // < 300 -> simpan dalam set exist dmn aja
            // klo lebih bs lgsg brute force checking sampe kurang dr 10^5 aja
            if(k > 300) {
                int res = -1;
                for(int i = k; i < lim; i += k) {
                    if(exist[i] && i + x <= s)
                        res = max(res, x ^ i);
                }
                if(res == -1)
                    cout << res << endl;
                else
                    cout << (res ^ x) << endl;
            }
            else {
                // coba pilih yg paling jauh
                int val_lim = s - x;
                // harus <= val_lim
                // ngga ada atau min terlalu besar, otomatis gada jwbn
                if(a[k].empty() || *a[k].begin() > val_lim) {
                    cout << -1 << endl;
                    continue;
                }
                // maximize xor
                // query trie
                int res = trie[k].query(trie[k].head, 16, x, val_lim);
                cout << (res ^ x) << endl;
            }
        }
    }
    return 0;
}