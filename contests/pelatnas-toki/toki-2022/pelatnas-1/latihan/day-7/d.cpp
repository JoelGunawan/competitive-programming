#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define lll __int128
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // do line sweep based on N
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> line_sweep(1000);
    vector<pair<pair<int, int>, int>> input;
    for(int i = 0; i < k; ++i) {
        int x, y, d;
        cin >> x >> y >> d;
        input.pb(mp(mp(x, y), d));
    }
    int q;
    cin >> q;
    pair<int, pair<int, int>> queries[q];
    for(int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        queries[i] = mp(x, mp(y, i + 1));
    }
    sort(queries, queries + q);
    int query_idx = 0, line_sweep_size = 0;
    vector<int> z(q + 1, 0);
    for(int i = 1; i <= n; ++i) {
        while(query_idx < q && queries[query_idx].fi == i)
            line_sweep[line_sweep_size++] = queries[query_idx++].se;
        int idx = 0, active = 0;
        for(int j = 0; j < k; ++j) {
            // cek kalo ada intersection
            if(abs(input[j].fi.fi - i) <= input[j].se) {
                int diff = input[j].se - abs(input[j].fi.fi - i);
                if(input[j].fi.se - diff <= 1 && input[j].fi.se + diff >= m)
                    ++active;
                else {
                    line_sweep[line_sweep_size++] = mp(max(input[j].fi.se - diff, 1), 0);
                    line_sweep[line_sweep_size++] = mp(min(input[j].fi.se + diff, m), 1e9);
                }
            }
        }
        sort(line_sweep.begin(), line_sweep.begin() + line_sweep_size + 1);
        while(idx < line_sweep_size) {
            while(idx < line_sweep_size && line_sweep[idx].se == 0)
                ++active, ++idx;
            while(idx < line_sweep_size && line_sweep[idx].se >= 1 && line_sweep[idx].se < 1e9)
                z[line_sweep[idx].se] = active, ++idx;
            while(idx < line_sweep_size && line_sweep[idx].se == 1e9)
                --active, ++idx;
        }
        line_sweep_size = 0;
    }
    for(int i = 1; i <= q; ++i)
        cout << z[i] << endl;
    return 0;
}