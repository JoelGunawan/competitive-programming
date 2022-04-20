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
int solve(int n, int d, bool ori = 0) {
    if(d == 1) {
        if(ori) {
            n -= 30;
            if(n <= 0)
                return n;
            else
                return solve(n, 3);
        }
        n %= 91;
        if(n == 0)
            return n;
        n -= 30;
        if(n <= 0)
            return n;
        else
            return solve(n, 3);
    }
    else if(d == 2) {
        n -= 30;
        if(n <= 0)
            return n;
        else
            return solve(n, 4);
    }
    else if(d == 3) {
        n -= 30;
        if(n <= 0)  
            return n;
        else
            return solve(n, 5);
    }
    else if(d == 4) {
        n -= 32;
        if(n <= 0)
            return n;
        else
            return solve(n, 1);
    }
    else {
        n -= 31;
        if(n <= 0)
            return n;
        else
            return solve(n, 1);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string t; int n;
    cin >> t >> n;
    int d[n];
    for(int i = 0; i < n; ++i)
        cin >> d[i];
    // determine start day, cycle sampe jadi ke hari senin
    int x;
    if(t == "Mon")
        x = 1;
    else if(t == "Tue")
        x = 2;
    else if(t == "Wed")
        x = 3;
    else if(t == "Thu")
        x = 4;
    else if(t == "Fri")
        x = 5;
    else if(t == "Sat")
        x = 6;
    else
        x = 7;
    --x;
    int res = INT_MIN;
    for(int i = 0; i < n; ++i) {
        int day = (x - d[i]) % 7;
        day += 7;
        day %= 7;
        ++day;
        res = max(res, solve(d[i], day, 1));
    }
    cout << -res << endl;
    return 0;
}