#include <bits/stdc++.h>
 
using namespace std;
 
const int b = 4;
 
void solve()
{
    vector<int> a(b);
    for(int i = 0; i < b; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << a[0] * a[2] << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}