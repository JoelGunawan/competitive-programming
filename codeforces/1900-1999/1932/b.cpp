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
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        ll cur = 0;
        for(int i = 1; i <= n; ++i) {
            ++cur;
            if(cur % a[i] != 0) 
                cur += a[i] - (cur % a[i]);
            //cout << "DEBUG " <<  a[i] - (cur % a[i]) << endl;
        }
        cout << cur << endl;
    }
    return 0;
}