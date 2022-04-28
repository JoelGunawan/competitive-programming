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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int x[n / 2];
    for(int i = 0; i < n / 2; ++i)  
        cin >> x[i];
    ll ans[n], cur = 1, sum = 0;
    memset(ans, -1, sizeof(ans));
    bool exists = 1;
    for(int i = 0; i < n / 2; ++i) {
        while((cur + 1) * (cur + 1) - cur * cur <= x[i]) {
            ll l = cur + 1, r = 1e7, res = -1;
            while(l <= r) {
                ll m = (l + r) / 2;
                //cout << m * m << " " << cur * cur << " " << x[i] << endl;
                if(m * m == cur * cur + x[i]) {
                    res = m;
                    break;
                }
                else if(m * m < cur * cur + x[i])
                    l = m + 1;
                else
                    r = m - 1;
            }
            if(res == -1)
                ++cur;
            else {
                ans[2 * i] = cur * cur - sum;
                sum += ans[2 * i];
                ans[2 * i + 1] = res * res - sum;
                sum += ans[2 * i + 1];
                cur = res + 1;
                break;
            }
        }
        //cout << i << " " << ans[i] << endl;
        if(ans[2 * i] == -1)
            exists = 0;
    }
    if(exists) {
        cout << "Yes" << endl;
        for(int i = 0; i < n; ++i)
            cout << ans[i] << " ";
        cout << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}