#include <bits/stdc++.h>
//#define endl "\n"
#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
using namespace std;
vector<int> nxt[300001]; 
int par[19][300001];
int depth[300001];
bool vis[300001];
vector<int> cur;
void dfs(int nd) {
    int tmp1 = 1, tmp2 = 0;
    while(cur.size() >= tmp1) {
        par[tmp2][nd] = cur[cur.size() - tmp1];
        tmp1 *= 2, ++tmp2;
    }
    depth[nd] = cur.size();
    cur.pb(nd);
    for(auto i : nxt[nd])
        dfs(i);
    cur.pop_back();
}
int lca(int a, int b) {
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = 18; i >= 0; --i) {
        if(depth[a] - depth[b] >= 1 << i)
            a = par[i][a];
    }
    if(a == b)
        return a;
    for(int i = 18; i >= 0; --i) {
        if(par[i][a] != par[i][b])
            a = par[i][a], b = par[i][b];
    }
    return par[0][a];
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    // do no 3 operations subtask
    int prev[n + 1], val[n + 1], size[n + 1], equiv[n + 1];
    size[0] = 0, equiv[0] = 0, prev[0] = -1, val[0] = -1;
    vector<pair<int, int>> ans;
    // -1 on the second means that it is
    for(int i = 1; i <= n; ++i) {
        char type; int v;
        cin >> type >> v;
        if(type == 'a') {
            prev[i] = equiv[v];
            val[i] = i;
            size[i] = size[v] + 1;
            equiv[i] = i;
            nxt[equiv[v]].pb(i);
        }
        else if(type == 'b') {
            prev[i] = prev[prev[v]];
            val[i] = val[prev[v]];
            size[i] = size[prev[v]];
            equiv[i] = equiv[prev[v]];
            nxt[prev[prev[v]]].pb(equiv[i]);
            ans.pb(mp(val[v], -1));
        }
        else {
            val[i] = val[v];
            prev[i] = prev[v];
            size[i] = size[v];
            equiv[i] = equiv[v];
            nxt[prev[v]].pb(equiv[i]);
            int cur = equiv[i];
            int w;
            cin >> w;
            // find lowest common ancestor between w and v
            w = equiv[w];
            ans.pb(mp(equiv[v], equiv[w]));
        }
    }
    // jadiin binlift buat lca
    // dfs dari next
    dfs(0);
    for(pair<int, int> i : ans) {
        if(i.se == -1)
            cout << i.fi << endl;
        else {
            // output size of lca between i.fi and i.se
            cout << size[equiv[lca(equiv[i.fi], equiv[i.se])]] << endl;
        }
    }
    return 0;
}