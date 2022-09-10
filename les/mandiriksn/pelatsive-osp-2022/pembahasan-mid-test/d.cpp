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
    string a, s;
    cin >> a >> s;
    string b = "";
    int a_idx = a.size() - 1, s_idx = s.size() - 1;
    bool ans = 1;
    while(a_idx >= 0 && s_idx >= 0) {
        if(s[s_idx] < a[a_idx]) {
            if(s_idx == 0 || s[s_idx - 1] != '1') 
                ans = 0;
            b += s[s_idx] + 10 - a[a_idx] + '0';
            s_idx -= 2;
            --a_idx;
        }
        else {
            b += s[s_idx] - a[a_idx] + '0';
            --s_idx, --a_idx;
        }
    }
    if(!ans || a_idx >= 0) {
        cout << -1 << endl;
        return;
    }
    while(s_idx >= 0)
        b += s[s_idx], --s_idx;
    reverse(b.begin(), b.end());
    while(b.size() > 0 && b[0] == '0')
        b.erase(0, 1);
    cout << b << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}