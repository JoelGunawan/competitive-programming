#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void tc() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // konstruksi prefix sum
    int pref[n + 1];
    pref[0] = 0;
    for(int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    int q;
    cin >> q;
    for(int pertanyaan = 0; pertanyaan < q; ++pertanyaan) {
        int l, u;
        cin >> l >> u;
        // cari pref[r] yg paling mendekati pref[l - 1] + u
        int cari = pref[l - 1] + u;
        // cari yg >= 
        int cl = l, cr = n, lebih_dari = -1;
        while(cl <= cr) {
            int m = (cl + cr) / 2;
            if(pref[m] < cari) {
                cl = m + 1;
            }
            else {
                cr = m - 1;
                lebih_dari = m;
            }
        }
        // cari yg <= 
        cl = l, cr = n;
        int kurang_dari = -1;
        while(cl <= cr) {
            int m = (cl + cr) / 2;
            if(pref[m] <= cari) {
                cl = m + 1;
                kurang_dari = m;
            }
            else {
                cr = m - 1;
            }
        }
        if(lebih_dari == -1) {
            cout << kurang_dari << " ";
        }
        else if(kurang_dari == -1) {
            cout << lebih_dari << " ";
        }
        else {
            // cek yg mendekati, jika sama maka pilih yg kurang dari
            if(abs(pref[kurang_dari] - cari) <= max(0, abs(pref[lebih_dari] - cari) - 1)) {
                cout << kurang_dari << " ";
            }
            else {
                cout << lebih_dari << " ";
            }
        }
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
        tc();
}