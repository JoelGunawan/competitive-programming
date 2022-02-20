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
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int left[n + 1], right[n + 1];
    ll res = 0;
    for(int i = 3; i < n; ++i) {
        ll cur = 0;
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        for(int j = 1; j < i; ++j)
            ++right[a[j]];
        for(int j = 1; j < i - 1; ++j) {
            // transition is
            // remove j from right and reduce res by the amount
            cur -= right[a[j]] * left[a[j]];
            if(a[j] != a[j - 1])
                cur -= right[a[j - 1]] * left[a[j - 1]];
            --right[a[j]];
            ++left[a[j - 1]];
            cur += right[a[j]] * left[a[j]];
            if(a[j] != a[j - 1])
                cur += right[a[j - 1]] * left[a[j - 1]];
            if(a[j] == a[i])
                res += cur;
        }
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}