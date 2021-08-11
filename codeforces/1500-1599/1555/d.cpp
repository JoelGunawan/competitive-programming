#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; string s;
    cin >> n >> m >> s;
    // permutation of size 6
    string t = "abc";
    vector<vector<int>> prefix(6, vector<int>(n, 0));
    int cur = 0;
    do
    {
        prefix[cur][0] = (s[0] != t[0]);
        for(int i = 1; i < n; ++i)
            prefix[cur][i] = prefix[cur][i - 1] + (s[i] != t[i % 3]);
        ++cur;
    } while (next_permutation(t.begin(), t.end()));
    for(int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int res = INT_MAX;
        if(l == 0)
            for(int i = 0; i < 6; ++i)
                res = min(res, prefix[i][r]);
        else
            for(int i = 0; i < 6; ++i)
                res = min(res, prefix[i][r] - prefix[i][l - 1]);
        cout << res << endl;
    }
}