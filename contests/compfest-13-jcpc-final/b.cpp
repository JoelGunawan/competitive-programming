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
    ll n, r;
    cin >> n >> r;
    pair<int, int> a[n];
    if(n == 1)
    {
        ll x, y;
        cin >> x >> y;
        if(x * x + y * y <= 4 * r * r)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    int x, y;
    // sampah subtask x[i] = 0
    for(int i = 0; i < n; ++i)
        cin >> x >> y, a[i] = {x, y};
    int counter[5 * (int)1e5], pref[5 * (int)1e5], zero = 25 * 1e4;
    memset(counter, 0, sizeof(counter));
    for(int i = 0; i < n; ++i)
        ++counter[zero + a[i].second];
    r = min((int)r, (int)1e5 + 1000);
    for(int i = 1; i < 5 * 1e5; ++i)
        pref[i] = pref[i - 1] + counter[i];
    int res = 0;
    for(int i = zero; i <= zero + 2 * r; ++i)
        // find highest
        res = max(res, pref[i] - pref[i - 2 * r - 1]);
    cout << res << endl;
    return 0;
}