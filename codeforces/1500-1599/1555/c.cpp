#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin >> m;
        vector<vector<int>> a(2, vector<int>(m));
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < m; ++j)
                cin >> a[i][j];
        vector<int> prefix1(m), prefix2(m);
        for(int i = 0; i < m; ++i)
        {
            prefix1[i] = a[0][i];
            prefix2[i] = a[1][i];
            if(i > 0)
            {
                prefix1[i] += prefix1[i - 1];
                prefix2[i] += prefix2[i - 1];
            }
        }
        int minimum = prefix1[m - 1] - prefix1[0];
        for(int i = 1; i < m; ++i)
             minimum = min(minimum, max(prefix1[m - 1] - prefix1[i], prefix2[i - 1]));
        cout << minimum << endl;
    }
    return 0;
}