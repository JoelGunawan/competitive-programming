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
ll combin(ll a, ll b) {
    if(a - b > b)
        b = a - b;
    ll res = 1;
    for(int i = b + 1; i <= a; ++i) {
        res *= i;
    }
    for(int i = a - b; i > 1; --i)
        res /= i;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; double p;
    cin >> n >> p;
    for(int i = 0; i < n; ++i) {
        // we have i maps studied
        double cur = 0;
        // 3 studied -> if(i >= 3)
        // 2 studied -> if(i >= 2)
        // 1 studied -> if(i >= 1)
        if(i >= 3) {
            cur += combin(i, 3) * combin(n - i, 0) * 1.0 / combin(n, 3);
        }
        if(i >= 2) {
            cur += combin(i, 2) * combin(n - i, 1) * 1.0 / combin(n, 3);
        }
        if(i >= 1)
            cur += combin(i, 1) * combin(n - i, 2) * 0.5 / combin(n, 3);
        if(cur >= p)
            cout << i << endl, exit(0);
    }
    return 0;
}