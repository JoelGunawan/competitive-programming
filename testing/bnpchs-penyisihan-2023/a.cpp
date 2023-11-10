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
    // consider case 
    // **....
    // ***....
    // *.....
    // .....**
    // ....***
    // .....*
    // output empty string
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    int pre[n + 1], suff[n + 2];
    memset(pre, 0, sizeof(pre));
    memset(suff, 0, sizeof(suff));
    for(int i = 1; i <= n; ++i) 
        pre[i] = pre[i - 1] + (s[i] == '*');
    for(int i = n; i >= 1; --i)
        suff[i] = suff[i + 1] + (s[i] == '*');
    string res = "";
    for(int i = 1; i <= n; ++i) {
        if(s[i] != '*' && (pre[i] % 2 == 0) && (suff[i] % 2 == 0))
            res += s[i];
    }
    cout << res << endl;
    return 0;
}