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
bool prime(int n) {
    if(n == 1)
        return 0;
    for(int i = 2; i <= sqrt(n); ++i)
        if(n % i == 0)
            return 0;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bool win = 0;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i = a; i <= b; ++i) {
        bool ans = 1;
        for(int j = c; j <= d; ++j) {
            if(prime(i + j))
                ans = 0;
        }
        if(ans)
            cout << "Takahashi" << endl, exit(0);
    }
    cout << "Aoki" << endl;
    return 0;
}