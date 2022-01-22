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
    int prev_coord = 0, prev_height = 0;
    int n;
    cin >> n;
    int k[n], h[n];
    for(int i = 0; i < n; ++i)
        cin >> k[i];
    for(int i = 0; i < n; ++i)
        cin >> h[i];
    pair<int, int> segments[n];
    for(int i = 0; i < n; ++i)
        segments[i] = mp(k[i] - h[i] + 1, k[i]);
    bool merged[n];
    memset(merged, 0, sizeof(merged));
    // fi is coords, second is index
    set<pair<int, int>> dist;
    for(int i = 0; i < n; ++i) {
        if(dist.lb(mp(segments[i].fi, 0)) != dist.end()) {
           while(dist.size() > 0 && (*--dist.end()).fi >= segments[i].fi) {
               segments[i].fi = min(segments[i].fi, segments[(*--dist.end()).se].fi);
               merged[(*--dist.end()).se] = 1;
               dist.erase(--dist.end());
           }
        }
        dist.ins(mp(segments[i].se, i));
    }
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        //cout << segments[i].fi << " " << segments[i].se << endl;
        if(!merged[i])
            res += 1ll * (segments[i].se - segments[i].fi + 1) * (segments[i].se - segments[i].fi + 2) / 2;
    }
    cout << res << endl;
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