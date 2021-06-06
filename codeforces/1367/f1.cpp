#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    vector<int> longestSub(n, 0);
    for(int i = 0; i < n; ++i)
    {
        int cur = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if(cur > 0)
            longestSub[cur] = longestSub[cur - 1] + 1;
        else
            longestSub[cur] = 1;
    }
    int res = 0;
    for(int i : longestSub)
        res = max(res, i);
    cout << n - res << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
