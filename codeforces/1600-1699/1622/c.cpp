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
void tc() {
    int n; ll k;
    cin >> n >> k;
    int a[n + 1];
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a, a + n + 1);
    ll prefix[n + 1];
    prefix[0] = 0;
    for(int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] + a[i];
    ll res = LLONG_MAX;
    // go from back to front
    // count how many decrease operations would be necessary to accomplish a valid arrangement with x amount
    for(int i = n + 1; i > 1; --i) {
        ll tmp = k;
        tmp -= prefix[i - 1] - prefix[1];
        int remaining = n - i + 2;
        ll required = floor(1.0 * tmp / remaining), local = 0;
        if(a[1] > required)
            local += a[1] - required;
        local += remaining - 1;
        //cout << i << " " << local << " " << required << " " << remaining << " " << a[1] <<  endl;
        res = min(res, local);
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}