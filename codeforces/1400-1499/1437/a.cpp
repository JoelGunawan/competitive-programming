#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    int l, r;
    cin >> l >> r;
    if(r / 2 < l) cout << "Yes";
    else cout << "No";
    cout << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}