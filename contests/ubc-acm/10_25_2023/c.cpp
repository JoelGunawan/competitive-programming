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
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    set<int> s;
    bool first[n + 1], last[n + 1];
    memset(first, 0, sizeof(first));
    memset(last, 0, sizeof(last));
    for(int i = 1; i <= n; ++i) {
        if(!s.count(a[i]))
            first[i] = 1;
        s.ins(a[i]);
    }
    s.clear();
    for(int i = n; i >= 1; --i) {
        if(!s.count(a[i]))
            last[i] = 1;
        s.ins(a[i]);
    }
    s.clear();
    int cnt_last[n + 2];
    memset(cnt_last, 0, sizeof(cnt_last));
    for(int i = n; i >= 1; --i) {
        cnt_last[i] = cnt_last[i + 1] + last[i];
    }
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        res += first[i] * cnt_last[i];
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // a given l is valid if it is the first occur of elemm
    // a given r is valid if it is the last occur of elem
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}