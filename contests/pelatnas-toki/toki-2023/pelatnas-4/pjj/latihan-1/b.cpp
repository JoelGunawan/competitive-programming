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
int mod[2] = {998244353, (int)1e9 + 7};
ll fact[2][505], inv[2][505];
ll powmod(ll a, ll b, int idx) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2, idx);
        tmp = (tmp * tmp) % mod[idx];
        return b & 1 ? (tmp * a) % mod[idx] : tmp;
    }
}
ll mul(ll a, ll b, int idx) {
    return (a * b) % mod[idx];
}
ll combin(ll a, ll b) {
    //cout << "COMBIN " << a << " " << b << endl;
    ll ret1 = mul(fact[0][a], mul(inv[0][b], inv[0][a - b], 0), 0), ret2 = mul(fact[1][a], mul(inv[1][b], inv[1][a - b], 1), 1);
    //cout << fact[0][a] << " " << inv[0][b] << " " << inv[0][a - b] << endl;
    //cout << ret1 << " " << ret2 << endl;
    if(ret1 == ret2)
        return ret1;
    else
        return 1e9;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    fact[0][0] = fact[1][0] = inv[0][0] = inv[1][0] = 1;
    for(int i = 0; i < 2; ++i) {
        for(int j = 1; j <= 500; ++j) {
            fact[i][j] = (fact[i][j - 1] * j) % mod[i];
            inv[i][j] = powmod(fact[i][j], mod[i] - 2, i);
        }
    }
    // choose max k
    // simpan vis pakai map
    // turunin per node aja, choose max yg diturunin yg mana
    // simpan max dan second max, jadi transisi O(1), trus ntar precompute
    // simpan: visited, max - second_max
    // cek max/second_max, cek mana yg harusnya optimal di delete
    // max - second_max bs pake pq
    // problem: komputasi butuh NCK
    // NCK -> cari tanpa i, cost jadi berapa, pilih yang paling besar costnya
    // nanti memo cost berapa, jadi NCK + NClogN
    int n, k, c;
    cin >> n >> k >> c;
    int grid[n][k];
    pair<int, int> mx[k][n];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < k; ++j)
            cin >> grid[i][j], mx[j][i] = mp(grid[i][j], i);
    // fi -> cost
    // se.fi -> mx arr
    // se.se -> index nxt nya dimana
    priority_queue<pair<int, pair<vector<int>, int>>> pq;
    ll initc = 0;
    for(int i = 0; i < k; ++i) {
        sort(mx[i], mx[i] + n);
        reverse(mx[i], mx[i] + n);
        int ret = 0;
        for(int j = 0; j < n; ++j)
            ret = max(ret, grid[j][i]);
        initc += ret;
    }
    vector<int> tmp;
    for(int i = 0; i < k; ++i)
        tmp.pb(0);
    pq.push(mp(initc, mp(tmp, 0)));
    // simpan vector<int> yg isinya max yg diambil itu max yg ke brp
    // tiap proses -> K^2
    // cek valid/invalid, skip invalid states?
    // gimana cara skip invalid states?
    // kalo ada duplicate di maxnya, berarti ada beberapa yang harus diganti barengan
    // obs max pengubahan cuman 1
    // k <= 2 -> try every pair
    // n <= 100 -> 
    map<vector<int>, bool> vis;
    // fi: cost
    // se: index elem yg di geser/remove
    map<vector<int>, vector<pair<int, int>>> nxt;
    ll combinations = 0;
    while(pq.size()) {
        int cost = pq.top().fi;
        vector<int> a = pq.top().se.fi;
        int idx = pq.top().se.se;
        //cout << cost << " " << idx << endl;
        pq.pop();
        if(idx != 0) {
            if(idx != nxt[a].size() - 1) {
                pq.push(mp(nxt[a][idx + 1].fi, mp(a, idx + 1)));
            }
            int cur = nxt[a][idx].se;
            for(int i = 0; i < k; ++i) {
                if(mx[i][a[i]].se == cur)
                    ++a[i];
            }
            pq.push(mp(cost, mp(a, 0)));
            continue;
        }
        if(vis[a])
            continue;
        vis[a] = 1;
        // coba cari transisi yg mgkn
        // residue state yg dimasukkin harus dikit doang (fractured search)
        // coba cek mandatory/allowednya dlu :D
        bool mandatory[n], allowed[n];
        memset(mandatory, 0, sizeof(mandatory));
        memset(allowed, 1, sizeof(allowed));
        vector<int> mand_loc[n];
        for(int i = 0; i < k; ++i) {
            for(int j = 0; j < a[i]; ++j) {
                allowed[mx[i][j].se] = 0;
            }
            mandatory[mx[i][a[i]].se] = 1;
            mand_loc[mx[i][a[i]].se].pb(i);
        }
        bool change = 0;
        for(int i = 0; i < k; ++i) {
            while(!allowed[mx[i][a[i]].se]) {
                cost += mx[i][a[i] + 1].fi - mx[i][a[i]].fi;
                ++a[i];
                change = 1;
            }
        }
        if(change) {
            // berarti push ke pq new valuenya
            pq.push(mp(cost, mp(a, 0)));
            continue;
        }
        int allow_cnt = 0, mandatory_cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(allowed[i])
                ++allow_cnt;
            if(mandatory[i])
                ++mandatory_cnt;
            // mandatory but not allowed -> no choice for cur
        }
        // tambah combination
        combinations += combin(allow_cnt - mandatory_cnt, k - mandatory_cnt);
        //cout << cost << " " << combinations << endl;
        if(combinations >= c) {
            cout << cost << endl;
            return 0;
        }
        // cari next, simpan mandatory di mana aja, nanti coba reduce
        // cek bs reduce max atau ga
        if(allow_cnt == k)
            continue;
        vector<pair<int, int>> tmp;
        for(int i = 0; i < n; ++i) {
            if(mand_loc[i].size()) {
                int nc = cost;
                // calculate new cost?
                for(auto j : mand_loc[i]) {
                    nc += mx[j][a[j] + 1].fi - mx[j][a[j]].fi;
                }
                tmp.pb(mp(nc, i));
            }
        }
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
        if(tmp.size() == 1) {
            for(auto j : mand_loc[tmp[0].se]) {
                ++a[j];
            }
            pq.push(mp(tmp[0].fi, mp(a, 0)));
        }
        else {
            nxt[a] = tmp;
            pq.push(mp(tmp[1].fi, mp(a, 1)));
            for(auto j : mand_loc[tmp[0].se]) {
                ++a[j];
            }
            pq.push(mp(tmp[0].fi, mp(a, 0)));
        }
    }
    return 0;
}