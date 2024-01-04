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
        vector<pair<int, char>> sm, lg;
        string s;
        cin >> s;
        int idx = 0;
        for(auto i : s) {
            if(i == 'b') {
                if(sm.size())
                    sm.pop_back();
            }
            else if(i == 'B') {
                if(lg.size())
                    lg.pop_back();
            }
            else if(i >= 'a' && i <= 'z') {
                sm.pb(mp(idx, i));
            }
            else {
                lg.pb(mp(idx, i));
            }
            ++idx;
        }
        vector<pair<int, char>> v;
        for(auto i : sm)
            v.pb(i);
        for(auto i : lg)
            v.pb(i);
        sort(v.begin(), v.end());
        for(auto i : v)
            cout << i.se;
        cout << endl;
    }
    return 0;
}