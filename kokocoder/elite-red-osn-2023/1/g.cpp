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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    set<int> s[26];
    string init;
    cin >> init;
    init = " " + init;
    for(int i = 0; i < 26; ++i)
        s[i].ins(init.size() + 1);
    for(int i = 1; i < init.size(); ++i) {
        s[init[i] - 'a'].insert(i);
    }
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int pos; char in;
            cin >> pos >> in;
            s[init[pos] - 'a'].erase(pos);
            init[pos] = in;
            s[init[pos] - 'a'].insert(pos);
        }
        else {
            int cnt = 0, l, r;
            cin >> l >> r;
            for(int i = 0; i < 26; ++i) {
                if(*s[i].lb(l) <= r)
                    ++cnt;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}