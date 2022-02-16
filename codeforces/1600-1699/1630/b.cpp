
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
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int b[n];
    for(int i = 0; i < n; ++i)
        b[i] = a[i];
    sort(b, b + n);
    int choose = (n + k) / 2 + (n + k) % 2, min_dist = INT_MAX, l, r;
    for(int i = 0; i <= n - choose; ++i) {
        if(min_dist > b[i + choose - 1] - b[i])
            min_dist = b[i + choose - 1] - b[i], l = b[i], r = b[i + choose - 1];
    }
    int last_max = 0, cur = 0, prev = 0, arr_cnt = 1;
    cout << l << " " << r << endl;
    for(int i = 0; i < n; ++i) {
        if(a[i] >= l && a[i] <= r) 
            ++cur;
        else
            --cur;
        if(cur > last_max && arr_cnt != k)
            ++arr_cnt, ++last_max, cout << prev + 1 << " " << i + 1 << endl, prev = i + 1;
    }
    cout << prev + 1 << " " << n << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}