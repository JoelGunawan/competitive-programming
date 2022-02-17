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
    int n, m;
    cin >> n >> m;
    bool a[n][m];
    // transisi 2x2:
    // 4 -> 1 -> 2 -> 3 -> 0
    // tricky case -> non even size
    // need: 3 * 3, 3 * 2 case
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) {
            char x;
            cin >> x;
            a[i][j] = x == '1';
        }
    vector<vector<int>> operations;
    for(int i = 0; i < n - 2; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[i][j]) {
                vector<int> cur;
                // choose current cell and 2 right cells
                cur.pb(i), cur.pb(j);
                a[i][j] = !a[i][j];
                cur.pb(i + 1), cur.pb(j);
                a[i + 1][j] = !a[i + 1][j];
                cur.pb(i + 1);
                if(j != 0)
                    cur.pb(j - 1), a[i + 1][j - 1] = !a[i + 1][j - 1];
                else
                    cur.pb(j + 1), a[i + 1][j + 1] = !a[i + 1][j + 1];
                operations.pb(cur);
            }
        }
    }
    for(int j = 0; j < m - 2; ++j) {
        for(int i = n - 2; i < n; ++i) {
            if(a[i][j]) {
                vector<int> cur;
                cur.pb(i), cur.pb(j);
                a[i][j] = !a[i][j];
                
                cur.pb(n - 1), cur.pb(j + 1);
                a[n - 1][j + 1] = !a[n - 1][j + 1];
                
                cur.pb(n - 2), cur.pb(j + 1);
                a[n - 2][j + 1] = !a[n - 2][j + 1];
                operations.pb(cur);
            }
        }
    }
    // 4 -> select 1
    // 3 -> select 0
    // 2 -> select 1
    // 1 -> select 0
    vector<pair<bool, pair<int, int>>> arr;
    for(int i = n - 2; i < n; ++i) {
        for(int j = m - 2; j < m; ++j) {
            arr.pb(mp(a[i][j], mp(i, j)));
        }
    }
    for(int i = 0; i < 4; ++i) {
        int cnt = 0;
        for(auto j : arr)
            cnt += j.fi;
        //cout << cnt << endl;
        if(!cnt)
            break;
        if(cnt & 1) {
            int selected;
            for(int j = 0; j < arr.size(); ++j) {
                if(!arr[j].fi)
                    selected = j;
            }
            vector<int> cur;
            for(auto j : arr) {
                if(j != arr[selected])
                    cur.pb(j.se.fi), cur.pb(j.se.se);
            }
            for(int j = 0; j < arr.size(); ++j)
                if(j != selected)
                    arr[j].fi = !arr[j].fi;
            operations.pb(cur);
        }
        else {
            int selected;
            for(int j = 0; j < arr.size(); ++j) {
                if(arr[j].fi)
                    selected = j;
            }
            vector<int> cur;
            for(auto j : arr) {
                if(j != arr[selected])
                    cur.pb(j.se.fi), cur.pb(j.se.se);
            }
            for(int j = 0; j < arr.size(); ++j)
                if(j != selected)
                    arr[j].fi = !arr[j].fi;
            operations.pb(cur);
        }
    }
    cout << operations.size() << endl;
    for(auto i : operations) {
        for(auto j : i)
            cout << j + 1 << " ";
        cout << endl;
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