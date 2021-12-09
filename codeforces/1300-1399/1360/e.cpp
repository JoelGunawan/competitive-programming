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
        char arr[n][n];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> arr[i][j];
        bool ans = 1;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                if(arr[i][j] == '1') {
                    // either arr[i + 1][j] has to be 1
                    // or arr[i][j + 1] has to be 1
                    bool x = 1, y = 1;
                    if(i + 1 < n && arr[i + 1][j] == '0')
                        x = 0;
                    if(j + 1 < n && arr[i][j + 1] == '0')
                        y = 0;
                    if(!(x || y))
                        ans = 0;
                }
            }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}