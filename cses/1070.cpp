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
    int n;
    cin >> n;
    if(n == 2 || n == 3)
        cout << "NO SOLUTION" << endl;
    else {
        for(int i = 2; i <= n; i += 2)
            cout << i << " ";
        for(int i = 1; i <= n; i += 2)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}