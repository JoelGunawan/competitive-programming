// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
    int a[n];
    for(int i = 0; i < n; ++i)  
        cin >> a[i];
    if(n == 1)
        cout << a[0] << endl, exit(0);
    sort(a, a + n);
    ll sum = 0;
    if(a[n - 1] < 0) {
        for(int i = 0; i < n - 1; ++i)
            sum += abs(a[i]);
        sum += a[n - 1];
    }
    else {
        for(int i = 1; i < n; ++i)
            sum += abs(a[i]);
        sum -= a[0];
    }
    cout << sum << endl;
    return 0;
}