#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    cout << min(arr[1] - 1, n - 2) << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
