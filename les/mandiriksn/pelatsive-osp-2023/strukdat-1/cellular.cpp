#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n + 1], b[m + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int j = 1; j <= m; ++j)
        cin >> b[j];
    int res = 0;
    int idxb = 1;
    for(int i = 1; i <= n; ++i) {
        while(idxb < m && abs(a[i] - b[idxb + 1]) <= abs(a[i] - b[idxb]))
            ++idxb;
        res = max(res, abs(a[i] - b[idxb]));
    }
    cout << res << endl;
}