#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int x, y;
    for(int i = 0; i < n; ++i)
        cin >> x >> y;
    if(n < 3)
        cout << 0 << endl;
    else if(n == 3)
        cout << 1 << endl;
    else
        cout << n * (n - 1) * (n - 2) / 6 << endl;
    return 0;
}