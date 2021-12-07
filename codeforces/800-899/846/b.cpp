#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    int sum = 0, t[k];
    for(int i = 0; i < k; ++i)
    {
        cin >> t[i];
        sum += t[i];
    }
    sort(t, t + k);
    int res = 0;
    // brute force for the amount of full solves we should have
    for(int i = 0; i <= min(n, m / sum); ++i)
    {
        int local_res = (k + 1) * i, remaining_money = m - sum * i;
        multiset<int> a;
        for(int j = 0; j < n - i; ++j)
        {
            for(int l = 0; l < k; ++l)
                a.insert(t[l]);
        }
        while(a.size() > 0 && remaining_money >= *a.begin())
            ++local_res, remaining_money -= *a.begin(), a.erase(a.begin());
        res = max(local_res, res);
    }
    cout << res << endl;
    return 0;
}