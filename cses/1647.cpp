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

const int limit = 200000;
struct sparse_table {
    int a[18][limit];
    void build(vector<int> arr) {
        for(int i = 0; i < 18; ++i)
            for(int j = 0; j < limit; ++j)
                a[i][j] = INT_MAX;
        for(int i = 0; i < arr.size(); ++i) { 
            a[0][i] = arr[i];
        }
        for(int i = 1; i < 18; ++i) {
            for(int j = 0; j + (1 << i) <= limit; ++j) {
                a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int dist = r - l + 1, res = INT_MAX;
        for(int i = 17; i >= 0; --i) {
            if(dist >= 1 << i) {
                res = min(res, a[i][l]);
                l += 1 << i;
                dist -= 1 << i;
            }
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for(int i = 0; i < n; ++i)
        cin >> x[i];
    sparse_table sp;
    sp.build(x);
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << sp.query(l - 1, r - 1) << endl;
    }
    return 0;
}