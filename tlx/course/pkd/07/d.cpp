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
void solve() {
    string s;
    cin >> s;
    int memo[s.size() + 1], cur[s.size()];
    memset(memo, 0, sizeof(memo));
    for(int i = 0; i < s.size(); ++i) {
        memset(cur, 0, sizeof(cur));
        // cari pairing palindrome valid yang lebih besar dari sama dengan i
        for(int j = i; j < s.size(); ++j) {
            if(s[i] == s[j]) {
                // try to pair
                cur[j] = memo[j + 1] + 1;
                if(i != j)
                    ++cur[j];
            }
        }
        for(int j = s.size() - 1; j >= 0; --j) {
            memo[j] = max({memo[j], memo[j + 1], cur[j]});
        }
    }
    int res = 0;
    for(int i = 0; i < s.size(); ++i)
        res = max(res, memo[i]);
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    while(n--)
        solve();
    return 0;
}