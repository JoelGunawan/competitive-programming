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
    string s;
    cin >> n >> s;
    // cntzero == cntone
    // always possible, find algo
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '0')
            ++cnt0;
        else
            ++cnt1;
    }
    if(cnt0 != cnt1) {
        cout << -1 << endl;
        return;
    }
    // cnt0 and cnt1
    vector<int> ops;
    while(true) {
        bool op = 0;
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] == s[r]) {
                if(s[l] == '0') {
                    s.insert(r + 1, "01");
                    ops.pb(r + 1);
                }
                else {
                    s.insert(l, "01");
                    ops.pb(l);
                }
                op = 1;
                break;
            }
            ++l;
            --r;
        }
        if(!op)
            break;
    }
    cout << ops.size() << endl;
    for(auto i : ops)
        cout << i << " ";
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}