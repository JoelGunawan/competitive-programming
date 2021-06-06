#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n / 2; ++i)
    {
        sum1 += arr[i];
        sum2 += arr[n - i - 1];
    }
    if(n % 2 == 1)
    {
        sum2 += arr[n / 2];
    }
    cout << (long long)sum1 * (long long)sum1 + (long long)sum2 * (long long)sum2 << endl;
    return 0;
}
