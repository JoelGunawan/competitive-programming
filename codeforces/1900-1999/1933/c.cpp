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
        ll a, b, l;
        cin >> a >> b >> l;
        // a^x * b^y * k = l
        // find vals of k
        // find pairs of possible x, y
        set<int> s;
        ll cur1 = 1;
        for(int i = 0; i <= 25; ++i) {
            ll cur2 = 1;
            for(int j = 0; j <= 25; ++j) {
                if(l % (1ll * cur1 * cur2) == 0)
                    s.ins(l / cur1 / cur2);
                else
                    break;
                cur2 *= b;
            }
            cur1 *= a;
            if(l % cur1)
                break;
        }
        cout << s.size() << endl;
    }
    return 0;
}