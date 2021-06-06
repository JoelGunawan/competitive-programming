#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

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
    sort(arr.begin(), arr.end());
    int result = 1;
    for(int i = n - 1; i >= 0; --i)
    {
        if(arr[i] <= i + 1)
        {
            result += i + 1;
            break;
        }
    }
    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
