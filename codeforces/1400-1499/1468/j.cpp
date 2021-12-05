#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
using namespace std;
struct disjoint_set
{
    int head[(int)1e5 * 2 + 1], size[(int)1e5 * 2 + 1];
    void reset()
    {
        memset(head, -1, sizeof(head));
        memset(size, -1, sizeof(size));
    }
    bool merge(int a, int b)
    {
        if(!same_set(a, b))
        {
            int x = find_head(a), y = find_head(b);
            if(size[x] < size[y])
                head[x] = y, size[y] += x;
            else
                head[y] = x, size[x] += y;
            return 1;
        }
        else
            return 0;
    }
    int find_head(int a)
    {
        while(head[a] != -1)
            a = head[a];
        return a;
    }
    bool same_set(int a, int b)
    {
        return find_head(a) == find_head(b);
    }
};
disjoint_set dsu;
void test_case()
{
    // use kruskall
    int n, m, k;
    cin >> n >> m >> k;
    pair<int, pair<int, int>> kruskall[m];
    int x, y, s;
    for(int i = 0; i < m; ++i)
    {
        cin >> x >> y >> s;
        kruskall[i] = mp(s, mp(x, y));   
    }
    sort(kruskall, kruskall + m);
    dsu.reset();
    int idx = 0;
    // ck = closest to k
    int ck = INT_MAX;
    while(idx < m && kruskall[idx].fi <= k)
    {
        ck = kruskall[idx].fi;
        dsu.merge(kruskall[idx].se.fi, kruskall[idx].se.se);
        ++idx;
    }
    ck = k - ck;
    if(ck < 0)
        ck = INT_MAX;
    ll res = 0;
    bool use_ck = 1;
    for(int i = idx; i < m; ++i)
    {
        if(dsu.merge(kruskall[i].se.fi, kruskall[i].se.se))
        {
            res += kruskall[i].fi - k;
            use_ck = 0;
        }
    }
    if(use_ck)
    {
        if(idx < m && kruskall[idx].fi - k < ck)
            cout << kruskall[idx].fi - k << endl; 
        else
            cout << ck << endl;
    }
    else
        cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}