#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define endl "\n"
using namespace std;
struct bit
{
    int a[100001];
    bit()
    {
        memset(a, 0, sizeof(a));
    }
    void update(int index, int value)
    {
        while(index <= 100000)
        {
            a[index] += value;
            index += (index&-index);
        }
    }
    int query(int index)
    {
        int res = 0;
        while(index >= 1)
        {
            res += a[index];
            index -= (index&-index);
        }
        return res;
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    // first is forward - backward
    // second is absolute value for going forward
    // this is not a*x, but x only
    pair<int, int> greedy[m];
    bool arr[n + 1][6];
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < 6; ++j)
            arr[i][j] = 1;
    bit c, d;
    for(int i = 1; i <= n; ++i)
        c.update(i, 1), d.update(i, 1);
    for(int i = 0; i < m; ++i)
    {
        string s;
        cin >> s;
        int x = stoi(s.substr(0, s.size() - 1)), y = s[s.size() - 1] - 'A';
        arr[x][y] = 0;
        if(y == 2)
            c.update(x, -1);
        else if(y == 3)
            d.update(x, -1);
        int compulsory = 0;
        if(y <= 2)
        {
            for(int i = y; i < 2; ++i)
                if(arr[x][i])
                    ++compulsory;
        }
        else
        {
            for(int i = y; i > 3; --i)
                if(arr[x][i])
                    ++compulsory;   
        }
        if(arr[x][2])
            ++compulsory;
        if(arr[x][3])
            ++compulsory;
        int forward = compulsory + c.query(x - 1) + d.query(x - 1), backward = compulsory + c.query(n) - c.query(x) + d.query(n) - d.query(x);
        greedy[i] = {forward - backward, forward};
    }
    sort(greedy, greedy + m);
    ll res = LLONG_MAX;
    // greedy
    //int forward_cnt = 0, backward_cnt = 0;
    ll forward_prefix[m + 1], backward_prefix[m + 1];
    forward_prefix[0] = 0, backward_prefix[0] = 0;
    for(int i = 0; i < m; ++i)
    {
        ll forward = greedy[i].se;
        ll backward = greedy[i].se - greedy[i].fi;
        forward *= a;
        backward *= a;
        //cout << forward << " " << forward + b * (forward_cnt / 2) << " " << backward << " " << backward + b * (backward_cnt / 2) << endl; 
        forward_prefix[i + 1] = forward_prefix[i] + forward;
        backward_prefix[i + 1] = backward_prefix[i] + backward;
    }
    for(ll i = 0; i <= m; ++i)
        res = min(res, forward_prefix[i] + b * (i * (i - 1) / 2) + backward_prefix[m] - backward_prefix[i] + b * ((m - i) * (m - i - 1) / 2));
    cout << res << endl;
    return 0;
}