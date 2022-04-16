// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
int scan(int x, int y) {
    cout << "SCAN " << x << " " << y << endl;
    int n;
    cin >> n;
    return n;
}
int dig(int x, int y) {
    cout << "DIG " << x << " " << y << endl;
    int n;
    cin >> n;
    return n;
}
void tc() {
    int n, m;
    cin >> n >> m;
    int sx, sy, dx, dy;
    int a = scan(1, 1), b = scan(1, m);
    sx = (a + b + 6 - 2 * m) / 2;
    sy = (a - b + 2 + 2 * m) / 2;
    int c = scan(sx / 2, 1), d = scan(1, sy / 2);
    dx = c - sy + 2, dy = d - sx + 2;
    //cout << sx << " " << sy << " " << dx << " " << dy << endl;
    int x1 = (sx - dx) / 2, x2 = (sx + dx) / 2, y1 = (sy - dy) / 2, y2 = (sy + dy) / 2;
    if(dig(x1, y1) == 1) {
        dig(x2, y2);
    }
    else {
        dig(x1, y2), dig(x2, y1);
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}