// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
void tc() {
    int n, m;
    cin >> n >> m;
    pair<int, int> bigram[10][10];
    pair<int, int> trigram[10][10][10];
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            for(int k = 0; k < 10; ++k)
                trigram[i][j][k] = mp(0, 0);
            bigram[i][j] = mp(0, 0);
        }
    }
    string in;
    int a[m];
    for(int i = 0; i < n; ++i) {
        cin >> in;
        for(int j = 0; j < m; ++j) {
            a[j] = in[j] - '0';
            if(j > 0) {
                if(bigram[a[j - 1]][a[j]].fi == 0) {
                    bigram[a[j - 1]][a[j]] = mp(i + 1, j);
                }
            }
            if(j > 1) {
                if(trigram[a[j - 2]][a[j - 1]][a[j]].fi == 0) {
                    trigram[a[j - 2]][a[j - 1]][a[j]] = mp(i + 1, j - 1);
                }
            }
        }
    }
    string s;
    cin >> s;
    // bool: false -> bigram, true -> trigram
    // fi which phone number
    // se start of bigram/trigram
    pair<bool, pair<int, int>> dp[m + 1];
    bool vis[m + 1];
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for(int i = 2; i <= m; ++i) {
        if(vis[i - 2] && bigram[s[i - 2] - '0'][s[i - 1] - '0'].fi != 0) {
            dp[i] = mp(0, bigram[s[i - 2] - '0'][s[i - 1] - '0']);
            vis[i] = 1;
        }
        else if(i > 2 && vis[i - 3] && trigram[s[i - 3] - '0'][s[i - 2] - '0'][s[i - 1] - '0'].fi != 0) {
            dp[i] = mp(1, trigram[s[i - 3] - '0'][s[i - 2] - '0'][s[i - 1] - '0']);
            vis[i] = 1;
        }
    }
    if(!vis[m]) {
        cout << -1 << endl;
        return;
    }
    else {
        // backtrack dp
        vector<pair<pair<int, int>, int>> ans;
        int cur = m;
        while(cur > 0) {
            if(dp[cur].fi) {
                ans.pb(mp(mp(dp[cur].se.se, dp[cur].se.se + 2), dp[cur].se.fi));
                cur -= 3;
            }
            else {
                ans.pb(mp(mp(dp[cur].se.se, dp[cur].se.se + 1), dp[cur].se.fi));
                cur -= 2;
            }
        }
        cout << ans.size() << endl;
        for(int i = ans.size() - 1; i >= 0; --i) {
            cout << ans[i].fi.fi << " " << ans[i].fi.se << " " << ans[i].se << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}