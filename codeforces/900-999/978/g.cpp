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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int activity[n + 1], cnt[m + 1];
    pair<int, pair<bool, int>> sweep[2 * m];
    pair<int, int> range[m + 1];
    for(int i = 0; i < m; ++i) {
        int s, d, c;
        cin >> s >> d >> c;
        range[i + 1] = mp(s, d);
        cnt[i + 1] = c + 1;
        sweep[2 * i] = mp(s, mp(0, i + 1));
        sweep[2 * i + 1] = mp(d, mp(1, i + 1));
    }
    // exam day, index
    sort(sweep, sweep + 2 * m);
    set<pair<int, int>> active;
    int idx = 0;
    int res[n + 1];
    memset(res, 0, sizeof(res));
    for(int i = 1; i <= n; ++i) {
        while(idx < 2 * m && sweep[idx].fi == i && !sweep[idx].se.fi) {
            active.ins(mp(range[sweep[idx].se.se].se, sweep[idx].se.se));
            ++idx;
        }
        bool used = 0;
        while(idx < 2 * m && sweep[idx].fi == i && sweep[idx].se.fi) {
            if(!used) {
                used = 1;
                res[i] = m + 1;
                --cnt[sweep[idx].se.se];
            }
            ++idx;
        }
        if(!used && active.size() > 0) {
            // find in active
            while(active.size() > 0 && cnt[(*active.begin()).se] <= 1)
                active.erase(active.begin());
            if(active.size() > 0 && cnt[(*active.begin()).se] > 1)
                --cnt[(*active.begin()).se], res[i] = (*active.begin()).se;
        }
    }
    bool ans = 1;
    for(int i = 1; i <= m; ++i)
        if(cnt[i] > 0)
            ans = 0;
    if(ans) {
        for(int i = 1; i <= n; ++i)
            cout << res[i] << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}