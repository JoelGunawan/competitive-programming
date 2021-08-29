#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), p(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    vector<ll> res(n, 0);
    ll pjsum = 0, totalsum = 0;
    for(int i = 1; i < n; ++i)
        pjsum += p[i - 1], totalsum += (a[i] - a[i - 1]) * pjsum, res[i] += totalsum;
    pjsum = 0, totalsum = 0;
    for(int i = n - 2; i >= 0; --i)
        pjsum += p[i + 1], totalsum += (a[i + 1] - a[i]) * pjsum, res[i] += totalsum;
    ll minimum = LLONG_MAX, output;
    for(int i = 0; i < n; ++i)
        if(res[i] < minimum)
            minimum = res[i], output = i;
    cout << output << endl;
    return 0;
}