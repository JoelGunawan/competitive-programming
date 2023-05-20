#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int x[k + 1], c[k + 1];
        for(int i = 1; i <= k; ++i) 
            cin >> x[i];
        for(int i = 1; i <= k; ++i)
            cin >> c[i];
        int cur = 0;
        string res = "";
        bool ans = 1;
        if(c[1] > x[1]) {
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < c[1] - 3; ++i) {
            res += 'a';
        }
        cur = c[1];
        int idx = 0;
        char arr[] = {'a', 'b', 'c'};
        for(int i = c[1] - 3; i < x[1]; ++i) {
            res += arr[idx];
            ++idx;
            if(idx >= 3)
                idx -= 3;
        }
        for(int i = 2; i <= k; ++i) {
            // buat kondisi ini construct string
            // buat pola abc
            // jadi nanti
            // aaaaaabcabcabca | ddddddddddbcabcac | eeeeeeeeeeeeabcabcab | fcbacbacbacba ...
            // mulai dari d
            if(x[i] - x[i - 1] < c[i] - cur) {
                ans = 0;
                break;
            }
            for(int j = 0; j < c[i] - cur; ++j)
                res += (char)('b' + i);
            for(int j = c[i] - cur; j < x[i] - x[i - 1]; ++j) {
                res += arr[idx];
                ++idx;
                if(idx >= 3)
                    idx -= 3;
            }
            cur = c[i];
        }
        if(!ans)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << res << endl;
        }
    }
}