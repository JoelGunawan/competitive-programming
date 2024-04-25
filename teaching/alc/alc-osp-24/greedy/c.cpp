#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    // paling kecil dengan paling besar
    long long res = 0;
    for(int i = 0; i < n; ++i) {
        // i dipasangkan dengan n - i - 1
        res += 1ll * a[i] * b[n - i - 1];
    }
    cout << res << endl;
}