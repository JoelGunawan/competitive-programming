#include <bits/stdc++.h>
using namespace std;
int main() {
    // 2d prefsum
    // total sum - pref query
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    memset(a, 0, sizeof(a));
    int prajurit = 0;
    long long total = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if(a[i][j])
                prajurit++;
            total += a[i][j];
        }
    }    
    vector<pair<int, int>> sizes;
    for(int i = 1; i <= prajurit; ++i) {
        if(prajurit % i == 0)
            sizes.push_back({i, prajurit / i });
    }
    long long pref[n + 1][m + 1];
    memset(pref, 0, sizeof(pref));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    long long ans = -1;
    for(auto p : sizes) {
        // prefsum query
        for(int i = 1; i <= n - p.first + 1; ++i) {
            for(int j = 1; j <= m - p.second + 1; ++j) {
                ans = max(ans, pref[i + p.first - 1][j + p.second - 1] - pref[i - 1][j + p.second - 1] - pref[i + p.first - 1][j - 1] + pref[i - 1][j - 1]);
            }
        }
    }
    if(ans == -1)
        cout << ans << endl;
    else {
        cout << total - ans << endl;
    }
}