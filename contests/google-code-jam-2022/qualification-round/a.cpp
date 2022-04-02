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
void solve() {
    int r, c;   
    cin >> r >> c;
    cout << "..";
    for(int i = 0; i < c - 1; ++i) {
        cout << "+-";
    }
    cout << "+" << endl;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(i == 0 && j == 0)
                cout << "..";
            else
                cout << "|.";
        }
        cout << "|" << endl;
        for(int j = 0; j < c; ++j) {
            cout << "+-";
        }
        cout << "+" << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ":" << endl;
        solve();
    }
    return 0;
}