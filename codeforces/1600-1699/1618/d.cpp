#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ll long long
#define lll __int128
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
void tc() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int score = 0;
    for(int i = 0; i < k; ++i) {
        score += (a[n - k - i - 1] / a[n - i - 1]);
    }
    for(int i = 0; i < n - 2 * k; ++i)
        score += a[i];
    cout << score << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}