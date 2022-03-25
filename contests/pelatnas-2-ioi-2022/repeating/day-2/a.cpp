// header file
#include <bits/stdc++.h>
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
vector<int> child[200001];
int depth[200001], subtree[200001], ett[200001];
struct bit {
    int a[200005];
    bit() {
        memset(a, 0, sizeof(a));
    }
    void reset() {
        memset(a, 0, sizeof(a));
    }
    void update(int l, int r, int val) {
        upd(l, val);
        upd(r + 1, -val);
    }
    void upd(int idx, int val) {
        while(idx < 200005)
            a[idx] += val, idx += (idx&-idx);
    }
    int query(int idx) {
        int res = 0;
        while(idx > 0) {
            res += a[idx], idx -= (idx&-idx);
        }
        return res;
    }
};
int global = 0;
int dfs(int nd, int d) {
    depth[nd] = d;
    subtree[nd] = 1;
    ett[nd] = global++;
    //cout << nd << " " << ett[nd] << endl;
    for(auto i : child[nd])
        subtree[nd] += dfs(i, d + 1);
    return subtree[nd];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        child[p].pb(i);
    }
    dfs(0, 0);
    bit bit;
    int q;
    cin >> q;
    //for(int i = 1; i <= n; ++i)
    //    cout << subtree[i] << " ";
    //cout << endl;
    for(int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        vector<pair<int, int>> b(k);
        for(int i = 0; i < k; ++i) {
            int tmp;
            cin >> tmp;
            b[i] = mp(depth[tmp], tmp);
        }
        sort(b.begin(), b.end());
        int res = 0;
        set<pair<int, int>> segments;
        for(auto i : b) {
            if(bit.query(ett[i.se]) == 0) {
                //cout << ett[i.se] << " " << ett[i.se] + subtree[i.se] - 1 << endl;
                res += subtree[i.se];
                bit.update(ett[i.se], ett[i.se] + subtree[i.se] - 1, 1);
            }
        }
        bit.reset();
        cout << res << endl;
    }
    return 0;
}