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
struct sparse_table {

};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // find how many subarrays does a[i] become minmum
    // find how many subarrays does a[i] become maximum
    // keep in mind if there are 2 minimums
    // we need to select only one of them
    // so to one side it's <, the other is <=
    // same applies to maximum
    int left_min[n], right_min[n], left_max[n], right_max[n];
    stack<pair<int, int>> s;
    for(int i = 0; i < n; ++i) {
        while(s.size() > 0 && s.top().fi >= a[i])
            s.pop();
        if(s.size() == 0)
            left_min[i] = i;
        else
            left_min[i] = i - s.top().se - 1;
        s.push(mp(a[i], i));
    }
    while(s.size() > 0)
        s.pop();
    //s.push(mp(0, n - 1));
    for(int i = n - 1; i >= 0; --i) {
        while(s.size() > 0 && s.top().fi > a[i])
            s.pop();
        if(s.size() == 0)
            right_min[i] = (n - 1) - i;
        else
            right_min[i] = s.top().se - i - 1;
        s.push(mp(a[i], i));
    }
    while(s.size() > 0)
        s.pop();
    for(int i = 0; i < n; ++i) {
        while(s.size() > 0 && s.top().fi <= a[i])
            s.pop();
        if(s.size() == 0)
            left_max[i] = i;
        else
            left_max[i] = i - s.top().se - 1;
        s.push(mp(a[i], i));
    }
    while(s.size() > 0)
        s.pop();
    //s.push(mp(1e9, n - 1));
    for(int i = n - 1; i >= 0; --i) {
        while(s.size() > 0 && s.top().fi < a[i])
            s.pop();
        if(s.size() == 0)
            right_max[i] = (n - 1) - i;
        else
            right_max[i] = s.top().se - i - 1;
        s.push(mp(a[i], i));
    }
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        //cout << left_min[i] << " " << right_min[i] << " " << left_max[i] << " " << right_max[i] << endl;
        res += 1ll * (left_max[i] + 1) * (right_max[i] + 1) * a[i];
        res -= 1ll * (left_min[i] + 1) * (right_min[i] + 1) * a[i];
    }
    cout << res << endl;
    return 0;
}