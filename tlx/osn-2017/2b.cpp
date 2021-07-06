#include <bits/stdc++.h>
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
vector<vector<vector<bool>>> sstate, tstate;
string s, t;
int n, m;
vector<string> arr;
void findT(int cur, int x, int y)
{
    if(tstate[cur][x][y] || arr[x][y] != t[cur])
        return;
    else
    {
        tstate[cur][x][y] = 1;
        --cur;
    }
    if(cur == -1)
        return;
    if(x != n - 1)
        findT(cur, x + 1, y);
    if(x != 0)
        findT(cur, x - 1, y);
    if(y != m - 1)
        findT(cur, x, y + 1);
    if(y != 0)
        findT(cur, x, y - 1);
}
void findS(int cur, int x, int y)
{
    if(sstate[cur][x][y] || arr[x][y] != s[cur])
        return;
    else
    { 
        sstate[cur][x][y] = 1;
        ++cur;
    }
    if(cur == s.size())
        return;
    if(x != n - 1)
        findS(cur, x + 1, y);
    if(x != 0)
        findS(cur, x - 1, y);
    if(y != m - 1)
        findS(cur, x, y + 1);
    if(y != 0)
        findS(cur, x, y - 1);
}
int main()
{
    string subsoal;
    cin >> subsoal >> n >> m;
    arr = vector<string>(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> s >> t;
    // brute force dfs all s and t
    // we can use state memo, so that we don't duplicate max amount of states is (|s| * (n * m) + |t| * (n * m)) -> 10^6
    // we need to consider when the end of s is equal to the start of t, we need to factor that in
    // we find t from behind, we find s from the front
    // we need to consider the length of the similar between s and t
    string common = "";
    int length = min(s.size(), t.size());
    while(length > 0)
    {
        if(s.substr(s.size() - length, length) == t.substr(0, length))
        {
            common = t.substr(0, length);
            break;
        }
        --length;
    }
    sstate = vector<vector<vector<bool>>>(s.size(), vector<vector<bool>>(n, vector<bool>(m, false)));
    tstate = vector<vector<vector<bool>>>(t.size(), vector<vector<bool>>(n, vector<bool>(m, false)));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            findS(0, i, j);
            findT(t.size() - 1, i, j);
        }
    }
    if(subsoal[7] == '7')
    {
        int ans = INT_MAX;
        if(s[s.size() - 1] == t[0])
        {
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)
                    if(sstate[s.size() - 1][i][j])
                        ans = s.size();
        }
        else
        {
            // check for all scoords and tcoords
            vector<pair<int, int>> scoords, tcoords;
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < m; ++j)
                {
                    if(sstate[s.size() - 1][i][j])
                        scoords.push_back(make_pair(i, j));
                    if(t[0] == arr[i][j])
                        tcoords.push_back(make_pair(i, j));
                }
            }
            for(int i = 0; i < scoords.size(); ++i)
                for(int j = 0; j < tcoords.size(); ++j)
                    ans = min(ans, (int)s.size() + (int)t.size() + abs(scoords[i].first - tcoords[j].first) + abs(scoords[i].second - tcoords[j].second) - 1);
        }
        if(ans == INT_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
        return 0;
    }
    ll res = INT_MAX;
    for(int i = 0; i <= common.size(); ++i)
    {
        vector<pair<int, int>> scoords, tcoords;
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < m; ++k)
            {
                if(-(ll)common.size() - 1 + i < 0 && s.size() - (ll)common.size() - 1 + i >= 0 && sstate[s.size() - common.size() - 1 + i][j][k])
                    scoords.push_back(make_pair(j, k));
                if(i >= 0 && i < t.size() && tstate[i][j][k])
                    tcoords.push_back(make_pair(j, k));
            }
        if((s == common && s.size() - (ll)common.size() - i + 1 == -1 && tcoords.size())
            || (t == common && i == t.size() && scoords.size()))
        {
            res = 1;
            break;
        }
        else if(scoords.size() == 0 || tcoords.size() == 0)
            continue;
        for(int j = 0; j < scoords.size(); ++j)
            for(int k = 0; k < tcoords.size(); ++k)
                if(scoords[j] != tcoords[k])
                    res = min(res, (ll)abs(scoords[j].first - tcoords[k].first) + abs(scoords[j].second - tcoords[k].second));
    }
    if(res == INT_MAX)
        cout << -1 << endl;
    else
        cout << s.size() + t.size() - common.size() + res - 1 << endl;
    return 0;
}