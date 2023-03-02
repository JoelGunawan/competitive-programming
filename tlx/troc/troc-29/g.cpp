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
const int lim = 3e5 + 5;
int sz[lim];
bool vis[lim];
int cnt[lim];
vector<int> edges[lim];
struct disjoint_set {
    int head[lim], size[lim];
    map<int, int> a[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int fh(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    void merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y];
            head[y] = x;
            for(auto i : a[y]) {
                a[x][i.fi] += i.se;
            }
        }
    }
};
// kalo sampe ke node itu terus sz merupakan faktor, tapi tidak bisa, maka pasti tidak bisa, dia udah tidak bisa, di atasnya ga usah di cek karena pasti tidak bisa
disjoint_set dsu;
vector<int> prime_factors[lim];
ll cur_factor = 1;
vector<pair<int, int>> prime_factorization;
vector<int> factors;
void generate_factors(int idx) {
    if(idx == prime_factorization.size()) {
        factors.pb(cur_factor);
        return;
    }
    int tmp = 1;
    for(int i = 0; i <= prime_factorization[idx].se; ++i) {
        generate_factors(idx + 1);
        cur_factor *= prime_factorization[idx].fi;
    }
    for(int i = 0; i <= prime_factorization[idx].se; ++i) {
        cur_factor /= prime_factorization[idx].fi;
    }
}
void dfs(int nd) {  
    vis[nd] = 1;
    sz[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            dfs(i), sz[nd] += sz[i], dsu.merge(nd, i);
    }
    ++dsu.a[dsu.fh(nd)][sz[nd]];
    // coba tiap faktor
    int tmp = dsu.fh(nd);
    for(auto i : prime_factors[sz[nd]]) {
        if(i == 1)
            continue;
        int tmp = sz[nd];
        int cnt = 0;
        while(tmp % i == 0)
            tmp /= i, ++cnt;
        prime_factorization.pb(mp(i, cnt));
    }
    //cout << "PRIME FACT" << endl;
    //for(auto i : prime_factorization)
    //    cout << i.fi << " " << i.se << endl;
    generate_factors(0);
    prime_factorization.clear();
    for(auto i : factors) {
        //cout << sz[nd] << " " << nd << " " << i << " " << dsu.a[tmp][i] << endl;
        if(i == sz[nd])
            continue;
        if(dsu.a[tmp][i] == sz[nd] / i - 1) {
            ++dsu.a[tmp][i];
        }
        else
            cnt[i] += dsu.a[tmp][i], dsu.a[tmp][i] = 0;
    }
    factors.clear();
}
void sieve() {
    bool a[lim];
    memset(a, 1, sizeof(a));
    for(int i = 1; i < lim; ++i)
        prime_factors[i].pb(1);
    for(int i = 2; i < lim; ++i) {
        if(a[i]) {
            prime_factors[i].pb(i);
            for(int j = 2 * i; j < lim; j += i) {
                prime_factors[j].pb(i);
                a[j] = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    sieve();
    dfs(1);
    for(auto i : dsu.a[dsu.fh(1)]) {
        cnt[i.fi] += i.se;
    }
    //for(int i = 1; i <= n; ++i)
    //    cout << cnt[i] << " ";
    //cout << endl;
    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; ++i) {
        int tmp = n - cnt[i] * i;
        //cout << i << " " << tmp << endl;
        if(tmp == 0)
            ans[cnt[i]]++;
        else if(tmp <= i) {
            ans[cnt[i] + 1]++;
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
    // try every factor of sz[nd]
    // cari di child ada berapa kemunculan hal tersebut
    // jika kemunculan * sz_group = sz[nd];
    // pakai dsu map merging (classic lah ya)
    return 0;
}