#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i];
        if(i == n - 1) cout << endl;
        else cout << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
