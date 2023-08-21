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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll dp[20];
ll f(int n) {
    if(n == 0)
        return 1;
    if(dp[n] == -1) {
        dp[n] = 0;
        for(int i = 0; i < n; ++i)
            dp[n] += 1ll * f(i) * f(n - i - 1);
    }
    return dp[n];
}
int root;
vector<int> child[20];
void get_ans(int l, int r, int k, int par = -1) {
    // coba dr l ke r
    if(l > r)
        return;
    int cum = 0, idx = -1;
    //cout << "GET " << l << " " << r << " " << k << endl;
    for(int i = l; i <= r; ++i) {
        cum += f(i - l) * f(r - i);
        //cout << cum << " " << k << endl;
        if(cum - 1 >= k) {
            idx = i;
            cum -= f(i - l) * f(r - i);
            break;
        }
    }
    //cout << k << " " << cum << " ";
    k -= cum;
    // k buat sekarang, pisah jadi 2 bagian
    assert(idx != -1);
    if(par != -1)
        child[par].pb(idx);
    else
        root = idx;
    int lcara = f(idx - l), rcara = f(r - idx);
    //cout << k << " " << rcara << endl;
    get_ans(l, idx - 1, k / rcara, idx);
    get_ans(idx + 1, r, k % rcara, idx);
}
string s = "";
void dfs(int nd) {
    s += (char)(nd + 'a' - 1);
    for(auto i : child[nd])
        dfs(i);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    int n, k;
    cin >> n >> k;
    f(n);
    if(k > f(n)) {
        cout << "-" << endl;
        return 0;
    }
    --k;
    get_ans(1, n, k);
    dfs(root);
    cout << s << endl;
    return 0;
}