#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<pair<int, int>> res;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(a[i][j] == '0')
                continue;
            if((i != 0 && a[i - 1][j] == '1')
            || (j != 0 && a[i][j - 1] == '1')
            || (i != 0 && j != 0 && a[i - 1][j - 1] == '1')
            || (i != n - 1 && a[i + 1][j] == '1') 
            || (j != n - 1 && a[i][j + 1] == '1')
            || (i != n - 1 && j != n - 1 && a[i + 1][j + 1] == '1')
            || (i != n - 1 && j != 0 && a[i + 1][j - 1] == '1')
            || (i != 0 && j != n - 1 && a[i - 1][j + 1] == '1'))
                res.push_back(make_pair(i, j));
        }
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++i)
        cout << res[i].first << " " << res[i].second << endl;
    return 0;
}