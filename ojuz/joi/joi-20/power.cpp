#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
vector<int> edges[lim];
bool gen[lim], vis[lim];
int res[lim];
int ans = 0;
void dfs(int nd = 1) {
    // ambil dr child, itu berarti boleh ambil dr semua di sum terus nanti dikurangi 1
    // ambil dr skrg doang -> tergantung gen state
    vis[nd] = 1;
    int sum = 0, mx = 0;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
            sum += res[i];
            mx = max(mx, res[i]);
        }
    }
    if(!gen[nd]) {
        // then just merge aja :D
        // berarti lgsg get sum from all
        res[nd] = sum;
        //cout << sum << endl;
    }
    else {
        // kita harus rusak gen ini
        // atau buat gen ini as root
        // kalo buat gen as root, berarti choose 1 mx trus itu doang yg nyala
        // else sum - 1
        res[nd] = max(1, sum - 1);
        ans = max(ans, mx + 1);
        //cout << nd << " " << mx << " " << sum << endl;
    }
}
int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    string s;
    cin >> s;
    for(int i = 1; i <= n; ++i)
        gen[i] = s[i - 1] == '1';
    dfs(1);
    int mx = 0;
    for(int i = 1; i <= n; ++i)
        mx = max(res[i], mx);
    cout << max(mx, ans) << endl;
}