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
    int n, q, m;
    cin >> n >> q >> m;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<pair<int, pair<int, int>>> queries(q);
    for(int i = 0; i < q; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        queries[i] = mp(t, mp(l, r));
    }
    reverse(queries.begin(), queries.end());
    int b[m];
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    // do the array operations but in reverse
    for(int i = 0; i < m; ++i) {
        int cur = b[i];
        for(auto j : queries) {
            if(cur >= j.se.fi && cur <= j.se.se) {
                if(j.fi == 1) {
                    if(cur == j.se.fi)
                        cur = j.se.se;
                    else
                        --cur;
                }
                else {
                    cur = j.se.se - cur + j.se.fi;
                }
            }
        }
        cout << a[cur - 1] << " ";
    }
    cout << endl;
    return 0;
}