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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int k;
struct sparse_table {
    ll a[17][100005];
    sparse_table() {
        memset(a, 0, sizeof(a));
    }
    ll merge(ll a, ll b) {
        return gcd(a * b, k);
    }
    void build(vector<int> arr) {
        for(int i = 0; i < arr.size(); ++i)
            a[0][i] = gcd(arr[i], k);
        for(int i = 1; i < 17; ++i) {
            for(int j = 0; j + (1 << i) <= 100005; ++j) {
                a[i][j] = merge(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    ll query(ll l, ll r) {
        ll dist = r - l + 1;
        ll res = 1;
        for(int i = 16; i >= 0; --i) {
            if(dist >= 1 << i) {
                res = merge(res, a[i][l]);
                dist -= 1 << i;
                l += 1 << i;
            }
        }
        return res;
    }
};
sparse_table sp;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n >> k;
    // use gcd sparse table
    // where the merge process is multiplying and then finding gcd
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sp.build(arr);
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        int l = i, r = n, res;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(sp.query(i, mid) == k) 
                res = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        ans += n - res;
    }
    cout << ans << endl;
    return 0;
}