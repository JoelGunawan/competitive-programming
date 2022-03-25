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
int c[4005];
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // cek setiap subarray apakah jika di sort a[l...r] = b[l...r]
    // buat dp O(n^2) dulu
    // kok bisa a[l...r] = b[l...r]
    // cara pemeriksaan yang O(n^2) gimana?
    // probably cuma bisa O(n^2 log n^2)
    // bisa dicoba sih ._.
    // maintain count of each number in a subarray using BIT + coord compression
    // get sum of array
    // kalo misal ada di a tambahi 1
    // kalo misal ada di b kurangi 1
    // kalo misal ada value yang bukan 0 maka tidak mungkin valid
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    set<int> coords;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], coords.ins(a[i]);
    for(int i = 1; i <= n; ++i)
        cin >> b[i], coords.ins(b[i]);
    ll dp[n];
    memset(dp, 0, sizeof(dp));
    map<int, int> tmp;
    int tmp2 = 0;
    for(auto i : coords) {
        tmp[i] = tmp2++;
    }
    for(int i = 1; i <= n; ++i)
        a[i] = tmp[a[i]];
    for(int i = 1; i <= n; ++i)
        b[i] = tmp[b[i]];
    ll res = 0;
    for(int i = 1; i < n; ++i) {
        // kita maintain count of indices yang non zero
        // tiap update kita cek tiap indeks apakah berubah atau tidak
        // jika case a == b maka tidak usah ganti
        // transisi -> O(nlogn) untuk tiap posisi
        // tinggal buat dp dimana pasti ada 1 (current segment aja)
        // ditambah dengan dp sisanya (l - 1)
        int wrong_cnt = 0;
        for(int j = i; j >= 1; --j) {
            // determine if (j, i) is a valid segment
            if(a[j] != b[j]) {
                if(c[a[j]] == 0)
                    ++wrong_cnt;
                ++c[a[j]];
                if(c[a[j]] == 0)
                    --wrong_cnt;
                if(c[b[j]] == 0)
                    ++wrong_cnt;
                --c[b[j]];
                if(c[b[j]] == 0)
                    --wrong_cnt;
            }
            if(wrong_cnt == 0) {
                // add current segment into range
                //cout << j << " " << i << endl;
                dp[i] += dp[j - 1] + 1;
            }
        }
        memset(c, 0, sizeof(c));
        dp[i] %= mod;
        res += dp[i];
        res %= mod;
    }
    cout << res << endl;
    return 0;
}