#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<set<pair<int, int>>> a(n);
    for(int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].insert(make_pair(z, y));
        if(a[x].size() > 2)
            a[x].erase(--a[x].end());
        a[y].insert(make_pair(z, x));
        if(a[y].size() > 2)
            a[y].erase(--a[y].end());
    }
    int prev;
    long long res = 0;
    for(int i = 0; i < k; ++i)
    {
        if(i == 0 && a[t].size() >= 1)
        {
            res += (*a[t].begin()).first;
            prev = t;
            t = (*a[t].begin()).second;
        }
        else if(a[t].size() >= 2)
        {
            if((*a[t].begin()).second == prev)
            {
                res += (*++a[t].begin()).first;
                prev = t;
                t = (*++a[t].begin()).second;
            }
            else
            {
                res += (*a[t].begin()).first;
                prev = t;
                t = (*a[t].begin()).second;
            }
        }
        else
            break;
    }
    cout << res << endl;
}