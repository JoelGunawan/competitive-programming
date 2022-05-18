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
const int lim = 1000005;
int LOG[lim];
struct sparse_table_max {
    int a[21][lim];
    sparse_table_max() {
        memset(a, 0, sizeof(a));
    }
    int merge(int a, int b) {
        return max(a, b);
    }
    void build(vector<int> arr) {
        for(int i = 0; i < arr.size(); ++i)
            a[0][i] = arr[i];
        for(int i = 1; i < 21; ++i) {
            for(int j = 0; j + (1 << i) <= lim; ++j) {
                a[i][j] = merge(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int dist = (r - l + 1);
        return merge(a[LOG[dist]][l], a[LOG[dist]][r - (1 << (LOG[dist])) + 1]);
    }
};
int main() {
    for(int i = 2; i < lim; ++i)
        LOG[i] = LOG[i >> 1] + 1;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // maintain next occurence of A[i] and prev occurence for A[i] in the range L, R
    // find max or of prev occurence
    // corner case -> l[i] - 1 == r[i] + 1 ._. (nvm found solution)
    // first precalculate furthest r
    // for each query find maximum result in range that is valid
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> b(n + 1, 0);
    int prev[n + 1];
    memset(prev, 0, sizeof(prev));
    for(int i = 1; i <= n; ++i) {
        b[i] = prev[a[i]];
        prev[a[i]] = i;
    }
    sparse_table_max m, res;
    m.build(b);
    // maintains furthest right
    vector<int> result(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        int l = i, r = n, tmp;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(m.query(i, mid) < i)
                l = mid + 1, tmp = mid;
            else
                r = mid - 1;
        }
        result[i] = tmp - i + 1;
        //cout << result[i] << " ";
    }
    //cout << endl;
    res.build(result);
    int last = 0;
    for(int i = 0; i < q; ++i) {
        int p, q;
        cin >> p >> q;
        p ^= last, q ^= last;
        // binser l yang mungkin
        // binser l menggunakan max query
        int l = 1, r = p, tmp = p;
        while(l <= r) {
            int mid = (l + r) / 2;
            //cout << mid << " " << q << " " << m.query(mid, q) << endl;
            if(m.query(mid, q) < mid)
                r = mid - 1, tmp = mid;
            else
                l = mid + 1;
        }       
        //cout << tmp << " " << p << endl;
        last = res.query(tmp, p);
        cout << last << endl;
    }
    return 0;
}