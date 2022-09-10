#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
int main() {
    int n, p, s;
    cin >> n >> p >> s;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    pair<int, int> a_order[n], b_order[n];
    for(int i = 0; i < n; ++i)
        a_order[i] = mp(a[i], i);
    for(int i = 0; i < n; ++i)
        b_order[i] = mp(b[i], i);
    sort(a_order, a_order + n);
    reverse(a_order, a_order + n);
    sort(b_order, b_order + n);
    reverse(b_order, b_order + n);
    int a_rank[n], b_rank[n];
    for(int i = 0; i < n; ++i) {
        a_rank[a_order[i].se] = i;
        b_rank[b_order[i].se] = i;
    }
    // if both are outside p + s, remove
    // if one is inside p + s and one is outside, add to p_only/s_only
    // if both are inside p + s, add to both
    // eventually the problem will go to p + s at most, what optimal configuration?
    // either choose p or s
    // dp[pos][p_cnt] = max(dp[pos - 1][p_cnt] + s[pos], dp[pos - 1][p_cnt - 1] + p[pos]);
    // p_cnt dipilih berapa, coba kalo diganti dengan yang p only berapa
    // s_cnt dipilih berapa, coba kalo diganti dengan yang s only berapa
    vector<int> both, a_only, b_only;
    for(int i = 0; i < n; ++i) {
        if(a_rank[i] < p + s && b_rank[i] < p + s)
            both.pb(i);
        else if(a_rank[i] < p + s)
            a_only.pb(i);
        else if(b_rank[i] < p + s)
            b_only.pb(i);
    }
    int dp[both.size() + 1][p + 1];
    bool take_a[both.size() + 1][p + 1];
    memset(take_a, 0, sizeof(take_a));
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= both.size(); ++i) {
        for(int j = 0; j <= p; ++j) {
            if(j != 0 && dp[i - 1][j - 1] + a[both[i - 1]] > dp[i - 1][j] + b[both[i - 1]])
                dp[i][j] = dp[i - 1][j - 1] + a[both[i - 1]], take_a[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] + b[both[i - 1]];
        }
    }
    // buat dp backtrack tiap dp[both.size()][i], cari dengan jumlah p segitu
    vector<int> sol[p + 1];
    for(int i = 0; i <= p; ++i) {
        pair<int, int> cur = mp(both.size(), i);
        while(cur.fi != 0) {
            if(take_a[cur.fi][cur.se]) {
                sol[i].pb(cur.fi - 1);
                --cur.fi, --cur.se;
            }
            else
                --cur.fi;
        }
    }
    vector<int> a_sol, b_sol;
    int res = 0;
    for(int i = 0; i <= p; ++i) {
        vector<int> cp, cs;
        for(int j = (int)both.size() - 1; j >= 0; --j) {
            if(sol[i].size() && sol[i].back() == both[j]) {
                sol[i].pop_back();
                cp.pb(both[j]);
            }
            else
                cs.pb(both[j]);
        }
        for(auto j : a_only)
            cp.pb(j);
        for(auto j : b_only)
            cs.pb(j);
        for(auto &j : cp)
            j = a[j];
        for(auto &j : cs)
            j = b[j];
        sort(cp.begin(), cp.end());
        sort(cs.begin(), cs.end());
        reverse(cp.begin(), cp.end());
        reverse(cs.begin(), cs.end());
        for(auto i : cp)
            cout << i << " ";
        cout << endl;
        for(auto i : cs)
            cout << i << " ";
        cout << endl;
        int ans = 0;
        for(int j = 0; j < min(p, (int)cp.size()); ++j)
            ans += cp[j];
        for(int j = 0; j < min(s, (int)cs.size()); ++j) 
            ans += cs[j];
        if(ans > res) {
            res = ans;
            a_sol.clear(), b_sol.clear();
            for(int j = 0; j < max(p, s); ++j) {
                if(j < min(p, (int)cp.size()))
                    a_sol.pb(cp[j]);
                if(j < min(s, (int)cs.size()))
                    b_sol.pb(cs[j]);
            }
        }
    }
    for(auto i : a_only)
        cout << i << " ";
    cout << endl;
    for(auto i : b_only)
        cout << i << " ";
    cout << endl;
    for(auto i : both)
        cout << i << " ";
    cout << endl;
    cout << res << endl;
    for(auto i : a_sol)
        cout << i << " ";
    cout << endl;
    for(auto j : b_sol)
        cout << j << " ";
    cout << endl;
}