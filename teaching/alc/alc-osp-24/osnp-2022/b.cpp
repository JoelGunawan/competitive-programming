#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin >> k;
    int p[k], c[k];
    for(int i = 0; i < k; ++i) {
        cin >> p[i];
    }
    for(int i = 0; i < k; ++i) {
        cin >> c[i];
    }
    // sorting berdasarkan harga
    // first -> harga
    // second -> kapasitas
    vector<pair<int, int>> a(k);
    for(int i = 0; i < k; ++i) {
        a[i] = make_pair(c[i], p[i]);
    }
    // biaya paling kecil di belakang
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int n;
    cin >> n;
    int b[n];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    sort(b, b + n);
    reverse(b, b + n);
    // untuk b paling besar di depan
    long long total = 0;
    for(int i = 0; i < n; ++i) {
        // pasangkan yg paling kecil biaya kandang
        if(a.back().second == 0)
            a.pop_back();
        total += (long long)b[i] * a.back().first;
        a.back().second--;
    }
    cout << total << endl;
}