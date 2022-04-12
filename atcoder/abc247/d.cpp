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
    int q;
    cin >> q;
    deque<pair<int, int>> dq;
    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, c;
            cin >> x >> c;
            dq.pb(mp(c, x));
        }
        else {
            int c;
            cin >> c;
            ll res = 0;
            while(c > 0) {
                //cout << c << " " << dq.front().fi << " " << dq.front().se << endl;
                if(c >= dq.front().fi) {
                    res += 1ll * dq.front().fi * dq.front().se;
                    c -= dq.front().fi;
                    dq.pop_front();
                }
                else {
                    res += 1ll * c * dq.front().se;
                    dq.front().fi -= c;
                    c = 0;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}