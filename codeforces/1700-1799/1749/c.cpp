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
void tc() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int pref[n + 1];
    memset(pref, 0, sizeof(pref));
    for(int i = 1; i <= n; ++i)
        ++pref[a[i]];
    for(int i = 1; i <= n; ++i)
        pref[i] += pref[i - 1];
    int mx = 0;
    for(int i = 1; i <= n; ++i) {
        bool can = 1;
        for(int j = 1; j <= i; ++j) {
            //cout << i << " " << pref[j] << " " << i + j - 1 << endl;
            if(pref[j] < i + j - 1)
                can = 0;
        }
        if(can)
            mx = i;
    }
    cout << mx << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}