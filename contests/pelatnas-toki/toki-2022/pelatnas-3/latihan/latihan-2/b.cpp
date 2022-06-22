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
// dsu on trie_struct
// merge based on suffix.size
const int lim = 2e6 + 5;
const int lim2 = 1e5 + 5;
int q[lim2];
int key = 98689;
int mod1 = 1e9 + 9, mod2 = 1e9 + 7;
pair<vector<int>, vector<int>> h(string s) {
    vector<int> res1, res2;
    ll cur1 = 0, cur2 = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        cur1 = (cur1 * key + s[i]) % mod1;
        cur2 = (cur2 * key + s[i]) % mod2;
        res1.pb(cur1);
        res2.pb(cur2);
    }
    return mp(res1, res2);
}
unordered_map<int, int> valid_suffix1, valid_suffix2;
struct disjoint_set {
    int size[lim], head[lim];
    unordered_map<int, int> suffix1[lim];//, suffix2[lim];
    disjoint_set() {
        fill(size, size + lim, 1);
        memset(head, -1, sizeof(head));
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            if(suffix1[x].size() < suffix1[y].size())
                swap(suffix1[x], suffix1[y]);//, swap(suffix2[x], suffix2[y]);
            size[x] += size[y], head[y] = x;
            for(auto i : suffix1[y])
                suffix1[x][i.fi] += i.se;
            //for(auto i : suffix2[y])
            //    suffix2[x][i.fi] += i.se;
        }
        return x != y;
    }
};
struct node {
    int child[4];
    vector<pair<int, pair<int, int>>> q;
    node() {
        memset(child, -1, sizeof(child));
    }
};
int to_num(char a) {
    if(a == 'A')
        return 0;
    else if(a == 'C')
        return 1;
    else if(a == 'G')
        return 2;
    else
        return 3;
}
disjoint_set dsu;
struct trie_struct {
    vector<node> a = {node()};
    string u;
    int qnum, suffhash1, suffhash2;
    void update(int nd, int idx) {
        if(idx == u.size()) {
            // poly h u
            // masukkan semua poly h ke suffix
            pair<vector<int>, vector<int>> tmp = h(u);
            //cout << nd << " HASH" << endl;
            for(auto i : tmp.fi)
                if(valid_suffix1[i])
                    ++dsu.suffix1[nd][i];
            //cout << endl;
            //for(auto i : tmp.se)
            //    if(valid_suffix2[i])
            //        ++dsu.suffix2[nd][i];
            //cout << endl;
            return;
        }
        int num = to_num(u[idx]);
        if(a[nd].child[num] == -1)  
            a[nd].child[num] = a.size(), a.pb(node());
        update(a[nd].child[num], ++idx);
    }
    void query(int nd, int idx) {
        if(idx == u.size()) {
            //cout << nd << " q " << suffhash1 << " " << suffhash2 << endl;
            a[nd].q.pb(mp(qnum, mp(suffhash1, suffhash2)));
            return;
        }
        int num = to_num(u[idx]);
        if(a[nd].child[num] == -1)
            return;
        query(a[nd].child[num], idx + 1);
    }
    void solve(int nd) {
        for(auto i : a[nd].child) {
            if(i != -1)
                solve(i), dsu.merge(nd, i);
                // cout << "MERGE " << nd << " " << i << endl;
        }
        for(auto i : a[nd].q) {
            q[i.fi] = dsu.suffix1[dsu.find_head(nd)][i.se.fi];//dsu.suffix2[dsu.find_head(nd)][i.se.se]);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    string a[n];
    // get suffix in h, cek klo ada string yang prefix x dan suffix y
    // get prefix and suffix in h
    // for each query, get prefix, in that prefix store string h values for a certain suffix length
    trie_struct trie;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    pair<string, string> b[m];
    for(int i = 0; i < m; ++i) {
        cin >> b[i].fi >> b[i].se;
        pair<vector<int>, vector<int>> tmp = h(b[i].se);
        valid_suffix1[tmp.fi.back()] = 1;
        valid_suffix2[tmp.se.back()] = 1;
    }
    for(int i = 0; i < n; ++i)
        trie.u = a[i], trie.update(0, 0);
    for(int i = 0; i < m; ++i) {
        trie.u = b[i].fi;
        pair<vector<int>, vector<int>> tmp = h(b[i].se);
        trie.suffhash1 = tmp.fi.back(), trie.suffhash2 = tmp.se.back();
        trie.qnum = i;
        trie.query(0, 0);
    }
    trie.solve(0);
    // remember to add query to trie_struct and add query number
    // tiap query itu ada suffix h value yang diperlukan
    // cek suffix h value itu ada berapa yang sama
    for(int i = 0; i < m; ++i)
        cout << q[i] << endl;
    return 0;
}