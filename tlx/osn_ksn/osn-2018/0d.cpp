#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    string subsoal; int n, in, arr[(int)1e5 + 1];
    memset(arr, 0, sizeof(arr));
    cin >> subsoal >> n;
    for(int i = 0; i < n; ++i)
        cin >> in, ++arr[in];
    // a contains previous 1 pair
    // b contains previous 2 pair counter
    ll a = 0, b = 0, res = 0;
    for(int i = 1; i <= 1e5; ++i)
    {
        res += b * arr[i];
        b += a * arr[i];
        a += arr[i];
    }
    //cout << a << " " << b << endl;
    cout << res << endl;
    return 0;
}