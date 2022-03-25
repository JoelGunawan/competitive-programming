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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // tiap box isi n
    // tiap box -> pairing of 2 numbers
    // buat tiap pair yang < n harus dipasangkan dengan color lain
    // buat pair yang > n bebas
    // misal 1 2 3 4 |4 4 4 4| |4 4 4 4| |4 4 4 4|
    // misal 1 2 3 4 5 (4 11 times)
    // 1 4 4 4 2 4 4 4 3 4 4 4 5 4 4 4
    // pair count paling dikit dengan count paling banyak
    // apakah ada counter case?
    // 
    // kita harus pasangkan 1 dengan 4
    // dst
    // for each color pair check if such pair should exist?
    // buat pair yang == n dibuat n
    int n;
    cin >> n;
    int c[n * n];
    for(int i = 0; i < n * n; ++i)
        cin >> c[i];
    int cnt[n + 2];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n * n; ++i) 
        ++cnt[c[i]];
    // pair least non zero with max non zero
    // when is it not possible
    // never?
    vector<int> op[n + 2];
    cout << "YES" << endl;
    for(int i = 0; i < n; ++i) {
        int minimum = INT_MAX, min_idx, maximum = 0, max_idx;
        for(int j = 1; j <= n + 1; ++j) {
            if(cnt[j] != 0) {
                if(cnt[j] < minimum) {
                    min_idx = j, minimum = cnt[j];
                }
            }
        }
        for(int j = n + 1; j >= 1; --j) {
            if(cnt[j] > maximum) {
                    max_idx = j, maximum = cnt[j];
            }
        }
        //cout << min_idx << " " << max_idx << " " << minimum << " " << maximum << endl;
        if(min_idx == max_idx || minimum >= n) {
            cnt[min_idx] -= n;
            for(int k = 0; k < n; ++k)
                op[min_idx].pb(i + 1);
        }
        else {
            cnt[min_idx] -= minimum;
            cnt[max_idx] -= (n - minimum);
            for(int k = 0; k < minimum; ++k) {
                op[min_idx].pb(i + 1);
            }    
            for(int k = 0; k < n - minimum; ++k) {
                op[max_idx].pb(i + 1);
            }
        }
    }
    // pair min cnt and max cnt
    //for(int i = 1; i <= n + 1; ++i) {
    //    for(auto j : op[i])
    //        cout << j << " ";
    //    cout << endl;
    //}
    // ijin ke toilet :D
    for(int i = 0; i < n * n; ++i) {
        if(op[c[i]].size() == 0)
            exit(0);
        cout << op[c[i]].back() << " ", op[c[i]].pop_back();
    }
    cout << endl;
    return 0;
}