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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = " " + s;
        int pre[s.size() + 1], suff[s.size() + 1];
        set<char> a;
        memset(pre, 0, sizeof(pre));
        memset(suff, 0, sizeof(suff));
        for(int i = 1; i <= n; ++i)
            a.insert(s[i]), pre[i] = a.size();
        a.clear();
        for(int i = n; i >= 1; --i)
            a.insert(s[i]), suff[i] = a.size();
        int mx = 0;
        for(int i = 1; i <= n; ++i)
            mx = max(mx, pre[i] + suff[i + 1]);
        cout << mx << endl;
    }
    return 0;
}