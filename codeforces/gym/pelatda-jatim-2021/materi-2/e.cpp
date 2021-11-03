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
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    // there should be a chain, and we should do a chain at once
    int cnt[(int)1e6 + 1]; memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i)
        ++cnt[p[i]];
    int res = 0;
    for(int i = 1; i <= 1e6; ++i)
    {
        if(2 * i <= 1e6 && cnt[i] > 0 && cnt[2 * i] > 0)
        {
            // we try to make the longest chain
            vector<int> numbers = {cnt[i]};
            int cur = 2 * i;
            while(cur <= 1e6 && cnt[cur] > 0)
                numbers.pb(cnt[cur]), cur *= 2;
            int dp[numbers.size()];
            memset(dp, 0, sizeof(dp));
            for(int i = 0; i < numbers.size(); ++i)
            {
                if(i == 0)
                    dp[i] = 0;
                else if(i == 1)
                    dp[i] = min(numbers[i], numbers[i - 1]);
                else if(i == 2)
                    dp[i] = min(dp[i - 1] + numbers[i], numbers[i - 1]);
                else
                    dp[i] = min(dp[i - 1] + numbers[i], dp[i - 2] + numbers[i - 1]);
                //cout << dp[i] << " ";
            }
            cur = i;
            while(cur <= 1e6 && cnt[cur] > 0)
            	cnt[cur] = 0, cur *= 2;
        	//cout << endl;
            res += dp[numbers.size() - 1];
        }
    }
    cout << res << endl;
    return 0;
}