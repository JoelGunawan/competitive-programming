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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int r, c;
    cin >> r >> c;
    char grid[r + 1][c + 1];
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j)
            cin >> grid[i][j];
    }
    if((r * c) & 1) {
        cout << "TIDAK MUNGKIN" << endl;
        return 0;
    }
    // else pasti possible
    int putih[r + 1], pref[r + 1];
    memset(pref, 0, sizeof(pref));
    memset(putih, 0, sizeof(putih));
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            if(grid[i][j] == 'o')
                ++putih[i];
        }
        pref[i] = pref[i - 1] + putih[i];
    }
    if(pref[r] == r * c / 2) {
        // no moves needed
        // just output
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < 4; ++j)
                cout << 1 << " ";
            cout << endl;
        }
        return 0;
    }
    pair<int, int> mn = mp((int)1e9, (int)1e9);
    for(int i = 1; i <= r; ++i) {
        // invert some prefix supaya pas
        // invert from 1..i
        //cout << pref[r] - pref[i] + i * c - pref[i] - r * c / 2 << " ";
        mn = min(mn, mp(abs((pref[r] - pref[i] + i * c - pref[i]) - r * c / 2), i));
    }
    //cout << endl;
    // udah dapet invert dr 1 ke i
    // nanti di invert dlu
    //cout << mn.se << endl;
    cout << 1 << " " << 1 << " " << mn.se << " " << c << endl;
    for(int i = 1; i <= mn.se; ++i) {
        putih[i] = c - putih[i];
        for(int j = 1; j <= c; ++j) {
            if(grid[i][j] == 'o')
                grid[i][j] = 'x';
            else
                grid[i][j] = 'o';
        }
    }
    ll cum = 0;
    for(int i = 1; i <= r; ++i) {
        //cout << putih[i] << " ";
        cum += putih[i];
    }
    //cout << endl;
    if(cum == r * c / 2) {
        // only output 1, terus nanti invert all
        cout << 1 << " " << 1 << " " << r << " " << c << endl;
        return 0;
    }
    int lebih = cum - r * c / 2;
    for(int i = 1; i <= r; ++i) {
        int w = 0, b = 0;
        for(int j = 1; j <= c; ++j) {
            if(grid[i][j] == 'o')
                ++w;
            else
                ++b;
            if(w - b == lebih) {
                cout << i << " " << 1 << " " << i << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}