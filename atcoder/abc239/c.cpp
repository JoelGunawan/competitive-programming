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
ll sqr(ll a) {
    return a * a;
}
double dist(pair<int, int> x, pair<int, int> y) {
    return sqrt(sqr(x.fi - y.fi) + sqr(x.se - y.se));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1 - 10; i <= x1 + 10; ++i) {
        for(int j = y1 - 10; j <= y1 + 10; ++j) {
            pair<int, int> cur = mp(i, j);
            if(dist(cur, mp(x1, y1)) == dist(cur, mp(x2, y2)) && dist(cur, mp(x1, y1)) == sqrt(5))
                cout << "Yes" << endl, exit(0);
        }
    }
    cout << "No" << endl;
    return 0;
}