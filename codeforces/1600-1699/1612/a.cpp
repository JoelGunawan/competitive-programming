#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("Ofast")
using namespace std;
void test_case()
{
    int x, y;
    cin >> x >> y;
    if((x + y) & 1)
        cout << -1 << " " << -1 << endl;
    else
    {
        int total = x + y;
        total /= 2;
        if(x >= y)
            cout << x - total << " " << y << endl;
        else
            cout << x << " " << y - total << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}