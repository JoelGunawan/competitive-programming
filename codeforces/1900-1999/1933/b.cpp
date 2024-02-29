// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int cnt[3];
        memset(cnt, 0, sizeof(cnt));
        int cur = 0;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            ++cnt[x % 3];
            cur += x;
            cur %= 3;
        }
        if(cur == 0) {
            cout << 0 << endl;
        }
        else if(cur == 2) {
            cout << 1 << endl;
        }
        else {
            if(cnt[1])
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
    return 0;
}