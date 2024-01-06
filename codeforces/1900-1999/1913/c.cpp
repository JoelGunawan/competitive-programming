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
    int m;
    cin >> m;
    int cnt[30];
    memset(cnt, 0, sizeof(cnt));
    while(m--) {
        int a, b;
        cin >> a >> b;
        if(a == 1) {
            // add
            ++cnt[b];
        }
        else {
            // get
            for(int i = 29; i >= 0; --i) {
                int cur = min(cnt[i], b / (1 << i));
                b -= cur * (1ll << i);
            }
            //cout << b << endl;
            cout << (b ? "NO" : "YES") << endl;
        }
    }
    return 0;
}