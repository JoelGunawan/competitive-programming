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
void tc() {
    // use pq from left to right
    // use min res
    // do pq for odd and for even
    int n, m;
    cin >> n >> m;
    int odd[n + 2][m + 2], even[n + 2][m + 2];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            odd[i][j] = 1e9, even[i][j] = 1e9;
            if((i + j) & 1)
                odd[i][j] = 1;
            else
                even[i][j] = 1;
        }
    string strings[n + 1];
    for(int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        strings[i] = s;
        for(int j = 1; j <= m; ++j) {
            if(s[j - 1] == '#') {
                if((i + j) & 1)
                    odd[i][j] = 0, even[i - 1][j] = 1e9, even[i + 1][j] = 1e9, even[i][j - 1] = 1e9, even[i][j + 1] = 1e9;
                else
                    even[i][j] = 0, odd[i - 1][j] = 1e9, odd[i + 1][j] = 1e9, odd[i][j - 1] = 1e9, odd[i][j + 1] = 1e9;
            }
        }
    }
    // pq dari kiri ke kanan
    // proc odd first
    priority_queue<pair<ll, pair<pair<int, int>, pair<int, int>>>> pq;
    ll oddans[n + 2][m + 2], evenans[n + 2][m + 2];
    memset(oddans, -1, sizeof(oddans));
    memset(evenans, -1, sizeof(evenans));
    for(int i = 2; i <= n; i += 2) {
        pq.push(mp(-odd[i][1], mp(mp(i, 1), mp(-1, -1))));
    }
    bool vis[n + 2][m + 2];
    pair<int, int> pr[n + 2][m + 2];
    memset(vis, 0, sizeof(vis));
    while(pq.size()) {
        int x = pq.top().se.fi.fi, y = pq.top().se.fi.se; ll cur = -pq.top().fi;
        pair<int, int> tmp = pq.top().se.se;
        pq.pop();
        if(vis[x][y])
            continue;
        oddans[x][y] = cur;
        pr[x][y] = tmp;
        vis[x][y] = 1;
        //cout << x << " " << y << " " << tmp.fi << " " << tmp.se << endl;
        //cout << cur << endl;
        if(!vis[x - 1][y - 1] && x > 1 && y > 1)
            pq.push(mp(-(cur + odd[x - 1][y - 1]), mp(mp(x - 1, y - 1), mp(x, y))));
        if(!vis[x - 1][y + 1] && x > 1 && y < m)
            pq.push(mp(-(cur + odd[x - 1][y + 1]), mp(mp(x - 1, y + 1), mp(x, y))));
        if(!vis[x + 1][y + 1] && x < n && y < m)
            pq.push(mp(-(cur + odd[x + 1][y + 1]), mp(mp(x + 1, y + 1), mp(x, y))));
        if(!vis[x + 1][y - 1] && x < n && y > 1)
            pq.push(mp(-(cur + odd[x + 1][y - 1]), mp(mp(x + 1, y - 1), mp(x, y))));
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i += 2) {
        pq.push(mp(-even[i][1], mp(mp(i, 1), mp(-1, -1))));
    }
    while(pq.size()) {
        int x = pq.top().se.fi.fi, y = pq.top().se.fi.se; ll cur = -pq.top().fi;
        pair<int, int> tmp = pq.top().se.se;
        pq.pop();
        if(vis[x][y])
            continue;
        //cout << x << " " << y << " " << tmp.fi << " " << tmp.se << endl;
        //cout << cur << endl;
        evenans[x][y] = cur;
        pr[x][y] = tmp;
        vis[x][y] = 1;
        if(!vis[x - 1][y - 1] && x > 1 && y > 1)
            pq.push(mp(-(cur + even[x - 1][y - 1]), mp(mp(x - 1, y - 1), mp(x, y))));
        if(!vis[x - 1][y + 1] && x > 1 && y < m)
            pq.push(mp(-(cur + even[x - 1][y + 1]), mp(mp(x - 1, y + 1), mp(x, y))));
        if(!vis[x + 1][y + 1] && x < n && y < m)
            pq.push(mp(-(cur + even[x + 1][y + 1]), mp(mp(x + 1, y + 1), mp(x, y))));
        if(!vis[x + 1][y - 1] && x < n && y > 1)
            pq.push(mp(-(cur + even[x + 1][y - 1]), mp(mp(x + 1, y - 1), mp(x, y))));
    }
    ll ans = 1e18;
    int idx = -1;
    for(int i = 1; i <= n; ++i) {
        //cout << m << " " << i << " " << oddans[m][i] << " " << evenans[m][i] << endl;
        if((i + m) & 1) {
            if(oddans[i][m] < ans && oddans[i][m] != -1)
                idx = i, ans = oddans[i][m];
        }
        else {
            if(evenans[i][m] < ans && evenans[i][m] != -1)
                idx = i, ans = evenans[i][m];
        }
    }
    if(ans > n * m)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        pair<int, int> cur = mp(idx, m);
        while(cur != mp(-1, -1) && cur != mp(0, 0)) {
            //cout << cur.fi << " " << cur.se << endl;
            strings[cur.fi][cur.se - 1] = '#';
            cur = pr[cur.fi][cur.se];
        }
        for(int i = 1; i <= n; ++i)
            cout << strings[i] << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
        tc();
    return 0;
}