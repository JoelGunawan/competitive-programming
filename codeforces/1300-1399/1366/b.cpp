#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x, m;
    cin >> n >> x >> m;
    int lower = x, upper = x;
    int l, r;
    for(int i = 0; i < m; i++)
    {
        cin >> l >> r;
        if(l < lower && r >= lower)
            lower = l;
        if(r > upper && l <= upper)
            upper = r;
    }
    cout << upper - lower + 1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
