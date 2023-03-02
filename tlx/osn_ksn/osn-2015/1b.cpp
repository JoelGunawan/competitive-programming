// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
struct pref_sum {
    int a[1005][1005];
    pref_sum() {
        memset(a, 0, sizeof(a));
    }
    void build() {
        for(int i = 1; i <= 1000; ++i)
            for(int j = 1; j <= 1000; ++j) {
                a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            }
    }
    int query(int x1, int y1, int x2, int y2) {
        if(x1 > x2 || y1 > y2 || x1 <= 0 || y1 <= 0 || x2 > 1000 || y2 > 1000)
            return 0;
        else {
            return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string buang;
    cin >> buang;
    int n, m, q;
    cin >> n >> m >> q;
    pref_sum left, right, up, down, all;
    int arr[n + 5][m + 5];
    memset(arr, -1, sizeof(arr));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }  
    //for(int i = 1; i <= m; ++i)
    //    cout << i << " " << arr[1][i] << endl;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            left.a[i][j] = arr[i + 1][j] > arr[i][j] || arr[i][j + 1] > arr[i][j] || arr[i][j - 1] > arr[i][j];
            right.a[i][j] = arr[i - 1][j] > arr[i][j] || arr[i][j + 1] > arr[i][j] || arr[i][j - 1] > arr[i][j];
            up.a[i][j] = arr[i - 1][j] > arr[i][j] || arr[i][j + 1] > arr[i][j] || arr[i + 1][j] > arr[i][j];
            down.a[i][j] = arr[i - 1][j] > arr[i][j] || arr[i][j - 1] > arr[i][j] || arr[i + 1][j] > arr[i][j];
            all.a[i][j] = left.a[i][j] || right.a[i][j] || up.a[i][j] || down.a[i][j];
        }
    }
    int dow[n + 5][m + 5], u[n + 5][m + 5];
    memset(dow, 0, sizeof(dow));
    memset(u, 0, sizeof(u));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            u[i][j] = u[i][j - 1] + (arr[i][j] < arr[i][j - 1]);
            dow[i][j] = dow[i][j - 1] + (arr[i][j] < arr[i][j + 1]);
        }
    }
    left.build(), right.build(), up.build(), down.build(), all.build();
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a == c) {
            // only 1 line
            // WA here
            if(dow[a][d - 1] - dow[a][b - 1] == d - b) {
                cout << "Kanan Bawah" << endl;
            }
            else if(u[a][d] - u[a][b] == d - b) {
                cout << "Kiri Atas" << endl;
            }
            else
                cout << "Tidak Mungkin" << endl;
        }
        else {
            assert(a < c);
            // cek bagian atas
            // cek bagian kanan
            // cek bagian bawah
            // cek bagian kiri
            // cek all
            int cnt = up.query(a + 1, b, c - 1, b) + right.query(c, b + 1, c, d - 1) + down.query(a + 1, d, c - 1, d) + left.query(a, b + 1, a, d - 1) 
            + all.query(a + 1, b + 1, c - 1, d - 1) + (arr[b][c] < arr[b + 1][c] || arr[b][c] < arr[b][c - 1]) + (arr[a][d] < arr[a + 1][d] || arr[a][d] < arr[a][d - 1]);
            if(arr[a][b] > arr[a + 1][b] && arr[a][b] > arr[a][b + 1] && (arr[c][d] < arr[c - 1][d] || arr[c][d] < arr[c][d - 1]) && cnt + 2 == (c - a + 1) * (d - b + 1))
                cout << "Kiri Atas" << endl;
            else if(arr[c][d] > arr[c - 1][d] && arr[c][d] > arr[c][d - 1] && (arr[a][b] < arr[a + 1][b] || arr[a][b] < arr[a][b + 1]) && cnt + 2 == (c - a + 1) * (d - b + 1))
                cout << "Kanan Bawah" << endl;
            else
                cout << "Tidak Mungkin" << endl;
        }
    }
    return 0;
}