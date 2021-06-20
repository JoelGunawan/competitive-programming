#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> prefix(n);
    prefix[0] = a[0];
    for(int i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + a[i];
    cout << lower_bound(prefix.begin(), prefix.end(), prefix[n - 1] / 2 + prefix[n - 1] % 2) - prefix.begin() + 1 << endl;
    return 0;
}