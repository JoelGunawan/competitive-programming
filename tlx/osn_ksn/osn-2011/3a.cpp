#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
    int n, x[5001], y[5001];
    memset(x, 0, sizeof(x)), memset(y, 0, sizeof(y));
    cin >> n;
    int inputx[n], inputy[n];
    for(int i = 0; i < n; ++i)
        cin >> inputx[i] >> inputy[i], ++x[inputx[i]], ++y[inputy[i]];
    ull res = 0;
    for(int i = 0; i < n; ++i)
        res += (x[inputx[i]] - 1LL) * (y[inputy[i]] - 1LL);
    cout << res << endl;
    return 0;
}