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
const int lim = 200001;
struct sparse_table {
    int a[18][lim], log[lim];
    sparse_table() {
        memset(a, -1, sizeof(a));
        log[1] = 0;
        for(int i = 2; i < lim; ++i)
            log[i] = log[i >> 1] + 1;
    }
    void build(vector<int> arr) {
        for(int i = 0; i < arr.size(); ++i)
            a[0][i] = arr[i];
        for(int i = 1; i < 18; ++i)
            for(int j = 0; j + (1 << i) <= lim; ++j)
                a[i][j] = max(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
    }
    int query(int l, int r) {
        int tmp = log[r - l + 1];
        return max(a[tmp][l], a[tmp][r - (1 << tmp) + 1]);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int p[n], a[m];
    int previous[n + 1];
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    for(int i = 0; i < n; ++i) {
        previous[p[i]] = p[(i - 1 + n) % n];
    }
    for(int i = 0; i < m; ++i)
        cin >> a[i];
    int prev[m], memo[n + 1];
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < m; ++i) {
        //cout << a[i] << " " << previous[a[i]] << endl;
        prev[i] = memo[previous[a[i]]];
        memo[a[i]] = i;
    }
    vector<int> par[m];
    int par_cnt[m];
    for(int i = 0; i < m; ++i) {
        if(prev[i] != -1) {
            vector<int> cur = {prev[i]};
            while(par[cur.back()].size() > cur.size() - 1)
                cur.pb(par[cur.back()][cur.size() - 1]);
            par[i] = cur;
            //cout << par[i].size() << " ";
            par_cnt[i] = par_cnt[prev[i]] + 1;
        }
        else
            par_cnt[i] = 0;
    }
    //cout << endl;
    vector<int> arr(m, -1e9);
    for(int i = 0; i < m; ++i) {
        if(par_cnt[i] >= n - 1) {
            // binlift n - 1
            int dist = n - 1, nd = i;
            for(int j = 17; j >= 0; --j) {
                if(dist >= 1 << j) {
                    dist -= 1 << j;
                    nd = par[nd][j];
                }
            }
            arr[i] = nd;
        }
    }
    //for(int i = 0; i < m; ++i)
    //    cout << prev[i] << " ";
    //cout << endl;
    //for(int i = 0; i < m; ++i)
    //    cout << arr[i] << " ";
    //cout << endl;
    sparse_table sp;
    sp.build(arr);
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        //cout << sp.query(l, r) << endl;
        cout << (int)(sp.query(l, r) >= l);
    }
    cout << endl;
    return 0;
}