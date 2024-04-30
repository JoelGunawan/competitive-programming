#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int r = -1, distinct = 0;
    int cnt[1000005];
    memset(cnt, 0, sizeof(cnt));
    int mx = 0;
    pair<int, int> range;
    for(int i = 0; i < n; ++i) {
        // dua kemungkinan: 
        // cek apakah dia bisa ke kanan (belum di n - 1)
        // cek apakah distinct < k
        // jika distinct = k, maka yg kita tambahkan HARUS sudah muncul sebelumnya
        while(r < n - 1 && (distinct < k || (distinct == k && cnt[a[r + 1]] > 0))) {
            ++r;
            if(cnt[a[r]] == 0)
                ++distinct;
            ++cnt[a[r]];
        }
        // utk l = i, r terjauh sama dengan r
        // segmen dari i ke r, maka ada r - i + 1 elemen
        if(r - i + 1 > mx) {
            mx = r - i + 1;
            range = make_pair(i + 1, r + 1);
        }
        // keluarkan elemen ke-i dari segmen
        --cnt[a[i]];
        if(cnt[a[i]] == 0) {
            --distinct;
        }
    }
    cout << range.first << " " << range.second << endl;
}