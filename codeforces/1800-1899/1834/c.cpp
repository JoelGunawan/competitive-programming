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
int solve(string a, string b) {
    int ret = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] != b[i])
            ++ret;
    }
    return ret;
}
void tc() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int a = solve(s, t);
    reverse(s.begin(), s.end());
    int b = solve(s, t);
    int res = 1e9;
    //cout << a << " " << b << endl;
    if(a == 0)
        res = min(res, 0);
    if(b == 0)
        res = min(res, 2);
    if(a % 4 == 1) {
        res = min(res, 8 * (a / 4) + 1);
    }
    else if(a % 4 == 2) {
        res = min(res, 8 * (a / 4) + 4);
    }
    else if(a % 4 == 3) {
        res = min(res, 8 * (a / 4) + 5);
    }
    else {
        res = min(res, 8 * (a / 4));
    }
    if(b & 1)
        res = min(res, 2 * b);
    else
        res = min(res, max(2, 2 * b - 1));
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // ada 2 kemungkinan, pakai s, t awal dan pakai rev(s), t
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}