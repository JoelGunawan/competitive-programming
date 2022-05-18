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
vector<int> edges[500001];
bool on[500001], m[500001], vis[500001];
int res[500001], one_way[500001], two_way[500001], cnt[500001];
int dfs(int nd) {
    vis[nd] = 1;
    cnt[nd] = 1;
    int child_cnt = 0;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            cnt[nd] += (dfs(i)); 
            if(res[i] != 0)
                ++child_cnt;
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        char x;
        cin >> x;
        on[i + 1] = x == '1';
    }
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    // kita dfs tiap subtree
    // for each node, kita maintain kalo one way berapa, kalo 2 way berapa
    // untuk tiap subtree, kita simpan biaya untuk one way, two way, dan calculate result jika current node merupakan root dari walk
    // seharusnya inbound dan outbound tidak pengaruh, yang penting satu arah atau 2 arah
    // kita tinggal cari result dari node dengan depth terendah yang ada merging (lebih dari 2 node)
    dfs(1);
    return 0;
}