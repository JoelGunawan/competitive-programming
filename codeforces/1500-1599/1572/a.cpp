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
    // do a dijkstra
    int n;
    cin >> n;
    int cnt = n;
    vector<int> edges[n + 1];
    set<int> nums;
    vector<int> nxt;
    int edge_cnt[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> edge_cnt[i];
        for(int j = 0; j < edge_cnt[i]; ++j) {
            int x;
            cin >> x;
            edges[x].pb(i);
        }
        if(edge_cnt[i] == 0)
            nxt.pb(i);
    }
    int prev = 0, res = 0;
    while(nums.size() > 0 || nxt.size() > 0) {
        if(nums.size() == 0) {
            sort(nxt.begin(), nxt.end());
            for(auto i : nxt)
                nums.ins(i);
            ++res;
            nxt.clear();
            continue;
        }
        --cnt;
        int cur = *nums.begin();
        //cout << cur << " ";
        nums.erase(nums.begin());
        for(auto i : edges[cur]) {
            --edge_cnt[i];
            if(edge_cnt[i] == 0) {
                if(i > cur)
                    nums.ins(i);
                else
                    nxt.pb(i);
            }
        }
    }
    //cout << endl;
    if(cnt != 0)
        cout << -1 << endl;
    else
        cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}