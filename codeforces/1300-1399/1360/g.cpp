#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        bool res[n][m];
        int remaining[m];
        memset(res, 0, sizeof(res));
        fill(remaining, remaining + m, b);
        bool valid = 1;
        for(int i = 0; i < n; ++i) {
            int cur = a;
            bool found = 1;
            while(found && cur > 0) {
                int idx = 0;
                for(int j = 0; j < m; ++j)
                    if(remaining[j] > remaining[idx])
                        idx = j;
                found = remaining[idx] != 0;
                if(remaining[idx])
                    --cur, --remaining[idx], res[i][idx] = 1;
            }
            if(cur > 0)
                valid = 0;
        }
        for(int i = 0; i < m; ++i)
            if(remaining[i] > 0)
                valid = 0;
        if(valid) {
            cout << "YES" << endl;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j)
                    cout << (int)res[i][j];
                cout << endl;
            }
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}