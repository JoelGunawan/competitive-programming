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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
pair<int, int> get_max(pair<int, int> a, pair<int, int> b) {
    pair<int, int> c = a, d = b;
    int m1 = min(a.fi, b.fi), m2 = min(a.se, b.se);
    a.fi -= m1, b.fi -= m1;
    a.se -= m2, b.se -= m2;
    // calculate difference
    if(a.se > b.se)
        swap(a, b);
    if(b.se >= a.se && b.fi >= a.fi) {
        return max(c, d);
    }
    if(log(3) * b.se > log(2) * a.fi) {
        // berarti choose yg se lebih besar -> fi lebih kecil
        return min(c, d);
    }
    else
        return max(c, d);
}
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    char grid[n + 1][n + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> grid[i][j];
    int hor[n + 1][n + 1][4], ver[n + 1][n + 1][4], d1[n + 1][n + 1][4], d2[n + 1][n + 1][4];
    memset(hor, 0, sizeof(hor));
    memset(ver, 0, sizeof(ver));
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
    // fi -> count of 2
    // se -> count of 3
    pair<int, int> mx = mp(0, 0);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int k = 0; k < 4; ++k) {
                hor[i][j][k] = hor[i][j - 1][k];
                ver[i][j][k] = ver[i - 1][j][k];
                d1[i][j][k] = d1[i - 1][j - 1][k];
                d2[i][j][k] = d2[i - 1][j + 1][k];
            }
            ++hor[i][j][grid[i][j] - '0'];
            ++ver[i][j][grid[i][j] - '0'];
            ++d1[i][j][grid[i][j] - '0'];
            ++d2[i][j][grid[i][j] - '0'];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            // set (i, j) as midpoint
            // find horizontal and vertical max nya brp tanpa 0
            int r = n + 1, l = 0, u = 0, d = n + 1;
            // r
            int cl = j, cr = n;
            while(cl <= cr) {
                int mid = (cl + cr) / 2;
                if(hor[i][mid][0] - hor[i][j - 1][0]) 
                    cr = mid - 1, r = mid;
                else
                    cl = mid + 1;
            }
            // l
            cl = 1, cr = j;
            while(cl <= cr) {
                int mid = (cl + cr) / 2;
                if(hor[i][j][0] - hor[i][mid - 1][0])
                    cl = mid + 1, l = mid;
                else
                    cr = mid - 1;
            }
            // u
            cl = 1, cr = i;
            while(cl <= cr) {
                int mid = (cl + cr) / 2;
                if(ver[i][j][0] - ver[mid - 1][j][0])
                    cl = mid + 1, u = mid;
                else
                    cr = mid - 1;
            }
            // d
            cl = i, cr = n;
            while(cl <= cr) {
                int mid = (cl + cr) / 2;
                if(ver[mid][j][0] - ver[i - 1][j][0])
                    cr = mid - 1, d = mid;
                else
                    cl = mid + 1;
            }
            int dist = min({j - l, r - j, i - u, d - i});
            if(dist >= 0) {
                int two = 0, three = 0;
                two += hor[i][j + dist - 1][2] - hor[i][j - dist][2];
                three += hor[i][j + dist - 1][3] - hor[i][j - dist][3];
                two += ver[i + dist - 1][j][2] - ver[i - dist][j][2];
                three += ver[i + dist - 1][j][3] - ver[i - dist][j][3];
                if(grid[i][j] == '2')
                    --two;
                else if(grid[i][j] == '3')
                    --three;
                //cout << i << " " << j << " " << two << " " << three << " " << mx.fi << " " << mx.se << endl;
                mx = get_max(mx, mp(two, three));
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            int dist = n + 1;
            int cl = 0, cr = (n - max(i, j));
        }
    }
    // binser closest 0 position in diagonal
    // binser closest 0 position in hor, vert
    // terus pake prefix buat cri count of 2, 3
    //cout << mx.fi << " " << mx.se << endl;
    // jangan lupa case all zero
    cout << (powmod(2, mx.fi) * powmod(3, mx.se)) % mod << endl;
    return 0;
}