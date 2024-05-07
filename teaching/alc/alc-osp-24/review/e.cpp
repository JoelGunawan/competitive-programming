#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int op = 0; op < t; ++op) {
        int n;
        cin >> n;
        int a[n + 1];
        int mn = 1e9;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i] == mn)
                ++cnt;
        }
        if(cnt == 1) {
            cout << "YES" << endl;
        }
        else {
            // cek apakah semua a itu kelipatan min
            bool kel_min = 1;
            for(int i = 1; i <= n; ++i) {
                if(a[i] % mn)
                    kel_min = 0;
            }
            if(kel_min)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
}