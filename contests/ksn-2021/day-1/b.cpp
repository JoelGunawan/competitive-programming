#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl "\n"
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int mod = 1e9 + 7;
bool vis[201][201];
int a, b, c, d;
bool valid(int x, int y)
{
    //cout << "SPECIAL " << (x & y) << " " << (int)vis[x][y] << endl;
    return (x >= a && x <= c && y >= b && y <= d) 
    && !vis[x][y] && ((x & y) == 0);
}
void dfs(int x, int y)
{
    // try to move to valid positions and set the vis to 1
    //cout << x << " " << y << endl;
    vis[x][y] = 1;
    if(valid(x - 1, y))
        dfs(x - 1, y);
    if(valid(x, y - 1))
        dfs(x, y - 1);
    if(valid(x + 1, y))
        dfs(x + 1, y);
    if(valid(x, y + 1))
        dfs(x, y + 1);
}
int find_length(int x, int y)
{
    // between 0 to y, ada berapa potong daratan?
    int pow = 1;
    while(pow <= x)
        pow *= 2;
    return y / pow + 1;
}
int main()
{
    fast_io();
    int n, m, q;
    cin >> n >> m >> q;
    if(n <= 200 && m <= 200 && q <= 200)
    {
        // brute force aja bang
        // precalculate the array as a graph
        // and do a dfs
        for(int i = 0; i < q; ++i)
        {
            cin >> a >> b >> c >> d;
            memset(vis, 0, sizeof(vis));
            int res = 0;
            for(int j = a; j <= c; ++j)
                for(int k = b; k <= d; ++k)
                    if(!vis[j][k] && (j & k) == 0)
                        dfs(j, k), ++res;
            cout << res << endl;
        }
    }
    else if(n <= 2000 && m <= 2000 && q <= 2000)
    {
        for(int i = 0; i < q; ++i)
        {
            cin >> a >> b >> c >> d;
            if(a == c)
            {
                bool prev = 0; int res = 0;
                for(int j = b; j <= d; ++j)
                {
                    if((a & j) == 0)
                    {
                        if(!prev)
                            prev = !prev, ++res;
                    }
                    else
                    {
                        if(prev)
                            prev = !prev;
                    }
                }
                cout << res << endl;
            }
            else if(b == d)
            {
                bool prev = 0; int res = 0;
                for(int j = a; j <= c; ++j)
                {
                    if((b & j) == 0)
                    {
                        if(!prev)
                            prev = !prev, ++res;
                    }
                    else
                    {
                        if(prev)
                            prev = !prev;
                    }
                }
                cout << res << endl;
            }
            else if(a == 0 && b == 0)
                cout << 1 << endl;
        }
    }
    else
    {
        for(int i = 0; i < q; ++i)
        {
            cin >> a >> b >> c >> d;
            if(a == 0 && b == 0)
                cout << 1 << endl;
            else if(a == c)
            {
                int res = find_length(a, d);
                if(b > 0)
                {
                    res -= find_length(a, b);
                    if((a & (b - 1)) == 0 && (a & b) == 0)
                        ++res;
                }
                cout << res << endl;
            }
        }
    }
    return 0;
}