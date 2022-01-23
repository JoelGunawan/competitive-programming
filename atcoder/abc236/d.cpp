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
int a[20][20];
set<int> cur;
ll ans = 0;
int n;
void brute(int depth, ll res) {
    //cout << depth << " " << res << endl;
    if(depth == n) {
        ans = max(ans, res);
    }
    else {
        //cout << "TEST1 " << cur.size() << endl;
        int tmp = *cur.begin();
        cur.erase(cur.begin());
        auto it = cur.begin();
        //cout << "TEST2" << endl;
        while(it != cur.end()) {
            //cout << *it << endl;
            int x = *it;
            cur.erase(it);
            brute(depth + 1, res ^ a[tmp][x]);
            cur.ins(x);
            it = cur.ub(x);
        }
        cur.ins(tmp);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= 2 * n; ++i) {
        for(int j = i + 1; j <= 2 * n; ++j)
            cin >> a[i][j], a[j][i] = a[i][j];
    }
    //for(int i = 1; i <= 2 * n; ++i) {
    //    for(int j = 1; j <= 2 * n; ++j)
    //        cout << a[i][j] << " ";
    //    cout << endl;
    //}
    for(int i = 1; i <= 2 * n; ++i)
        cur.ins(i);
    brute(0, 0);
    cout << ans << endl;
    return 0;
}