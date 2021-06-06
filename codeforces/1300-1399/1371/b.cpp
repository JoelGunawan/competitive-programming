#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

void solve()
{
    ull n, r;
    cin >> n >> r;
    bool myBool = r >= n;
    if(r < n - 1) n = r;
    else n = n - 1;
    cout << n * (n + 1) / 2 + myBool;
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
