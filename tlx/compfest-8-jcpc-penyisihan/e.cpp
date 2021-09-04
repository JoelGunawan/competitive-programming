#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
string format(int number)
{
    string s = to_string(number);
    string add = "";
    for(int i = 0; i < 7 - s.size(); ++i)
        add += '0';
    return add + s;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll r, k, c, h;
    cin >> r >> c >> k >> h;
    ll arr[r][c];
    for(int i = 1; i <= r; ++i)
        for(int j = 1; j <= c; ++j)
            arr[i - 1][j - 1] = (((i - 1) * c + j) * k + h) % (r * c) + 1;
    int x = 0, y = 0;
    ll ans[r + c - 1];
    ans[0] = arr[0][0];
    for(int i = 1; i < r + c - 1; ++i)
    {
        // either choose right or down, lexicographically smallest
        if(x == r - 1)
            ans[i] = arr[x][y + 1], ++y;
        else if(y == c - 1)
            ans[i] = arr[x + 1][y], ++x;
        else
        {
            if(arr[x + 1][y] < arr[x][y + 1])
                ans[i] = arr[x + 1][y], ++x;
            else
                ans[i] = arr[x][y + 1], ++y;
        }
    }
    if(r + c - 1 > 200)
    {
        for(int i = 0; i < 100; ++i)
            cout << format(ans[i]) << endl;
        for(int i = r + c - 101; i < r + c - 1; ++i)
            cout << format(ans[i]) << endl;
    }
    else
    {
        for(int i = 0; i < r + c - 1; ++i)
            cout << format(ans[i]) << endl;
    }
}