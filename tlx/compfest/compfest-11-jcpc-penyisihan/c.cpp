#include <bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;
ll totalsum(ll a, ll b)
{
    return b * (b + 1) / 2 - a * (a + 1) / 2;
}
int main()
{
    int n, in1, in2;
    cin >> n;
    pair<int, bool> a[2 * n];
    for(int i = 0; i < n; ++i)
    {
        cin >> in1 >> in2;
        a[2 * i] = make_pair(in1, 0), a[2 * i + 1] = make_pair(in2, 1);
    }
    int prev = 0, counter = 0;
    ll res = 0;
    sort(a, a + 2 * n);
    for(int i = 0; i < 2 * n; ++i)
    {
        if(counter == 0)
            prev = a[i].first;
        if(a[i].second)
            --counter;
        else
            ++counter;
        if(counter == 0)
            res += totalsum(prev - 1, a[i].first);
    }
    cout << res << endl;
    return 0;
}