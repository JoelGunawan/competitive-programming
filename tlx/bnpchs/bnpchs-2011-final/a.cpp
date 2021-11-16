#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
void solve()
{
    ll n, s, e;
    cin >> n >> s >> e;
    int a[n], x, y;
    for(int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        s += y;
        a[i] = x + y;
    }
    sort(a, a + n);
    int currentindex = 0;
    while(currentindex < n && s - a[currentindex] >= e)
        s -= a[currentindex++];
    cout << currentindex << " " << s << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}