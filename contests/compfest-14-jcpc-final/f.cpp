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
int mod = 998244353;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, f;
    cin >> n >> f;
    if(f == 1) {
        if(n == 1)
            cout << 1 << endl;
        else {
            cout << 1 << " ";
            for(int i = 2; i < n; ++i)
                cout << 0 << " ";
            cout << 1 << endl;
        }
        return 0;
    }
    // make "free" precomputation
    // has left/right
    // "free" -> can start from low/high
    // predetermined start
    /*
    for(int i = 1; i <= n; ++i) {
        vector<int> tmp;
        for(int j = 1; j <= i; ++j)
            tmp.pb(j);
        int cnt = 0;
        do {
            bool add = 1;
            if(tmp[0] != 1)
                add = 0;
            for(int k = 0; k < tmp.size() - 1; ++k) {
                if(abs(tmp[k] - tmp[k + 1]) > 2)
                    add = 0;
            }
            if(add)
                ++cnt;
        } while(next_permutation(tmp.begin(), tmp.end()));
        cout << cnt << endl;
    }
    */
    int a[n + 5];
    a[0] = a[1] = a[2] = 1;
    a[3] = 2;
    for(int i = 4; i <= n; ++i) {
        a[i] = a[i - 1] + a[i - 3] + 1;
        a[i] %= mod;
    }
    ll ans[n + 1];
    for(int i = 1; i <= n; ++i) {
        if(i == 1 || i == n) {
            ans[i] = a[n];
        }
        else {
            int l = i - 1, r = n - i;
            if(l > r)
                swap(l, r);
            if(l == r)
                ans[i] = 2;
            else {
                // case l angka lebih kecil
                int c1 = r - l;
                ans[i] = a[c1 + 1];        
                // case r angka lebih kecil
                int c2 = r - l - 1;
                ans[i] += a[c2 + 1];
                ans[i] %= mod;
            }    
        }
    }   
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}