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
const int lim = 2e5 + 5;
// simpan klo in ke node nd max brp
long long sum[lim], res = 0;
ll val[lim];
int par[lim];
vector<int> child[lim];
void calc_sum(int nd) {
    sum[nd] = val[nd];
    res += 1ll * val[nd] * (val[nd] - 1);
    for(auto i : child[nd]) {
        par[i] = nd;
        calc_sum(i);
        sum[nd] += sum[i];
    }
}
int alt;
int find_node(int nd) {
    pair<ll, int> mxc = {-1, 0};
    for(auto i : child[nd]) {
        mxc = max(mxc, {sum[i], i});
    }
    if(mxc.fi < sum[1] / 2) {
        return nd;
    }
    else {
        return find_node(mxc.se);
    }
}
vector<int> edges[lim];
bool vis[lim];
ll ns[lim];
void dfs(int nd, int o) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i, o);
            ns[nd] += ns[i];
        }
    }
    if(nd != o)
        res += ns[nd] * val[nd];
    ns[nd] += val[nd];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // pilih 1 node buat di mitm
    // bisa coba 2 node, pilih dimana yg inputnya sm yg outputnya
    // tapi pilih node yg mana???
    // subtree with largest depth yg sizenya >= sum / 2
    // pasti optimal?
    // yes i think :D
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    for(int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        child[x].pb(i);
        edges[x].pb(i);
        edges[i].pb(x);
    }
    calc_sum(1);
    int nd = find_node(1);
    // mitm !!!
    vector<ll> sums;
    for(auto i : child[nd])
        sums.pb(sum[i]);
    if(nd != 1)
        sums.pb(sum[1] - sum[nd]);
    // base in itu val[nd]
    // bagi sums jadi 2 bagian, nanti cari yg sumnya paling mendekati sum / 2
    vector<ll> one, two;
    // mitm algo udah bener
    // berarti kurang find optimal node algo
    // coba cek anaknya juga, sapa tau optimal?
    // atau mungkin parentnya? :thonk:
    for(int i = 0; i < sums.size(); ++i) {
        if(i & 1)
            one.pb(sums[i]);
        else
            two.pb(sums[i]);
    }
    if(one.empty())
        one.pb(0);
    vector<ll> a, b;
    for(int i = 0; i < (1 << one.size()); ++i) {
        ll tmp = 0;
        for(int j = 0; j < one.size(); ++j) {
            if((1 << j) & i)
                tmp += one[j];
        }
        a.pb(tmp);
    }
    for(int i = 0; i < (1 << two.size()); ++i) {
        ll tmp = 0;
        for(int j = 0; j < two.size(); ++j) {
            if((1 << j) & i)
                tmp += two[j];
        }
        b.pb(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll wi = sum[1] - val[nd];
    ll target = wi / 2 + wi % 2;
    ll cl_low = 0, cl_high = wi;
    //cout << res << endl;
    for(auto i : a) {
        if((lower_bound(b.begin(), b.end(), target - i)) != b.end()) {
            cl_high = min(cl_high, *lower_bound(b.begin(), b.end(), target - i) + i);
        }        
        if((lower_bound(b.begin(), b.end(), target - i)) != b.begin()) {
            cl_low = max(cl_low, *--lower_bound(b.begin(), b.end(), target - i) + i);
        }
    }
    if(cl_high - target >= wi / 2 - cl_low) {
        //cout << cl_low << " " << sum[1] - cl_low - val[nd] << endl;
        res += (cl_low) * (wi - cl_low);
        //cout << val[nd] << " " << sum[1] - val[nd] << endl;
    }
    else {
        res += (cl_high) * (wi - cl_high);
    }
    res += val[nd] * (sum[1] - val[nd]);
    //cout << res << endl;
    dfs(nd, nd);
    cout << res << endl;
    return 0;
}