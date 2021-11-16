#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//#pragma GCC optimize("Ofast")
using namespace std;
bool vis[11][11];
int n, m, r1, c1, r2, c2, res = 0;
vector<vector<int>> arr = {{1, 0, -1, 0}, {0, 1, 0, -1}};
bool valid(int a, int b)
{
    return a > 0 && a <= n && b > 0 && b <= m && !vis[a][b];
}
void brute_force(int a, int b, int len)
{
    //cout << a << " " << b << endl;
    if(a == r2 && b == c2)
        res = max(res, len);
    else
    {
        vis[a][b] = 1;
        for(int i = 0; i < arr[0].size(); ++i)
            if(valid(a + arr[0][i], b + arr[1][i]))
                brute_force(a + arr[0][i], b + arr[1][i], len + 1);
        vis[a][b] = 0;
    }
}
void solve()
{
    cin >> n >> m >> r1 >> c1 >> r2 >> c2;
    if(n == 1 || m == 1)
    {
        if(n == 1)
            cout << abs(c2 - c1) + 1 << endl;
        else
            cout << abs(r2 - r1) + 1 << endl;
    }
    else if(n * m <= 10)
    {
        memset(vis, 0, sizeof(vis));
        // brute force stupid
        brute_force(r1, c1, 1);
        cout << res << endl;
    }
    else
    {
        // do min(n, m) = 2
        if(m == 2)
        {
            // kalo di r yang sama, cek kiri atau kanan yang paling besar yang mana
            if((r1 == 1 || r1 == n) && (r2 == 1 || r2 == n))
                cout << n * m << endl;
            else if(r1 == r2)
                cout << max(r1 - 1, n - r1) * 2 + 2 << endl;
            else if(abs(r1 - r2) == 1 && abs(c1 - c2) == 1)
                cout << max(r1 - 1 + r2 - 1, n - r1 + n - r2) + 2 << endl;
            else if(abs(r2 - r1) % 2 == 1 && c1 != c2)
                cout << n * m << endl;
            else
                cout << n * m - 1 << endl;
        }
        else
        {
            if((c1 == 1 || c1 == n) && (c2 == 1 || c2 == n))
                cout << n * m << endl;
            else if(c1 == c2)
                cout << max(c1 - 1, m - c1) * 2 + 2 << endl;
            else if(abs(r1 - r2) == 1 && abs(c1 - c2) == 1)
                cout << max(c1 - 1 + c2 - 1, m - c1 + m - c2) + 2 << endl;
            else if(abs(c2 - c1) % 2 == 1 && r1 != r2)
                cout << n * m << endl;
            else
                cout << n * m - 1 << endl;
        }
    }
}
int main()
{
    fast_io();
    solve();
    return 0;
}