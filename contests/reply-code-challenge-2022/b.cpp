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
ifstream fin("input-grid-d94c.txt");
ofstream fout("output.txt");
void tc() {
    int n, m;
    fin >> n >> m;
    int a[n][n];
    int cnt = m;
    memset(a, 0, sizeof(a));
    pair<int, int> cur, last;
    for(int i = 0; i < m; ++i) {
        int x, y, cnt;
        fin >> x >> y >> cnt;
        a[x][y] += cnt;
        if(i == 0)
            cur = mp(x, y);
        if(i == m - 1)
            last = mp(x, y);
    }
    ll dist = 0;
    pair<int, int> prev = {-1, -1};
    while(cnt > 1) {
        pair<int, pair<int, int>> minimum = mp(INT_MAX, mp(INT_MAX, INT_MAX));
        if(cur == last)
            break;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(a[i][j] > 0 && mp(abs(i - cur.fi) + abs(j - cur.se), mp(i, j)) < minimum && mp(i, j) != cur && (mp(i, j) != prev || cnt == 2)) {
                    minimum = mp(abs(i - cur.fi) + abs(j - cur.se), mp(i, j));
                }
            }
        }
        --a[cur.fi][cur.se];
        if(a[cur.fi][cur.se] == 0)
            --cnt;
        dist += minimum.fi;
        prev = cur;
        cur = minimum.se;
        //fout << cnt << " " << prev.fi << " " << prev.se << " " << cur.fi << " " << cur.se << endl;
    }
    fout << dist << endl;
}
int main() {
    int t;
    fin >> t;
    for(int i = 0; i < t; ++i) {
        fout << "Case #" << i + 1 << ": ";
        tc();
    }   
    return 0;
}