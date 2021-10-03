#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define lll __int128
#define pb push_back
#define ins insert
#define ull unsigned long long
#define ullll unsigned __int128
#define pointer(it) *it
#define lb lower_bound
#define ub upper_bound
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);
    int n, k;
    cin >> n >> k;
    if(n == 2)
    {
        int neg = 0;
        int a, b;
        cin >> a >> b;
        if(a == -1 || b == -1)
            neg = 1;
        if(a == b && a != -1)
        {
            cout << 0 << endl;
            return 0;
        }
        cout << k - neg << endl;
    }
    return 0;
}