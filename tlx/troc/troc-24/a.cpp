#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define lll __int128
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fi first
#define se second
#define ins insert
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        if(a[i] == b[i])
            ++cnt;
    cout << cnt << endl;
    return 0;
}