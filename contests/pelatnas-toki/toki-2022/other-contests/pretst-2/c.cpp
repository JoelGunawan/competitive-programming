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
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    if(q <= 500) {
        int dp[2][1 << 14];
        vector<pair<int, int>> cur;
        // fi == 1 -> and
        // fi == 2 -> or
        // fi == 3 -> xor
        while(q--) {
            string type;
            cin >> type;
            if(type == "QUERY") {
                memset(dp, 0, sizeof(dp));
                dp[0][0] = 1;
                int val;
                cin >> val;
                bool z = 0;
                for(auto x : cur) {
                    z = !z;
                    for(int i = 0; i < 1 << 14; ++i)
                        dp[z][i] = 0;
                    for(int i = 0; i < 1 << 14; ++i) {
                        int tmp;
                        if(x.fi == 1)
                            tmp = i & x.se;
                        else if(x.fi == 2)
                            tmp = i | x.se;
                        else
                            tmp = i ^ x.se;
                        dp[z][tmp] += dp[!z][i];
                        dp[z][i] += dp[!z][i];
                    }
                }
                cout << dp[z][val] << endl;
            }
            else if(type == "REMOVE")
                cur.pop_back();
            else {
                int x;
                cin >> x;
                if(type == "AND")
                    cur.push_back(mp(1, x));
                else if(type == "OR")
                    cur.push_back(mp(2, x));
                else
                    cur.push_back(mp(3, x));
            }
        }
        // for all xor
        // try to do a persistent dsu kind of
        // we merge 2 elements (multiply sum by 2 for merge)
        // for in merge, multiply by 2
        // for out merge, multiply by 2 as well, but we need merge logic for unmerging
        // possibly use a dsu like structure (not really)

        // for all or
        // try an inverse approach
        // as we can calculate prev using inverses
        // for and, we can do the same thing as or (for full sol)
        
        // how to do xor together with or and and is confusing
        /*
        vector<node> a(1 << 14);
        a[0].res = 1;
        int q;
        cin >> q;
        for(int i = 0; i < q; ++i) {
            // each index itu ada nodenya, tiap node ada head
            string type;
            cin >> type;
            if(type == "QUERY") {
                int x;
                cin >> x;
                // kalo misal sama, kalikan 2
                // untuk merge, repot jika ada 2 merge
            }
            else if(type == "REMOVE") {
                // remove multiply from top level
                // or remove
            }
            else {
                int x;
                cin >> x;
                // untuk merging agak repot, kita harus bisa hindari double merging
            }
        }
        */
       return 0;
    }
    int dp[2][1 << 14], gl = powmod(2, mod - 2), cur, val;
    bool idx = 0;
    dp[idx][0] = 1;
    int queries[(int)1e4 + 1], q_size = 0;
    while(q--) {
        string type;
        cin >> type;
        if(type == "QUERY") {
            cin >> val;
            cout << dp[idx][val] << endl;
        }
        else if(type == "REMOVE") {
            for(int i = 0; i < 1 << 14; ++i)
                dp[!idx][i] = 0;
            cur = queries[q_size - 1];
            --q_size;
            for(int i = 0; i < 1 << 14; ++i) {
                if((i | cur) == i) {
                    dp[!idx][i] += dp[idx][i];
                    dp[!idx][i] %= mod;
                }
                else {
                    dp[!idx][i] += dp[idx][i];
                    dp[!idx][i] %= mod;
                    dp[!idx][i | cur] -= dp[idx][i];
                    dp[!idx][i | cur] = (1ll * dp[!idx][i | cur] + mod) % mod;
                }
            }
            for(int i = 0; i < 1 << 14; ++i) {
                if((i | cur) == i)
                    dp[!idx][i] = (1ll * dp[!idx][i] * gl) % mod;
            }
            idx = !idx;
        }
        else {
            cin >> val;
            queries[q_size++] = val;
            for(int i = 0; i < 1 << 14; ++i)
                dp[!idx][i] = 0;
            for(int i = 0; i < 1 << 14; ++i) {
                dp[!idx][i | val] += dp[idx][i];
                dp[!idx][i | val] %= mod;
                dp[!idx][i] += dp[idx][i];
                dp[!idx][i] %= mod;
            }
            idx = !idx;
        }
    }
    return 0;
}