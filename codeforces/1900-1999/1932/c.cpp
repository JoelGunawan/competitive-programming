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
        int n, m;
        cin >> n >> m;
        int a[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        string s;
        cin >> s;
        s = " " + s;
        int l = 1, r = n;
        for(int i = 1; i <= n; ++i) {
            if(s[i] == 'L')
                ++l;
            else
                --r;
        }
        ll ans[n + 1], cur = 1;
        for(int i = n; i >= 1; --i) {
            if(s[i] == 'L')
                --l, cur = (cur * a[l]) % m;
            else
                ++r, cur = (cur * a[r]) % m;
            ans[i] = cur;
        }
        for(int i = 1; i <= n; ++i)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}