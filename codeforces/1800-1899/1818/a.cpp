#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] == a[0])
                ++res;
        }
        cout << res << endl;
    }
}