#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    bool k = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] != b[i] && a[i] % b[0] != 0)
        {
            k = 1;
            break;
        }
    }
    if(k) cout << "No";
    else cout << "Yes";
    cout << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}