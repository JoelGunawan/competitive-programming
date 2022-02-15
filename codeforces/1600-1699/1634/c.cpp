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
    int n, k;
    cin >> n >> k;
    // a even, b odd
    int a = n * k / 2, b = n * k / 2 + (n * k) % 2;
    if(a % k == 0 && b % k == 0) {
        cout << "YES" << endl;
        for(int i = 0; i < a / k; ++i) {
            for(int j = 0; j < k; ++j) {
                cout << 2 * i * k + 2 * j + 2 << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < b / k; ++i) {
            for(int j = 0; j < k; ++j) {
                cout << 2 * i * k + 2 * j + 1 << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}