#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a + n);
        int res = 0;
        for(int i = n - 1; i >= n - 5; --i)
            res += a[i];
        cout << res << endl;
    }
    return 0;
}