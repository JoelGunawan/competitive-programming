#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[m], b[m], c[m];
    for(int i = 0; i < m; ++i)
        cin >> a[i] >> b[i] >> c[i];
    for(int i = 0; i < m; ++i)
        if(a[i] > b[i])
            swap(a[i], b[i]);
    int out = 1e9;
    for(int i = 0; i < (1 << m); ++i) {
        int res[m];
        memset(res, 0, sizeof(res));
        for(int j = 0; j < m; ++j) {
            if((1 << j) & i) {
                // tambah right segment
                for(int k = b[j]; k != a[j]; k = (k + 1) % m)
                    ++res[k];
            }
            else {
                for(int k = a[j]; k < b[j]; ++k)
                    ++res[k];
            }
        }
        int mx = 0;
        for(int j = 0; j < m; ++j)
            mx = max(mx, res[j]);
        out = min(out, mx);
    }
    cout << out << endl;
}