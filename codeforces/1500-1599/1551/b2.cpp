#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> counter(n + 1, 0); vector<int> res(n, 0);
        for(int i = 0; i < n; ++i)
        {
            ++counter[a[i]];
            res[i] = counter[a[i]];
        }
        vector<pair<int, int>> b;
        for(int i = 0; i < n; ++i)
        {
            if(res[i] <= k)
                b.push_back(make_pair(a[i], i));
        }
        res = vector<int>(n, 0);
        sort(b.begin(), b.end());
        for(int i = 0; i < b.size() - b.size() % k; ++i)
        {
            res[b[i].second] = i % k + 1;
        }
        for(int i = 0; i < n; ++i)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}