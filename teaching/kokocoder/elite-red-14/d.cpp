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
struct segment_tree {

};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // minimum between last few
    map<ll, int> p;
    ll pr[n + 1];
    pr[0] = 0;
    for(int i = 1; i <= n; ++i)
        pr[i] = pr[i - 1] + a[i];
    int cur_m = 0;
    ll res = 0;
    p[0] = 1;
    for(int i = 1; i <= n; ++i) {
        // cari l terjauh yang mungkin, antara l dan i - 1, cari maksimum
        cur_m = max(cur_m, p[pr[i]]);
        p[pr[i]] = i + 1;
        //cout << cur_m << " ";
        res += i - cur_m;
    }
    //cout << endl;
    cout << res << endl;
    return 0;
}