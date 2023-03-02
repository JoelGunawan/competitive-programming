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
    int n;
    cin >> n;
    int shift = 0;
    // fi -> val
    // se -> count
    vector<pair<int, int>> s;
    int size = 0;
    for(int i = 0; i < n; ++i) {
        string op;
        cin >> op;
        if(op == "add") {
            int x, y;
            cin >> x >> y;
            s.pb(mp(x - shift, y));
            size += y;
            cout << size << endl;
        }
        else if(op == "del") {
            int y;
            cin >> y;
            size -= y;
            cout << s.back().fi + shift << endl;
            while(s.size() && y) {
                if(y >= s.back().se)
                    y -= s.back().se, s.pop_back();
                else
                    s.back().se -= y, y = 0;
            }
        }
        else {
            int x;
            cin >> x;
            if(op == "adx")
                shift += x;
            else
                shift -= x;
        }
    }
    return 0;
}