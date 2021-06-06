#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    for(int i = 0; i < 2 * n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << arr[n] - arr[n - 1] << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
