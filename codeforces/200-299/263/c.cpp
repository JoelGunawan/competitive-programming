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
int diff_count(vector<int> a, vector<int> b) {
    int cnt = a.size();
    for(auto i : a) {
        for(auto j : b)
            if(i == j)
                --cnt;
    }
    //cout << cnt << endl;
    //for(auto i : a)
    //    cout << i << " ";
    //cout << endl;
    //for(auto i : b)
    //    cout << i << " ";
    //cout << endl;
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr[n + 1];
    vector<int> dn[n + 1];
    for(int i = 0; i < 2 * n; ++i) {
        int u, v;
        cin >> u >> v;
        arr[u].pb(v);
        arr[v].pb(u);
    }
    bool ans = 1;
    for(int i = 1; i <= n; ++i) {
        if(arr[i].size() != 4)
            ans = 0;   
    }
    if(!ans)
        cout << -1 << endl, exit
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++i) {
        //if(vis[i])
        //    continue;
        for(auto j : arr[i]) {
            if(diff_count(arr[i], arr[j]) == 2)
                dn[i].pb(j);
        }
        //cout << dn[i].size() << endl;
    }
    if(!ans)
        cout << -1 << endl, exit(0);
    if(n == 5) {
        for(int i = 1; i <= n; ++i)
            cout << i << " ";
        exit(0);
    }
    else if(n == 6) {
        memset(vis, 0, sizeof(vis));
        int last_idx = 0;
        int res[n];
        for(int i = 1; i <= n; ++i) {
            if(vis[i])
                continue;
            int opp;
            for(int j = 1; j <= n; ++j) {
                bool tmp1 = 1;
                for(auto k : arr[i]) {
                    //cout << i << " " << j << " " << k << endl;
                    if(k == j || j == i)
                        tmp1 = 0;
                }
                //cout << (int)tmp1 << endl;
                if(tmp1)
                    opp = j;
            }
            //cout << i << " " << opp << endl;
            //cout << i << " " << opp << endl;
            vis[i] = 1, vis[opp] = 1;
            res[last_idx] = i, res[last_idx + n / 2] = opp;
            ++last_idx;
        }
        for(int i = 0; i < n; ++i)
            cout << res[i] << " ";
        exit(0);
    }
    vector<int> res(n);
    for(int i = 1; i <= n; ++i) {
        if(dn[i].size() != 2)
            ans = 0;
    }
    if(!ans)
        cout << -1 << endl, exit(0);
    int prev = 1, cur = dn[1][0];
    for(int i = 1; i <= n; ++i) {
        res[i - 1] = cur;
        int exists = 0, changed = 0, x;
        //cout << dn[cur].size() << endl;
        for(auto j : dn[cur]) {
            if(j != prev) {
                x = j;
                ++changed;
            }
            else {
                ++exists;
            }
        }
        if(exists == 1 && changed == 1) {
            prev = cur;
            cur = x;
        }
        else
            ans = 0;
    }
    bool used[n + 1];
    memset(used, 0, sizeof(used));
    for(int i = 0; i < res.size(); ++i) {
        if(!((dn[res[i]][0] == res[(i + 1) % res.size()] || dn[res[i]][1] == res[(i + 1) % res.size()])
        && (dn[res[i]][1] == res[(i - 1 + n) % res.size()] || dn[res[i]][0] == res[(i - 1 + res.size()) % res.size()])))
            ans = 0;
        if(used[res[i]])
            ans = 0;
        used[res[i]] = 1;
    }
    if(!ans)
        cout << -1 << endl;
    else {
        for(auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}