#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n = 1000000, m = 5000;
    int a[m];
    memset(a, 0, sizeof(a));
    for(int i = 0; i * i <= n; i++)
    {
        a[(i * i) % m]++;
    }
    for(int i = 1; i < m; ++i)
    {
        for(int j = 1; j <= n; j *= 2)
        {
            for(int k = 0; k >(-a[i]); --k)
                a[(j - k) % i]++;
        }
    }
    long long sum = 0;
    for(int i = 0; i < 5000; ++i)
        sum += a[i];
    cout << sum << endl;
    return 0;
}