#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int g[n];
        for(int i = 0; i < n; ++i)
            cin >> g[i];
        sort(g, g + n);
        // check for no cuts
        int sum = 0;
        for(int i = 0; i < n; ++i)
            sum += g[i];
        if(sum <= m) {
            cout << -1 << endl;
            continue;
        }
        int left = 0, right = g[n - 1], res = 0;
        while(left <= right) {
            int mid = (left + right) / 2; sum = 0;
            for(int i = 0; i < n; ++i)
                sum += min(g[i], mid);
            if(sum <= m)
                left = mid + 1, res = mid;
            else
                right = mid - 1;
        }
        cout << res << endl;
    }
    return 0;
}