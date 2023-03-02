// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const int lim = 1e5 + 5;
vector<int> edges[lim];
int color[lim], mod = 1e9 + 7;
bool vis[lim], has_set[lim];
ll dp[lim][2];
void dfs(int nd) {
    vis[nd] = 1;
    has_set[nd] = color[nd];
    if(color[nd]) {
        dp[nd][1] = 1;
        vector<int> child;
        for(auto i : edges[nd]) {
            if(!vis[i]) {
                child.pb(i);
                has_set[nd] |= has_set[i];
                dfs(i);
                if(has_set[i])
                    dp[nd][1] *= dp[i][1];
                dp[nd][1] %= mod;
                // color -> tidak boleh ambil dari no stop (0)       
            }
        }
        //cout << nd << endl;
        //for(auto i : child)
        //    cout << i << " ";
        //cout << endl;
        dp[nd][0] = dp[nd][1];
    }
    else {
        vector<int> child;
        dp[nd][1] = 1;
        for(auto i : edges[nd]) {
            if(!vis[i]) {
                dfs(i);
                has_set[nd] |= has_set[i];
                if(has_set[i]) {
                    dp[nd][1] *= dp[i][1];
                    dp[nd][1] %= mod;
                    child.pb(i);
                }
            }
        }          
        if(child.size() == 0 || !has_set[nd]) {
            dp[nd][1] = 0;
            return;    
        }
        ll pref[child.size()], suff[child.size()];        
        pref[0] = 1;      
        suff[child.size() - 1] = 1;
        for(int i = 1; i < child.size(); ++i)
            pref[i] = (pref[i - 1] * dp[child[i - 1]][1]) % mod;
        for(int i = child.size() - 2; i >= 0; --i) {
            suff[i] = (suff[i + 1] * dp[child[i + 1]][1]) % mod;
        }
        for(int i = 0; i < child.size(); ++i) {
            //cout << "DP " << nd << " " << i << " " << dp[i][0] << " " << dp[i][1] << " " << sum << endl;
            dp[nd][0] += (dp[child[i]][0] * ((pref[i] * suff[i]) % mod)) % mod;
        }
        //cout << "ANS " << dp[nd][0] << " " << dp[nd][1] << endl;
        dp[nd][0] %= mod;
        dp[nd][1] += dp[nd][0];
        dp[nd][1] %= mod;
        //cout << nd << endl;
        //for(auto i : child)
        //    cout << i << " ";
        //cout << endl;
    }
    //cout << nd << " " << dp[nd][0] << " " << dp[nd][1] << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // create tree rooted at black vertex
    // later merge, each node consider ways to reach node, can be empty can be not empty
    // when at white -> use sum of bawah, pair from extending or below that
    // when arrive at black -> only below that
    // 2 states -> one extending, one end below that
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        edges[i].pb(p);
        edges[p].pb(i);        
    }
    for(int i = 0; i < n; ++i)
        cin >> color[i];
    dfs(0);
    cout << dp[0][0] << endl;
    return 0;
}