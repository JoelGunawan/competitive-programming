#include <bits/stdc++.h>
#define ll long long
#define ub upper_bound
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define ins insert
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int mod = 1e9 + 7;
struct segtree {
    int a[2048], arr_size = 1024;
    void reset()
    {
        memset(a, 0, sizeof(a));
    }
    void update(int index, int value)
    {
        a[index + arr_size] = value;
        private_update((index + arr_size) / 2);
    }
    void private_update(int index)
    {
        a[index] = max(a[2 * index], a[2 * index + 1]);
        if(index != 1)
            private_update(index / 2);
    }
    int query(int left, int right)
    {
        return private_query(1, 1, arr_size, left, right);
    }
    int private_query(int node, int cur_left, int cur_right, int left, int right)
    {
        if(cur_right < left || cur_left > right || cur_right < cur_left)
            return 0;
        else if(left >= cur_left && right <= cur_right)
            return a[node];
        int mid = (cur_left + cur_right) / 2;
        return max(private_query(2 * node, cur_left, mid, left, right), private_query(2 * node + 1, mid + 1, cur_right, left, right));
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b; 
    int dp[b.size()];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < a.size(); ++i)
    {
        //for(int j = 0; j < b.size(); ++j)
        //	cout << dp[j] << " ";
        //cout << endl;
        vector<pair<int, int>> updates;
        for(int j = 0; j < b.size(); ++j)
        {
            if(a[i] == b[j])
            {
                int res = 1;
                if(j != 0)
                    res += dp[j - 1];
                updates.pb({j, res});
                //cout << j << " " << res << endl;
            }
        }
        int idx = 0;
        for(int j = 0; j < b.size(); ++j)
        {
            if(idx < updates.size() && updates[idx].first == j)
                dp[j] = max(dp[j], updates[idx++].second);
            if(j != 0)
            	dp[j] = max(dp[j], dp[j - 1]);
        }
    }
    cout << dp[b.size() - 1] << endl;
    return 0;
}