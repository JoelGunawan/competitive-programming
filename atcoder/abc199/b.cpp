#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    int amax = 0, bmin = INT_MAX;
    for(int i = 0; i < n; ++i)
    {
        amax = max(amax, a[i]);
        bmin = min(bmin, b[i]);
    }
    cout << max(0, bmin - amax + 1) << endl;
}