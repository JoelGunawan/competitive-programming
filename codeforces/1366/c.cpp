#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int depth = n + m - 1;
    vector<int> zero(depth, 0), one(depth, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j])
                one[i + j]++;
            else
                zero[i + j]++;
        }
    }
    int result = 0;
    for(int i = 0; i < depth / 2; i++)
    {
        int total = zero[i] + zero[depth - i - 1] + one[i] + one[depth - i - 1];
        result += min(total - zero[i] - zero[depth - i - 1], total - one[i] - one[depth - i - 1]);
    }
    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
