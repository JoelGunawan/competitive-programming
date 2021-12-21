// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    pair<bool, pair<int, int>> queries[q];
    int arr_size = 0;
    for(int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t;
        if(t == 1)
            cin >> x, queries[i] = mp(0, mp(x, 0)), ++arr_size;
        else
            cin >> x >> y, queries[i] = mp(1, mp(x, y));
    }
    reverse(queries, queries + q);
    int res[arr_size], idx = 0;
    int value[500005];
    memset(value, -1, sizeof(value));
    for(int i = 0; i < q; ++i) {
        if(queries[i].fi) {
            value[queries[i].se.fi] = value[queries[i].se.se];
            if(value[queries[i].se.fi] == -1)
                value[queries[i].se.fi] = queries[i].se.se;
        }
        else {
            res[idx++] = value[queries[i].se.fi];
            if(res[idx - 1] == -1)
                res[idx - 1] = queries[i].se.fi;
        }
    }
    reverse(res, res + arr_size);
    for(int i = 0; i < arr_size; ++i)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}