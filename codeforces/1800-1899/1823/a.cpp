#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        bool ans = 0;
        int x;
        for(int i = 0; i <= n; ++i) {
            int j = n - i;
            if(i * (i - 1) / 2 + j * (j - 1) / 2 == k)
                ans = 1, x = i;
        }
        if(ans) {
            cout << "YES" << endl;
            for(int i = 0; i < x; ++i)
                cout << -1 << " ";
            for(int i = 0; i < n - x; ++i)
                cout << 1 << " ";
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
}