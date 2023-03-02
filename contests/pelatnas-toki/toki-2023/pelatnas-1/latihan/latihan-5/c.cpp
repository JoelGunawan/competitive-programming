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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll lim = 1e5 + 5;
bool type[lim];
ll len[lim], file_cnt[lim], tot[lim];
vector<ll> child[lim];
ll par[lim];
void dfs(ll nd) {
    // calculate file_cnt and tot
    if(type[nd] == 0) {
        file_cnt[nd] = 1;
        tot[nd] = len[nd];
    }
    else {
        for(auto i : child[nd]) {
            dfs(i);
            file_cnt[nd] += file_cnt[i];
            // tambahin /
            if(nd == 0)
                tot[nd] += tot[i];
            else
                tot[nd] += tot[i] + file_cnt[i] * (len[nd] + 1);
        }
    }
    //cout << nd << " " << type[nd] << " " << file_cnt[nd] << " " << tot[nd] << endl;
}
ll ans;
void dfs2(int nd, ll pr_res) {
    ans = min(ans, pr_res);
    for(auto i : child[nd]) {
        if(type[i]) {
            ll tmp = pr_res;
            tmp += 3 * (file_cnt[0] - file_cnt[i]);
            tmp -= (len[i] + 1) * file_cnt[i];
            dfs2(i, tmp);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        ll t;
        cin >> t;
        len[i] = s.size();
        if(t == 0) {
            type[i] = 0;
        }
        else {
            type[i] = 1;
            for(ll j = 0; j < t; ++j) {
                ll x;
                cin >> x;
                child[i].pb(x);
                par[x] = i;
            }
        }
    }
    for(ll i = 1; i <= n; ++i)
        if(par[i] == 0)
            child[0].pb(i);
    type[0] = 1;
    dfs(0);
    ans = tot[0];
    dfs2(0, tot[0]);
    cout << ans << endl;
    return 0;
}