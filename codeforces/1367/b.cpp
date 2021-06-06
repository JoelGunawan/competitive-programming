#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int even = 0, odd = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] & 1)
            ++odd;
        else
            ++even;
    }
    if(even != odd + 1 && even != odd)
    {
        cout << -1 << endl;
        return;
    }
    int evenWrong = 0;
    for(int i = 0; i < n; i += 2)
    {
        if(a[i] & 1) ++evenWrong;
    }
    cout << evenWrong << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
