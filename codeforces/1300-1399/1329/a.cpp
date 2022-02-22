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
    int n, m;
    cin >> n >> m;
    pair<int, int> a[m];
    ll total_sum = 0;
    for(int i = 0; i < m; ++i) {
        int l;
        cin >> l;
        a[i] = mp(l, i);
        total_sum += l;
    }
    int ans[m + 1];
    memset(ans, -1, sizeof(ans));
    if(total_sum < n) {
        cout << -1 << endl;
        exit(0);
    }
    ll minimum = 1, maximum = 1;
    for(int i = 0; i < m; ++i) {
        // choose between minimum and maximum
        // it is always possible
        // choose minimum start_idx that still satisfies
        if(minimum + a[i].fi > n + 1)
            cout << -1 << endl, exit(0);
        else {
            // choose closest to new min
            //cout << total_sum << " " << minimum << " " << maximum << endl;
            ans[a[i].se] = max(minimum, min(maximum, n - total_sum + 1)); 
            //cout << a[i].se << " " << ans[a[i].se] << endl;
        }
        total_sum -= a[i].fi;
        minimum = ans[a[i].se] + 1, maximum = ans[a[i].se] + a[i].fi;
    }
    //cout << endl;
    for(int i = 0; i < m; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}