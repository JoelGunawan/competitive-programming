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
    int n;
    cin >> n;
    int lmin, lmax;
    cin >> lmin >> lmax;
    int x[2][n], y[2][n], z[2][n];
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < n; ++j)
            cin >> x[i][j];
        for(int j = 0; j < n; ++j)
            cin >> y[i][j];
        for(int j = 0; j < n; ++j)
            cin >> x[i][j];
    }
    // consider tiap konfigurasi column yang valid
    // coba gabungkan antara beberapa column dan cek apakah konfigurasi tersebut valid dalam row
    
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    // cek cara penggambaran yang valid untuk tiap row
    // coba pasangkan cara penggambaran yang valid
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}