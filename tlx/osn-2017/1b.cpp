#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;

vector<vector<vector<short>>> memo;
vector<short> vals;
vector<short> one;

short general(short a, short b, short l)
{ 
    //cout << a << " " << b << " " << l << endl;
    if(l <= 0)
        return 0;
    else if(a == 0 || b == 0)
        return -1;
    else if(memo[a - 1][b - 1][l] != -2)
        return memo[a - 1][b - 1][l];
    int x = general(a - 1, b, l), y = general(a - 1, b - 1, l - vals[a - 1]);
    int res = INT_MAX;
    if(x != -1)
        res = min(res, x);
    if(y != -1)
        res = min(res, y + abs(a - 1 - one[b - 1]));
    if(res == INT_MAX)
        memo[a - 1][b - 1][l] = -1;
    else
        memo[a - 1][b - 1][l] = res;
    return memo[a - 1][b - 1][l];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n, k, len = 0; string subsoal;
    cin >> subsoal >> n >> k;
    k = min(n * (n - 1) / 2, k);
    vals = vector<short>(n);
    for(int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        vals[i] = c - '0';
        len += vals[i];
    }
    for(int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        if(c == '1')
            one.push_back(i);
    }
    memo = vector<vector<vector<short>>>(n, vector<vector<short>>(one.size(), vector<short>(len + 1, -2)));
    short tmp = general(n, one.size(), len);
    while(tmp == -1 || tmp > k)
    {
        --len;
        tmp = general(n, one.size(), len);
    }
    cout << len << endl;
    return 0;
}