#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define ins insert
#define pf push_front
#define fi first
#define se second
#define ld long double
#define endl "\n"
using namespace std;
bool m_levels[32];
int n, m, last_m = -1, last = 2;
pair<int, pair<int, int>> ans[(int)2e5 + 5];
void build(int node, int level, int excess_one)
{
    if(m_levels[level])
    {
        int tmp = last;
        if(level == last_m && excess_one < 2)
        {
            if(excess_one == 1)
            {
                ans[node] = {2, {last, 0}};
                ++last;
                build(tmp, level + 1, excess_one);             
            }
            else
            {
                ans[node] = {2, {0, 0}};
            }
            return;
        }
        ans[node] = {2, {last, last + 1}};
        last += 2;
        build(tmp, level + 1, excess_one / 2 + excess_one % 2);
        build(tmp + 1, level + 1, excess_one / 2);
    }
    else
    {
        if(level > last_m)
        {
            --excess_one;
            int tmp = last;
            if(excess_one >= 2)
            {
                ans[node] = {1, {last, last + 1}};
                last += 2;
                build(tmp, level + 1, excess_one / 2 + excess_one % 2);
                build(tmp + 1, level + 1, excess_one / 2);
            }
            else if(excess_one == 1)
            {
                ans[node] = {1, {last, 0}};
                ++last;
                build(tmp, level + 1, excess_one);
            }
            else
                ans[node] = {1, {0, 0}};
        }
        else
        {
            ans[node] = {1, {last, last + 1}};
            int tmp = last;
            last += 2;
            build(tmp, level + 1, excess_one / 2 + excess_one % 2);
            build(tmp + 1, level + 1, excess_one / 2);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int save = n;
    int tmp = 0;
    for(int i = 0; (1 << i) <= m; ++i)
        if((1 << i) & m)
            m_levels[i] = 1, last_m = i;
    for(int i = last_m; i >= 0; --i)
    {
        if(!((1 << i) & m))
            n -= 1 << i;
    }
    if(n < 0)
        cout << -1 << endl, exit(0);
    build(1, 0, n);
    for(int i = 1; i <= save + m; ++i)
        cout << ans[i].fi << " " << ans[i].se.fi << " " << ans[i].se.se << endl;
    return 0;
}