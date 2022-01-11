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
struct prefsum {
    vector<ll> a;
    void build(vector<int> arr) {
        a = vector<ll>(arr.size() + 1);
        a[0] = 0;
        for(int i = 0; i < arr.size(); ++i)
            a[i + 1] = a[i] + arr[i];
    }
    ll query(int l, int r) {
        return a[r + 1] - a[l];
    }
};
void tc() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // dp O(nsqrtn)
    reverse(a.begin(), a.end());
    prefsum pref;
    pref.build(a);
    int x = 0;
    while(x * (x + 1) / 2 < n)
        ++x;
    queue<pair<ll, int>> q[x + 1];
    ll maxval[x + 1];
    memset(maxval, 0, sizeof(maxval));
    maxval[0] = LLONG_MAX;
    int res = 0;
    for(int i = 0; i < n; ++i) {
        //cout << i << endl;
        for(int j = 1; j <= x; ++j) {
            if(q[j].size() > 0 && q[j].front().se == i)
                maxval[j] = max(maxval[j], q[j].front().fi), q[j].pop();
        }
        for(int j = 1; j <= x && i - j + 1 >= 0; ++j) {
            if(maxval[j - 1] > pref.query(i - j + 1, i)) {
                //cout << j << " " << maxval[j - 1] << " " << pref.query(i - j + 1, i) << endl;
                q[j].push(mp(pref.query(i - j + 1, i), i + j + 1));
                res = max(res, j);
            }
        }
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