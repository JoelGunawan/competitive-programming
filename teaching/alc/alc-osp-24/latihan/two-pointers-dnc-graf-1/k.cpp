#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int mx = 0;
    long long sum = 0;
    for(int i = 1; i <= n; ++i) {
        mx = max(mx, a[i]);
        sum += a[i];
    }
    // minimal: elemen max di a
    // maksimal: jumlah seluruh elemen di a
    long long l = mx, r = sum, ans = -1;
    while(l <= r) {
        long long mid = (l + r) / 2;
        // cek di mid apakah jumlah subarray jika max sumnya = mid itu <= k atau ngga?
        long long cur = 0;
        int cnt = 1;
        for(int i = 1; i <= n; ++i) {
            if(a[i] + cur > mid) {
                // buat subarray baru
                // di reset
                cur = 0;
                cnt++;
            }
            cur += a[i];
        }
        // cout << mid << " " << cnt << endl;
        // cnt terlalu besar, maka harus ke kanan
        if(cnt > k) {
            // ke kanan
            l = mid + 1;
        }
        else {
            // bisa dibuat dengan k subarray
            r = mid - 1, ans = mid;
        }
    }
    cout << ans << endl;
}