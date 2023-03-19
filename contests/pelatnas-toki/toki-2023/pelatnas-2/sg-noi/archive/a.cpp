#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> sorted_cost[k + 1];
    int fulfill[n + 1];
    memset(fulfill, 0, sizeof(fulfill));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= k; ++j) {
            // cost
            int x;
            cin >> x;
            sorted_cost[j].pb(mp(x, i));
        }
    }
    for(int i = 1; i <= k; ++i)
        sort(sorted_cost[i].begin(), sorted_cost[i].end());
    int benefit[n + 1][k + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= k; ++j)
            cin >> benefit[i][j];
    int cur_idx[k + 1];
    ll cur_taken[k + 1];
    memset(cur_taken, 0, sizeof(cur_taken));
    memset(cur_idx, 0, sizeof(cur_idx));
    bool change = 1;
    vector<int> update;
    int res = 0;
    while(change) {
        change = 0;
        for(int i = 1; i <= k; ++i) {
            pair<int, int> tmp = sorted_cost[i][cur_idx[i]];
            while(cur_idx[i] < n && cur_taken[i] >= tmp.fi) {
                ++fulfill[tmp.se];
                if(fulfill[tmp.se] == k) {
                    update.pb(tmp.se);
                }
                ++cur_idx[i];
                tmp = sorted_cost[i][cur_idx[i]];
            }
        }
        for(auto i : update) {
            for(int j = 1; j <= k; ++j) {
                cur_taken[j] += benefit[i][j];
            }
        }
        res += update.size();
        change = update.size();
        update.clear();
        // cari yang fulfillnya bisa ditambah
        // bisa pakai pq untuk maintain
    }
    cout << res << endl;
}