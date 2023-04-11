#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, s;
        cin >> m >> s;
        int b[m];
        int curs = 0;
        for(int i = 0; i < m; ++i)
            cin >> b[i], curs += b[i];
        int len = -1;
        for(int i = 1; i <= 100; ++i) {
            if(i * (i + 1) / 2 - curs == s)
                len = i;
        }
        if(len == -1) {
            cout << "NO" << endl;
            continue;
        }
        bool ans = 1;
        bool exist[len + 1];
        memset(exist, 0, sizeof(exist));
        for(int i = 0; i < m; ++i) {
            if(b[i] > len || b[i] < 0 || exist[b[i]]) {
                ans = 0;
                break;
            }
            exist[b[i]] = 1;
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}