#include <bits/stdc++.h>
using namespace std;
bool perbandingan(pair<string, int> a, pair<string, int> b) {
    for(int i = 0; i < a.first.size(); ++i) {
        if(a.first[i] == b.first[i]) {
            // cek yang selanjutnya
        }
        else {
            // diurutkan menaik (di indeks ganjil)
            if(i % 2 == 0) {
                // bandingkan normal
                return a.first[i] < b.first[i];
            }
            // diurutkan menurun (di indeks genap)
            else {
                // bandingkan kebalik
                return a.first[i] > b.first[i];
            }
        }
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;
    pair<string, int> a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n, perbandingan);
    for(int i = 0; i < n; ++i)
        cout << a[i].second << " ";
    cout << endl;
}