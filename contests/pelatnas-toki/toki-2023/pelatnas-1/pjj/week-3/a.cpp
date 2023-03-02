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
struct node {
    int cnt = 0;
    int child[26];
    node() {
        memset(child, -1, sizeof(child));
    }
};
struct triestruct {
    string query;
    vector<node> a;
    triestruct() {
        a.pb(node());
    }
    void upd(int nd, int idx) {
        ++a[nd].cnt;
        if(idx == query.size())
            return;
        if(a[nd].child[query[idx] - 'a'] == -1)
            a[nd].child[query[idx] - 'a'] = a.size(), a.pb(node());
        upd(a[nd].child[query[idx] - 'a'], idx + 1);
    }
    int q(int nd, int idx) {
        if(idx == query.size())
            return a[nd].cnt;
        else if(a[nd].child[query[idx] - 'a'] == -1)
            return 0;
        else
            return q(a[nd].child[query[idx] - 'a'], idx + 1);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    triestruct t;
    for(int i = 0; i < n; ++i) {
        cin >> t.query;
        t.upd(0, 0);
    }
    for(int i = 0; i < q; ++i) {
        cin >> t.query;
        cout << t.q(0, 0) << endl;
    }
    return 0;
}