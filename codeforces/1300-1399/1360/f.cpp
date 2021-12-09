#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        // just to avoid bugs
        if(n == 1) {
            string x;
            cin >> x;
            cout << x << endl;
            continue;
        }
        string strings[n];
        for(int i = 0; i < n; ++i)
            cin >> strings[i];
        string res;
        for(int i = 0; i < m; ++i)
            res += '?';
        bool ans = 0;
        // we know that it must differ by only 1 from the first string
        for(int i = 0; i < m; ++i) {
            // select the ith character to be not selected in res
            for(int j = 0; j < m; ++j) {
                if(j != i)
                    res[j] = strings[0][j];
                else
                    res[j] = '?';
            }
            bool changed = 0, valid = 1;
            for(int j = 1; j < n; ++j) {
                int diff = 0;
                for(int k = 0; k < m; ++k) {
                    if(strings[j][k] != res[k] && (i != k || changed)) {
                        // kalo udah diganti tambah ke diff
                        ++diff;
                        if(!changed)
                            res[i] = strings[j][i];
                        changed = 1;
                    }
                }
                if(diff > 1)
                    valid = 0;
            }
            if(valid) {
                if(!changed)
                    res[i] = strings[0][i];
                ans = 1;
                break;
            }
        }
        if(ans)
            cout << res << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}