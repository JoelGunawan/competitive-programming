#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, a[10000], res;
    double sum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum = 0, res = 0;
        for(int i = 0; i < n; ++i)
            cin >> a[i], sum += a[i];
        sum /= n;
        for(int i = 0; i < n; ++i)
            if(a[i] < sum)
                ++res;
        cout << res << endl;
    }
    return 0;
}