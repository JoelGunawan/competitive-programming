// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
struct sparse_table {
    ll a[18][lim];
    int s;
    sparse_table() {
        memset(a, 0, sizeof(a));
    }
    void reset(int n) {
        s = n;
        for(int i = 0; i < 18; ++i) {
            for(int j = 0; j <= n; ++j)
                a[i][j] = 0;
        }
    }
    void build(vector<ll> arr) {
        for(int i = 0; i < arr.size(); ++i)
            a[0][i] = arr[i];
        for(int i = 1; i < 18; ++i) {
            for(int j = 0; j + (1 << i) < arr.size(); ++j)
                a[i][j] = gcd(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
        }
    }
    ll query(int l, int r) {
        //cout << l << " " << r << endl;
        ll res = 0;
        for(int i = 17; i >= 0; --i) {
            if(l + (1 << i) <= r) {
                res = gcd(res, a[i][l]);
                l += 1 << i;
            }
        }
        //cout << res << endl;
        return gcd(res, a[0][l]);
    }
};
sparse_table sp;
void tc() {
    int n;
    cin >> n;
    sp.reset(n - 1);
    //cout << "TEST" << endl;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<ll> diff(n - 1);
    for(int i = 0; i < n - 1; ++i)
        diff[i] = abs(a[i] - a[i + 1]);
    // longest sequence of gcd sequence
    // sparse table :)
    sp.build(diff);
    //cout << "TEST2" << endl;
    int res = 1;
    for(int i = 0; i < n - 1; ++i) {
        //cout << i << endl;
        int l = i, r = n - 2, lc = l - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            //cout << l << " " << r << endl;
            //cout << i << " " << mid << " " << sp.query(i, mid) << endl;
            if(sp.query(i, mid) != 1)
                l = mid + 1, lc = mid;
            else
                r = mid - 1;
        }
        res = max(res, (lc - i) + 2);
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
        tc();
    return 0;
}