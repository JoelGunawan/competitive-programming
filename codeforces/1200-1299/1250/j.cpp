#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
void test_case()
{
    int n; ll k, sum = 0;
    cin >> n >> k;
    vector<ll> c(n);
    for(int i = 0; i < n; ++i)
        cin >> c[i], sum += c[i];
    // bsta
    // O(n log (sum(c) / k))
    ll left = 1, right = sum / k, res = 0;
    vector<ll> d;
    //cout << sum << endl;
    while(left <= right)
    {
        ll mid = (left + right) / 2;
        if(mid == 0)
            break;
        //cout << left << " " << right << endl;
        // calculate answer
        // use greedy approach where we always select
        // earliest possible because that is the most optimal
        d = c; ll row_cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i == 0)
                row_cnt += d[i] / mid, d[i] %= mid;
            else
            {
                //cout << d[i - 1] + d[i] << " ";
                row_cnt += (d[i - 1] + d[i]) / mid;
                if(d[i] + d[i - 1] >= mid)
                    d[i] = (d[i] + d[i - 1]) % mid;
                d[i - 1] = 0;
            }
            // cout << row_cnt << " ";
        }
        //cout << endl;
        if(row_cnt >= k)
            left = mid + 1, res = mid;
        else
            right = mid - 1;
    }
    cout << res * k << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}