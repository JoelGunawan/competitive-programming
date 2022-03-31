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
    ll n;
    cin >> n;
    bool a[n + 1];
    memset(a, 0, sizeof(a));
    ll sum = (n * (n + 1)) / 2;
    if(sum & 1) 
        cout << "NO" << endl, exit(0);
    cout << "YES" << endl;
    sum /= 2;
    int largest_used = n + 1;
    int cnt = 0;
    while(sum > 0) {
        if(sum < largest_used)
            a[sum] = 1, sum = 0;
        else {
            a[largest_used - 1] = 1;
            --largest_used;
            sum -= largest_used;
        }
        ++cnt;
    }
    cout << cnt << endl;
    for(int i = 1; i <= n; ++i)
        if(a[i])
            cout << i << " ";
    cout << endl;
    cout << n - cnt << endl;
    for(int i = 1; i <= n; ++i)
        if(!a[i])
            cout << i << " ";
    cout << endl;
    return 0;
}