#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
    return (long long)a.first * b.second < (long long)b.first * a.second;
}
int main() {
    long long n, m, a, b, q;
    cin >> n >> m >> a >> b >> q;
    cout << fixed << setprecision(3);
    for(int i = 1; i <= q; ++i) {
        long long x;
        cin >> x;
        // double tapi lebih presisi lebih tinggi
        long double l = 0, r = 1e9, ans;
        // double tidak bisa sama dengan
        // misal pilih 10^-10
        while(r - l > 1e-16) {
            long double mid = (l + r) / 2;
            // coba cari yg <= mid itu jumlahnya ada berapa
            long long cnt = 0;
            for(int i = 1; i <= n; ++i) {
                if((long long)(mid * (a + i) - b) > 0)
                    cnt += min((long long)(mid * (a + i) - b), m);
            }
            //cout << mid << "  " << cnt << endl;
            if(cnt == x) {
                ans = mid;
                break;
            }
            else if(cnt > x) {
                // bisa jadi jawabannya bener
                ans = mid;
                r = mid;
            }
            else {
                l = mid;
            }
        }
        // cari yg maks
        pair<int, int> mx = make_pair(1, 1e9);
        for(int i = 1; i <= n; ++i) {
            if((long long)(ans * (a + i) - b) > 0) {

                pair<int, int> x = make_pair(b + min((long long)(ans * (a + i) - b), m), a + i);
                // harus cek apakah lebih besar x atau mx
                if(compare(mx, x)) {
                    mx = x;
                }
                // alternatif: mx = max(mx, x, compare);
            }
        }
        cout << mx.first / __gcd(mx.first, mx.second) << "/" << mx.second / __gcd(mx.first, mx.second) << endl;
    }
    // pecahan: 
    // first -> atas
    // second -> bawah
    /*
    vector<pair<int, int>> v;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            v.push_back(make_pair(b + j, a + i));
        }
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        // urutan ke-x?
        cout << v[x - 1].first / __gcd(v[x - 1].first, v[x - 1].second) << "/" << v[x - 1].second / __gcd(v[x - 1].first, v[x - 1].second) << endl;
    }
    */
}