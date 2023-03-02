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
    string s;
    cin >> s;
    int res = 1;
    char a = min(s[0], s[1]), b = max(s[0], s[1]);
    for(int i = 2; i < s.size(); ++i) {
        if(min(s[i - 1], s[i]) == a && max(s[i - 1], s[i]) == b)
            continue;
        else
            ++res, a = min(s[i - 1], s[i]), b = max(s[i], s[i - 1]);
    }
    //cout << endl;
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