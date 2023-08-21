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
int grid[105][105];
int n, m;
// 0 -> black
// 1 -> white
// 2 -> top white left white
// 3 -> top white right white
// 4 -> bottom white left white
// 5 -> bottom white right white
void print() {
    char output[205][205];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            //assert(grid[i][j] != -1);
            if(grid[i][j] == 0) {
                output[2 * i][2 * j] = '#';
                output[2 * i + 1][2 * j] = '#';
                output[2 * i][2 * j + 1] = '#';
                output[2 * i + 1][2 * j + 1] = '#';
            }
            else if(grid[i][j] == 1) {
                output[2 * i][2 * j] = '.';
                output[2 * i + 1][2 * j] = '.';
                output[2 * i][2 * j + 1] = '.';
                output[2 * i + 1][2 * j + 1] = '.';
            }
            else if(grid[i][j] == 2) {
                output[2 * i][2 * j] = '.';
                output[2 * i + 1][2 * j] = '/';
                output[2 * i][2 * j + 1] = '/';
                output[2 * i + 1][2 * j + 1] = '#';
            }
            else if(grid[i][j] == 3) {
                output[2 * i][2 * j] = 92;
                output[2 * i + 1][2 * j] = '#';
                output[2 * i][2 * j + 1] = '.';
                output[2 * i + 1][2 * j + 1] = 92;
            }
            else if(grid[i][j] == 4) {
                output[2 * i][2 * j] = 92;
                output[2 * i + 1][2 * j] = '.';
                output[2 * i][2 * j + 1] = '#';
                output[2 * i + 1][2 * j + 1] = 92;
            }
            else {
                output[2 * i][2 * j] = '#';
                output[2 * i + 1][2 * j] = '/';
                output[2 * i][2 * j + 1] = '/';
                output[2 * i + 1][2 * j + 1] = '.';
            }
        }        
    }
    for(int i = 0; i < 2 * n; ++i) {
        for(int j = 0; j < 2 * m; ++j)
            cout << output[i][j];
        cout << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // algo constructive, selalu ada jawaban klo dia bs di pairing jadi bentuk a dan b gtu?
    // m = c
    memset(grid, -1, sizeof(grid));
    cin >> n >> m;
    int a, b, c;
    cin >> a >> b >> c;
    char ans[2 * n][2 * m];
    for(int i = 0; i < 2 * n; ++i) {
        for(int j = 0; j < 2 * m; ++j) {
            ans[i][j] = 'a';
        }
    }
    if(a % m == 0) {
        // berarti garis lurus
        for(int i = 0; i < a / m; ++i) {
            for(int j = 0; j < m; ++j) {
                grid[i][j] = 0;
            }
        }
        int tmp = a / m;
        for(int i = 0; i < m; ++i) {
            if(i & 1) {
                grid[tmp][i] = 4;
            }
            else {
                grid[tmp][i] = 5;
            }
        }
    }
    else {
        // berarti bukan garis lurus
        for(int i = 0; i < a / m; ++i) {
            for(int j = 0; j < m; ++j) {
                grid[i][j] = 0;
            }
        }
        int mid = a / m;
        for(int i = 0; i < (a % m); ++i) {
            grid[mid][i] = 0;
        }
        int idx = 0;
        for(int i = a % m; i < m; ++i) {
            if(idx & 1) {
                grid[mid][i] = 4;
            }
            else {
                grid[mid][i] = 5;
            }
            ++idx;
        }
        idx = 0;
        ++mid;
        for(int i = (a % m) - 1; i >= 0; --i) {
            if(idx & 1) {
                grid[mid][i] = 4;
            }
            else {
                grid[mid][i] = 5;
            }
            ++idx;
        }
        --mid;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == -1) {
                --b;
                grid[i][j] = 1;
                if(b == 0)
                    break;
            }
        }
        if(b == 0)
            break;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == -1) {
                if(j == 0) {
                    if(grid[i - 1][j] == 1 || grid[i - 1][j] == 4 || grid[i - 1][j] == 5) {
                        // white
                        grid[i][j] = 2;
                    }
                    else    
                        grid[i][j] = 4;
                }
                else {
                    // tergantung atas dan kiri
                    bool uw, lw;
                    uw = grid[i - 1][j] == 1 || grid[i - 1][j] == 4 || grid[i - 1][j] == 5;
                    lw = grid[i][j - 1] == 1 || grid[i][j - 1] == 3 || grid[i][j - 1] == 5;
                    if(uw && lw) {
                        grid[i][j] = 2;
                    }
                    else if(uw) {
                        grid[i][j] = 3;
                    }
                    else if(lw) {
                        grid[i][j] = 4;
                    }
                    else {
                        grid[i][j] = 5;
                    }
                }
            }
        }
    }
    print();
    return 0;
}