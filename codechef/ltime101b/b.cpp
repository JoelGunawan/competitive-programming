#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll find_sum(ll begin, ll end, ll diff)
{
    return ((end - begin) / diff + 1) * (begin + end) / 2;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n, v;
        cin >> n >> v;
        cout << n * (n - 1) / 2 << " ";
        ll res = 0;
        v = min(n - 1, v);
        res = find_sum(1, (n - v), 1) + v - 1;
        cout << res << endl;
    }
    return 0;
}