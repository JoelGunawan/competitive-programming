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
    int t;
    cin >> t;
    while(t--) {
        int n;
        ll h;
        cin >> n >> h;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        ll l = 1, r = h, res;
        while(l <= r) {
            ll mid = (l + r) / 2, tmp = 0, cur_time = 0;
            for(int i = 0; i < n; ++i) {
                if(cur_time >= a[i])
                    tmp += a[i] + mid - 1 - cur_time, cur_time = a[i] + mid - 1;
                else
                    tmp += mid, cur_time = a[i] + mid - 1;
            }
            if(tmp >= h)
                r = mid - 1, res = mid;
            else
                l = mid + 1;
        }
        cout << res << endl;
    }
    return 0;
}