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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    sort(a, a + n);
    // coba by b terkecil terus get free gitu?
    // tapi ada countercase gampang kan
    // soalnya bisa jadi ambil yang gede 1 doang lebih kecil dari ambil yang kecil 2 biji
    int res = INT_MAX;
    for(int i = 0; i < (1 << n); ++i) {
        int tmp = 0, cnt = 0;
        for(int j = 0; j < n; ++j) {
            if((1 << j) & i)
                tmp += a[j].se, ++cnt;
        }
        bool ans = 1;
        for(int j = 0; j < n; ++j) {
            if((1 << j) & i)
                continue;
            if(cnt < a[j].fi)
                ans = 0;
            else
                ++cnt;
        }
        //cout << ans << " " << i << " " << tmp << endl;
        if(ans)
            res = min(res, tmp);
    }
    cout << res << endl;
    return 0;
}