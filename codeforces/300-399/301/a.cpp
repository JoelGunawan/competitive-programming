#// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[2 * n - 1];
    int negative = 0;
    for(int i = 0; i < 2 * n - 1; ++i)
        cin >> a[i], negative += (int)(a[i] <= 0), a[i] = abs(a[i]);
    if(negative > n)
        negative -= n;
    int res = 0;
    sort(a, a + 2 * n - 1);
    reverse(a, a + 2 * n - 1);
    for(int i = 0; i < 2 * n - 1; ++i)
        res += a[i];
    if(negative % 2 == 1 && n % 2 == 0)
        res -= 2 * a[2 * n - 2];
    cout << res << endl;
    return 0;
}