#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
// rmq segtree
struct segtree
{
    int a[(1 << 18)], arr_size = (1 << 17);
    segtree()
    {
        for(int i = 0; i < (1 << 18); ++i)
            a[i] = INT_MAX;
    }
    void update(int index, int value)
    {
        a[arr_size + index] = value;
        private_update((arr_size + index) / 2);
    }
    void private_update(int index)
    {
        a[index] = max(a[2 * index], a[2 * index + 1]);
        if(index != 0)
            private_update(index / 2);
    }
    int query(int current, int cur_left, int cur_right, int left, int right)
    {
        if(cur_left > right || cur_right < left)
            return INT_MAX;
        else if(cur_left >= left && cur_right <= right)
            return a[current];
        else
        {
            int mid = (cur_left + cur_right) / 2;
            return max(query(2 * current, cur_left, mid, left, right), query(2 * current + 1, mid + 1, cur_right, left, right));
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    // use longest decreasing subsequence
    // index, dp value
    vector<pair<int, int>> arr;
    int a[n - 1];
    for(int i = 0; i < n - 1; ++i)
        cin >> a[i], --a[i];
    ll dp[n]; 
    memset(dp, 0, sizeof(dp));
    dp[n - 1] = 0;
    arr.pb({-(n - 1), 0});
    for(int i = n - 2; i >= 0; --i)
    {
        // the lds priority is highest index, highest value
        // add the dp value
        // binser dari begin ke end
        // cari pertama yang indexnya <= a[i]
        int tmp = (*lower_bound(arr.begin(), arr.end(), make_pair(-a[i], -1))).first;
        dp[i] += n - i - 1;
        //cout << dp[i] << " ";
        dp[i] += dp[-tmp];
        //cout << dp[i] << " " << a[i] << " " << tmp << endl;
        dp[i] -= a[i] + tmp;
        while(arr.size() > 0 && arr.back().second <= a[i])
            arr.pop_back();
        arr.pb({-i, a[i]});
    }
    ll res = 0;
    for(int i = 0; i < n; ++i)
        res += dp[i];
    cout << res << endl;
    return 0;
}