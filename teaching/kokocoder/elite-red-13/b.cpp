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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    // buat prefix sm suffix
    int pref[n], suff[n];
    pref[0] = 0, suff[n - 1] = 0;
    for(int i = 0; i < n; ++i) {
        if(i != 0)
            pref[i] = pref[i - 1];
        if(pref[i] < m && t[pref[i]] == s[i])
            ++pref[i];
    }
    for(int i = n - 1; i >= 0; --i) {
        if(i != n - 1)
            suff[i] = suff[i + 1];
        if(suff[i] < m && t[m - 1 - suff[i]] == s[i])
            ++suff[i];
    }
    int res = 0;
    for(int i = 0; i < n; ++i) {
        // coba cari untuk pref ini, corresponding suffnya dmn
        if(!pref[i])
            continue;
        int cur = pref[i];
        int l = i + 1, r = n - 1, ans;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(cur + suff[mid] >= m)
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        //cout << ans - i << " ";
        res = max(res, ans - i);
    }
    //cout << endl;
    cout << res << endl;
    return 0;
}