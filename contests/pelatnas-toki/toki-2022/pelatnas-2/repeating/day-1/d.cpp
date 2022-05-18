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
    int n, m, k;
    cin >> n >> m >> k;
    multiset<int> b;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        b.ins(x);
    }
    sort(a, a + n, greater<int>());
    for(auto i : a) {
        if(b.size() == 0 || b.lb(i) == b.end()) {
            cout << "BISA" << endl;
            return 0;
        }
        else
            b.erase(b.lb(i));
    }
    cout << "TIDAK" << endl;
    return 0;
}