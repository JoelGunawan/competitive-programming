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
struct node {
    vector<int> index = {};
    int cnt = 0;
    int child[4];
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
    else if(a == 'U')
        return 3;
    assert(false);
}
struct trie_struct {
    string u;
    vector<node> a = {node()};
    int csize;
    void update(int nd, int idx, int num) {
        a[nd].index.pb(num);
        a[nd].cnt++;
        if(idx == u.size())
            return;
        int cur = to_num(u[idx]);
        if(a[nd].child[cur] == -1)
            a[nd].child[cur] = a.size(), a.pb(node());
        update(a[nd].child[cur], idx + 1, num);
    }
    int query(int nd, int idx, int l, int r) {
        if(idx == u.size())
            return upper_bound(a[nd].index.begin(), a[nd].index.end(), r) - lower_bound(a[nd].index.begin(), a[nd].index.end(), l);
        int cur = to_num(u[idx]);
        if(a[nd].child[cur] != -1)
            return query(a[nd].child[cur], idx + 1, l, r);
        else 
            return 0;
    }
    int get_prev(int nd, int idx) {
        if(idx == u.size()) {
            csize = a[nd].cnt;
            return 0;
        }
        int cur = to_num(u[idx]);
        if(a[nd].child[cur] == -1) {
            csize = -1;
            return 0;
        }
        else {
            int res = 0;
            for(int i = cur; i < 4; ++i) {
                if(a[nd].child[i] != -1)
                    res += a[a[nd].child[i]].cnt;
            }
            return a[nd].cnt - res + get_prev(a[nd].child[cur], idx + 1);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    string a[n];
    trie_struct sufftrie, preftrie;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; ++i) {
        preftrie.u = a[i];
        preftrie.update(0, 0, 0);
        sufftrie.u = a[i];
        reverse(sufftrie.u.begin(), sufftrie.u.end());
        sufftrie.update(0, 0, i);       
    }
    string x, y;
    for(int i = 0; i < m; ++i) {
        // determine range of l to r
        cin >> x >> y;
        reverse(y.begin(), y.end());   
        preftrie.u = x;
        preftrie.csize = -1;
        int tmp = preftrie.get_prev(0, 0), tmp2 = preftrie.csize;
        sufftrie.u = y;
        //cout << tmp << " " << tmp + tmp2 - 1 << endl;
        if(tmp2 != -1)
            cout << max(0, sufftrie.query(0, 0, tmp, tmp + tmp2 - 1)) << endl;
        else
            cout << 0 << endl;
    }
    //cout << a[0] << " " << a[1] << endl;
    return 0;
}