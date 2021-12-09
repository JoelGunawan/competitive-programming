#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n], b[2];
        memset(b, 0, sizeof(b));
        for(int i = 0; i < n; ++i)
            cin >> a[i], ++b[a[i] % 2];
        if(b[0] & 1) {
            sort(a, a + n);
            bool found = 0;
            for(int i = 1; i < n; ++i)
                if(a[i] == a[i - 1] + 1)
                    found = 1;
            if(found)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
    return 0;
}