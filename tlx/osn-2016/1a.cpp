#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
vector<ll> result;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int n, m;
void dp(int a, int b, ll res)
{
    // invalide case
    if(a < 0 || a >= n || b < 0 || b >= m || visited[a][b])
        return;

    res += arr[a][b];
    // end case
    if(a == n - 1 && b == m - 1)
    {
        result.push_back(res);
        return;
    }

    visited[a][b] = 1;
    dp(a + 1, b, res);
    dp(a, b + 1, res);
    dp(a - 1, b, res);
    dp(a, b - 1, res);
    visited[a][b] = 0;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    string subsoal;
    cin >> subsoal >> n >> m;
    arr = vector<vector<int>>(n, vector<int>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, 0));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> arr[i][j];
    // do a n! solution first?
    dp(0, 0, 0);
    int k;
    sort(result.begin(), result.end());
    cin >> k;
    for(int i = 0; i < k; ++i)
    {
        ll p, q;
        cin >> p >> q;
        cout << (upper_bound(result.begin(), result.end(), q) - result.begin()) - (lower_bound(result.begin(), result.end(), p) - result.begin()) << endl;
    }
}