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
struct query {
    string type, pre, suff;
};
struct node {
    node *child[26];
    int cnt = 0;
};
struct trie_struct {
    node *head = new node();
    string s;
    void update(node *nd, int idx) {
        ++nd->cnt;
        //cout << "CHECK " << idx << " " << s << " " << nd->cnt << endl;
        if(idx < s.size()) {
            if(!nd->child[s[idx] - 'a'])
                nd->child[s[idx] - 'a'] = new node();
            update(nd->child[s[idx] - 'a'], idx + 1);
        }
    }
    int query(node *nd, int idx) {
        if(idx == s.size())
            return nd->cnt;
        else {
            if(nd->child[s[idx] - 'a'])
                return query(nd->child[s[idx] - 'a'], idx + 1);
            else
                return 0;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //cout << (int)("ab" < "aba") << endl;
    int n, q;
    cin >> n >> q;
    string a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    // tiap query bakal kasih "request" dia mau value apa aja
    // misal pre oc suff at
    // dia bakal request wktu lgi di obz sm ocz buat query at
    query queries[q + 1];
    // fi -> suffix yg mau didapetin
    // se.fi -> query yg req value (nanti tinggal max - min aja (abs value))
    vector<pair<string, int>> v[n + 1];
    vector<int> vals[q + 1];
    for(int i = 1; i <= q; ++i) {
        cin >> queries[i].type >> queries[i].pre >> queries[i].suff;
        string tmp = queries[i].pre;
        tmp += '{';
        // '{' is after z
        int idxa = lb(a + 1, a + n + 1, tmp) - a - 1, idxb = lb(a + 1, a + n + 1, queries[i].pre) - a - 1;
        reverse(queries[i].suff.begin(), queries[i].suff.end());
        v[idxa].pb(mp(queries[i].suff, i));
        v[idxb].pb(mp(queries[i].suff, i));
    }
    trie_struct trie, pre, suf;
    for(int i = 1; i <= n; ++i) {
        pre.s = a[i];
        pre.update(pre.head, 0);
    }
    for(int i = 1; i <= n; ++i) {
        reverse(a[i].begin(), a[i].end());
        trie.s = a[i];
        trie.update(trie.head, 0);
        for(auto j : v[i]) {
            trie.s = j.fi;
            vals[j.se].pb(trie.query(trie.head, 0));
        }
    }
    for(int i = 1; i <= n; ++i) {
        suf.s = a[i];
        suf.update(suf.head, 0);
    }
    for(int i = 1; i <= q; ++i) {
        int both = 0;
        if(vals[i].size() == 1)
            both = vals[i][0];
        else if(vals[i].size() == 2)
            both = vals[i][1] - vals[i][0];
        pre.s = queries[i].pre;
        int p = pre.query(pre.head, 0);
        suf.s = queries[i].suff;
        int s = suf.query(suf.head, 0);
        if(queries[i].type == "XOR") {
            cout << p + s - 2 * both << endl;
        }
        else if(queries[i].type == "AND") {
            cout << both << endl;
        }
        else {
            cout << p + s - both << endl;
        }
    }
    // jalanin trie according to order of a
    // after each iteration, isi vals yg request
    // ada kasus vals.size() == 1, lgsg output
    return 0;
}