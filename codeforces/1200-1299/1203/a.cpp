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
    int p[n];
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    int low, high;
    for(int i = 0; i < n; ++i) {
        if(p[i] == 1)
            low = i;
        else if(p[i] == n)
            high = i;
    }
    bool lowans = 1, highans = 1;
    for(int i = 0; i < n - 1; ++i) {
        if(p[low] + 1 == p[(low + 1) % n])
            low = (low + 1) % n;
        else
            lowans = 0;
        if(p[high] == p[(high + 1) % n] + 1)
            high = (high + 1) % n;
        else
            highans = 0;
    }
    if(highans || lowans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}