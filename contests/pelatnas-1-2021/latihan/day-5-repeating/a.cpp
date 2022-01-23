#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct pref_2d {
    int a[2001][2001];
    void build(vector<vector<int>> arr) {
        memset(a, 0, sizeof(a));
        for(int i = 0; i < arr.size(); ++i) {
            for(int j = 0; j < arr[i].size(); ++j) {
                a[i][j] = arr[i][j];
                if(i != 0 && j != 0)
                    a[i][j] -= a[i - 1][j - 1];
                if(i != 0)
                    a[i][j] += a[i - 1][j];
                if(j != 0)
                    a[i][j] += a[i][j - 1];
            }
        }
    }
    int query(int x1, int y1, int x2, int y2) {
        return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q; 
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0)), b = a, c = a;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            char x;
            cin >> x;
            a[i][j] = x - '0';
            if(a[i][j] & a[i - 1][j])
                b[i][j] = 1;
            if(a[i][j] & a[i][j - 1])
                c[i][j] = 1;
        }
    }
    pref_2d all, vert, hor;
    all.build(a), vert.build(b), hor.build(c);
    while(q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << all.query(x1, y1, x2, y2) - vert.query(x1 + 1, y1, x2, y2) - hor.query(x1, y1 + 1, x2, y2) << endl;
    }
    return 0;
}