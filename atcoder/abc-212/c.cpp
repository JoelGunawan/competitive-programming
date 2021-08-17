#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    int pointer = 0, res = INT_MAX;
    for(int i = 0; i < n; ++i)
    {
        int current = abs(a[i] - b[pointer]);
        while(pointer < m - 1 && abs(b[pointer + 1] - a[i]) <= current)
            current = abs(a[i] - b[++pointer]);
        res = min(res, current);
    }    
    cout << res << endl;
    return 0;
}