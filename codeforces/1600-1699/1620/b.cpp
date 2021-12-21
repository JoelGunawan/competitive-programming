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
    int w, h;
    cin >> w >> h;
    ll res = 0;
    int k, arr[200001];
    for(int j = 0; j < 2; ++j) {
        cin >> k;
        for(int i = 0; i < k; ++i)
            cin >> arr[i];
        res = max(res, 1ll * (arr[k - 1] - arr[0]) * h);
    }
    for(int j = 0; j < 2; ++j) {
        cin >> k;
        for(int i = 0; i < k; ++i)
            cin >> arr[i];
        res = max(res, 1ll * (arr[k - 1] - arr[0]) * w);
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