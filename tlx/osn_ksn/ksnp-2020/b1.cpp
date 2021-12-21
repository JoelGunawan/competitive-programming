#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n], b[k], prefix[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < k; ++i)
        cin >> b[i];
    prefix[0] = a[0];
    for(int i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + a[i];
    for(int i = 0; i < k; ++i)
        cout << upper_bound(prefix, prefix + n, b[i]) - prefix << endl;
    return 0;
}