#include <bits/stdc++.h>
 
using namespace std;
 
int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}
 
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), res(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n / 2; ++i)
    {
        int b = lcm(a[i], a[n - i - 1]);
        res[i] = b / a[i];
        res[n - i - 1] = -1 * b / a[n - i - 1];
    }
    for(int i = 0; i < n; ++i)
    {
        cout << res[i];
        if(i == n - 1) cout << endl;
        else cout << " ";
    }
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}