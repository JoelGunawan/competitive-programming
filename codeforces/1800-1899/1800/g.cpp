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
vector<int> edges[lim], child[lim];
int subtree[lim], par[lim], child_done_cnt[lim], id[lim];
bool vis[lim];
vector<vector<int>> trees;
void get_subtree(int nd) {
    vis[nd] = 1;
    subtree[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            get_subtree(i), par[i] = nd, subtree[nd] += subtree[i], child[nd].pb(i), child_done_cnt[nd]++;
    }
}
// custom compare function
// buat vektor
// sorting
// construct dari paling kecil
// size terkecil
// subtree child number terkecil
struct comp {
    bool operator()(pair<pair<int, vector<int>>, int>& a, pair<pair<int, vector<int>>, int>& b) {
        if(a.fi.fi != b.fi.fi)
            return a.fi > b.fi;
        if(a.fi.se.size() != b.fi.se.size())
            return a.fi.se.size() > b.fi.se.size();
        else
            return a.fi.se > b.fi.se;
    }
};
void tc() {
    // tiap child yang ukuran subtree sama diproses bareng
    // kalo ada yang sama, berarti lanjut ke next levelnya dia
    // kalo beda, berarti ga sama, langsung output no
    int n;
    cin >> n;
    trees.clear();
    for(int i = 1; i <= n; ++i)
        child_done_cnt[i] = 0, vis[i] = 0, id[i] = 0, subtree[i] = 0, par[i] = 0;
    for(int i = 1; i <= n; ++i)
        edges[i].clear(), child[i].clear();
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    get_subtree(1);
    for(int i = 1; i <= n; ++i)
        vis[i] = 0;
    // pake pq
    priority_queue<pair<pair<int, vector<int>>, int>, vector<pair<pair<int, vector<int>>, int>>, comp> pq;
    trees.pb({});
    for(int i = 1; i <= n; ++i) {
        if(child[i].size() == 0)
            pq.push(mp(mp(1, vector<int>()), i));
    }
    while(pq.size()) {
        int nd = pq.top().se; 
        if(vis[nd]) {
            pq.pop();
            continue;
        }
        vector<int> c = pq.top().fi.se;
        pq.pop();
        vis[nd] = 1;
        //cout << "OUTPUT" << endl;
        //cout << subtree[nd] << " " << nd << endl;
        //for(auto i : c)
        //    cout << i << " ";
        //cout << endl;
        if(c == trees.back())
            id[nd] = trees.size() - 1;
        else
            trees.pb(c), id[nd] = trees.size() - 1;
        --child_done_cnt[par[nd]];
        if(child_done_cnt[par[nd]] == 0) {
            vector<int> x;
            for(auto i : child[par[nd]]) {
                x.pb(id[i]);
            }
            sort(x.begin(), x.end(), greater<int>());
            pq.push(mp(mp(subtree[par[nd]], x), par[nd]));
        }
    }
    // cek 1, bawahnya, dst
    // ada yang sama -> 
    int cur = 1;
    while(true) {
        vector<int> childid;
        for(auto j : child[cur])
            childid.pb(id[j]);
        if(childid.size() == 0)
            break;
        sort(childid.begin(), childid.end());
        int oddidx = -1, c = 0;
        for(int i = 0; i < childid.size(); ++i) {
            if(i != 0 && childid[i] != childid[i - 1]) {
                if(c & 1) {
                    if(oddidx != -1) {
                        cout << "NO" << endl;
                        return;
                    }
                    oddidx = i - 1, c = 0;
                }
            }
            ++c;
        }
        if(c & 1) {
            if(oddidx != -1) {
                cout << "NO" << endl;
                return;
            }
            oddidx = childid.size() - 1;
        }
        //cout << c << " " << oddidx << " " << child[cur][oddidx] << endl;
        if(oddidx == -1)
            break;
        else {
            for(auto i : child[cur]) {
                if(id[i] == childid[oddidx]) {
                    cur = i;
                    break;
                }
            }
        }
    }
    cout << "YES" << endl;
    // cek langsung dari jumlah child aja?
    // kalo size subtree sama
    // nanti comparisonnya bisa beberapa barengan
    // sorting by largest subtree size
    // vector of children
    // tiap node masuk sekali aja
    // dfs(vector<int> nd)
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}