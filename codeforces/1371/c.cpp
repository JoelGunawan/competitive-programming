#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve()
{
    ll a, b, n, m;
    cin >> a >> b >> n >> m;

    if(a < b)
        swap(a, b);

    if(a + b >= n + m && b >= m)
        cout << "Yes";
    else
        cout << "No";
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
