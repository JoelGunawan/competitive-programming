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
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    ll cur = 0, res = 0;
    for(int i = n; i >= 1; --i) {
        // try to start at position i
        // if halt add all by 1, but not permanently
        if(i != n && s[i] == s[i + 1]) {
            cur += 2 * (n - i + 1) - 1;
        }
        else {
            cur += n - i + 1;
        }
        res += cur;
        if(s[i] == '0')
            res += n - i + 1;
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)  
        tc();
    return 0;
}