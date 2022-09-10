#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 1e6 + 5;
int a[lim];
vector<int> child[lim];
int dfs(int nd) {
    int res = 0;
    for(auto i : child[nd]) {
        res = max(res, dfs(i));
    }
    return res + a[nd];
}
int main() {
    int n, s, p;
    cin >> n >> s >> p;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<pair<int, string>> root;
    for(int i = 1; i <= p; ++i) {
        string s; int k;
        cin >> s >> k;
        root.push_back({k, s});
    }
    for(int i = 1; i <= n - p; ++i) {
        int j, k;
        cin >> j >> k;
        child[j].push_back(k);
    }
    int res = -1; string restype;
    for(auto i : root) {
        int cur = dfs(i.first);
        if(cur > res)
            res = cur, restype = i.second;
    }
    cout << restype << endl << res << endl;
    return 0;
}