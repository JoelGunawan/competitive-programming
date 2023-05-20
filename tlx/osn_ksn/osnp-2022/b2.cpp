#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin >> k;
    int p[k + 1], c[k + 1];
    pair<int ,int> a[k + 1];
    for(int i = 1; i <= k; ++i)
        cin >> p[i];
    for(int i = 1; i <= k; ++i)
        cin >> c[i], a[i] = {c[i], p[i]};
    sort(a + 1, a + k + 1);
    int n;
    cin >> n;
    int b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    sort(b + 1, b + n + 1, greater<int>());
    // b[i] terbesar dengan c[i] terkecil
    int idx = 1;
    long long res = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[idx].second == 0)
            ++idx;
        res += 1ll * b[i] * a[idx].first;
        --a[idx].second;
    }
    cout << res << endl;
}