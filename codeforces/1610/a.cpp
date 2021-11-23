#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#pragma GCC optimize("Ofast")
using namespace std;
void test_case()
{
    int n, m;
    cin >> n >> m;
    if(n == 1 && m == 1)
        cout << 0 << endl;
    else
        cout << min(n, min(m, 2)) << endl;
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