#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ins insert
#define pf push_front
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
int segtree[131073], memosegtree[131073];
void segtreeupdate(int a, int b, int amount, int current, int l, int r)
{
    
}
int segtreequery(int a, int b, int current, int l, int r)
{
    
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int p[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> p[i][j], --p[i][j];
    // full solve using segment tree
    ll res = 0;
    for(int i = 1; i < m; ++i)
    {
        int arr[2][n];
        for(int j = 0; j < n; ++j)
            arr[0][p[j][i - 1]] = j, arr[1][p[j][i]] = j;
        // go through each and add to the segment tree
        for(int j = 0; j < n; ++j)
        {
            res += j - segtreequery(0, j, 1, 1, 65536);
            segtreeupdate(0, j, 1, 1, 1, 65536);
        }
        // reset segment tree
        memset(segtree, 0, sizeof(segtree));
    }
    cout << res << endl;
    return 0;
}