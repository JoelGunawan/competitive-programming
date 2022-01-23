#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll mulmod(ll a, ll b)
{
    return (a * b) % mod;
}
vector<int> edges[101];
vector<vector<int>> matrix_mul(vector<vector<int>> a, vector<vector<int>> b)
{
    // result matrix is a.size() * b[0].size()
    vector<vector<int>> res(a.size(), vector<int>(b[0].size(), 0));
    for(int i = 0; i < a.size(); ++i)
    {
        for(int j = 0; j < b[0].size(); ++j)
        {
            for(int k = 0; k < a[0].size(); ++k)
                res[i][j] = (res[i][j] + mulmod(a[i][k], b[k][j])) % mod;
        }
    }
    return res;

}
vector<vector<int>> matrix_pow(vector<vector<int>> a, int times)
{
    if(times == 0)
    {
        // return identity
        vector<vector<int>> res(a.size(), vector<int>(a.size(), 0));
        for(int i = 0; i < a.size(); ++i)
            res[i][i] = 1;
        return res;
    }
    else
    {
        vector<vector<int>> res = matrix_pow(a, times / 2);
        res = matrix_mul(res, res);
        return times & 1 ? matrix_mul(res, a) : res;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // matrix exponentiation
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(1));
    for(int i = 0; i < n; ++i)
        cin >> a[i][0];
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i)
    {
        matrix[i][i] = ((2 * m - edges[i].size()) * powmod(2 * m, mod - 2)) % mod;
        for(int j = 0; j < edges[i].size(); ++j)
            matrix[i][edges[i][j]] = powmod(2 * m, mod - 2);
    }
    matrix = matrix_pow(matrix, k);
    a = matrix_mul(matrix, a);
    for(int i = 0; i < n; ++i)
        cout << a[i][0] << endl;
    return 0;
}