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
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, k, d;
        cin >> n >> k >> d;
        int a[n + 1];
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int v[max(k + 1, 2 * n + 2)];
        for(int i = 1; i <= k; ++i) {
            cin >> v[i];
        }
        if(k < 2 * n + 1) {
            for(int i = k + 1; i <= 2 * n + 1; ++i)
                v[i] = v[i % k == 0 ? k : i % k];
        }
        // only thing that matters -> first 4000 elements of v
        // 2 operations -> +1
        // try each operation from 0 to 2n
        int res = 0;
        for(int i = 0; i <= min(2 * n + 1, d - 1); ++i) {
            // find count of a[i] that is aligned for this current
            if(i != 0) {
                // process current operation
                for(int j = 1; j <= v[i]; ++j) {
                    ++a[j];
                }
            }
            int cnt = 0;
            for(int j = 1; j <= n; ++j) {
                // find count of aligned
                if(a[j] == j) {
                    ++cnt;
                }
            }
            // cout << cnt + (d - i - 1) / 2 << " ";
            res = max(res, cnt + (d - i - 1) / 2);
        }
        cout << res << endl;
    }
    return 0;
}