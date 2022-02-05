// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
const int lim = 100001;
struct sparse {
    // euler tour index, index in sparse
    pair<int, int> a[17][lim];
    // type 0 -> min type 1 -> max
    bool type = 0;
    pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
        if(type)
            return max(a, b);
        else
            return min(a, b);
    }
    void build(vector<int> arr) {
        for(int i = 0; i < arr.size(); ++i)
            a[0][i] = mp(arr[i], i);
        for(int i = 1; i < 17; ++i) {
            for(int j = 0; j + (1 << i) <= lim; ++j) {
                a[i][j] = merge(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    pair<int, int> query(int l, int r) {
        int dist = r - l + 1;
        pair<int, int> res = mp(1e9, 1e9);
        if(type)
            res = mp(-1e9, -1e9);
        for(int i = 16; i >= 0; --i) {
            if(dist >= 1 << i) {
                dist -= 1 << i;
                res = merge(res, a[i][l]);
                l += 1 << i;
            }
        }
        return res;
    }
};
int anc[17][lim], depth[lim];
vector<int> tmp;
vector<int> child[lim];
int euler_tour[lim], cur = 0;
void dfs(int nd) {
    depth[nd] = tmp.size();
    euler_tour[nd] = cur++;
    int tmp1 = 1, tmp2 = 0;
    while(tmp1 <= tmp.size()) {
        anc[tmp2][nd] = tmp[tmp.size() - tmp1];
        tmp1 <<= 1, ++tmp2;
    }
    tmp.pb(nd);
    for(auto i : child[nd])
        dfs(i);
    tmp.pop_back();
}
int lca(int a, int b) {
    //cout << a << " " << b << endl;
    if(depth[a] > depth[b])
        swap(a, b);
    for(int i = 16; i >= 0; --i) {
        //cout << a << " " << b << endl;
        if(depth[anc[i][b]] >= depth[a])
            b = anc[i][b];
    }
    //cout << "TEST3" << endl;
    if(a == b)
        return a;
    for(int i = 16; i >= 0; --i) {
        if(anc[i][b] != anc[i][a]) {
            a = anc[i][a];
            b = anc[i][b];
        }
    }
    //cout << "TEST4" << endl;
    return anc[0][a];
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        child[p].pb(i);
    }
    dfs(1);   
    sparse a, b;
    b.type = 1;
    vector<int> et(n + 1);
    for(int i = 0; i <= n; ++i)
        et[i] = euler_tour[i];
    a.build(et), b.build(et);
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        pair<int, int> left, second_left, right, second_right;
        left = a.query(l, r);
        right = b.query(l, r);
        //cout << "TEST" << endl;
        second_left = min(a.query(l, left.se - 1), a.query(left.se + 1, r));
        second_right = max(b.query(l, right.se - 1), b.query(right.se + 1, r));
        //cout << "TEST2" << endl;
        if(depth[lca(second_left.se, right.se)] < depth[lca(left.se, second_right.se)]) {
            cout << right.se << " " << depth[lca(left.se, second_right.se)] << endl;
        }
        else {
            cout << left.se << " " << depth[lca(second_left.se, right.se)] << endl;
        }
    }
    return 0;
}