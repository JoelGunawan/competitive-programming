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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
void tc() {
    int n, m;
    cin >> n >> m;
    // observe: lis starting point is non increasing
    int a[n + 1];
    vector<int> b;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        b.pb(x);
    }
    sort(b.begin(), b.end());
    // find index a[i] where it can be starting point of lis
    // for each index i, find lds ending at that index (in reverse)
    // cari di kanan yg a[j] > a[i] yg maksimal 
    // pakai vector buat maintain, binser query
    //cout << "TEST" << endl;
    //cout.flush();
    vector<int> v;
    int ans[n + 1];
    int mx = 0;
    for(int i = n; i >= 1; --i) {
        if(v.empty() || a[i] < v.back())
            v.pb(a[i]), ans[i] = v.size();
        else {
            // find first element of v that is >= a[i] from the back
            // worst case change last -> good
            int idx = ub(v.rbegin(), v.rend(), a[i]) - v.rbegin() - 1;
            //cout << idx << endl;
            //cout.flush();
            v[v.size() - idx - 1] = a[i];
            ans[i] = v.size() - idx;
        }
        mx = max(ans[i], mx);
    }
    vector<int> in[n + 1];
    for(int i = 1; i <= n; ++i) {
        if(ans[i] == mx) {
            //cout << "DEBUG " << i << " " << b.size() << endl;
            while(b.size() && b.back() >= a[i]) {
                in[i - 1].pb(b.back());
                b.pop_back();
            }
            //cout << "DEBUG " << i << " " << b.size() << endl;
        }
    }
    while(b.size()) {
        in[n].pb(b.back());
        b.pop_back();
    }
    for(int i = 0; i <= n; ++i) {
        if(i != 0)
            cout << a[i] << " ";
        for(auto j : in[i]) 
            cout << j << " ";
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}