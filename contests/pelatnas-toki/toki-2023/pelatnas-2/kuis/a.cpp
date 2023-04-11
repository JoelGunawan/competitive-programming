// aku nyalain do not disturb :D
#include <bits/stdc++.h>
#define endl "\n"
#define ins insert
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // ideas:
    // use persistent ds (hampir pasti pakai)
    // masalah: gmn cara determine closest active sekarang
    // ide 1: pakai segment tree, karena stack tidak bisa
    // observasi: cari maximum closest that is active
    // transisi active ribet karena bisa transisi n / 2 element
    // 
    // coba pahami soal by sampah sub 1, 2
    // sub 1, find closest active manually, nanti ubah activenya jg manual
    int n, sub;
    cin >> n >> sub;
    int pr[n + 1], val[n + 1];
    bool active[n + 1];
    memset(active, 0, sizeof(active));
    memset(pr, -1, sizeof(pr));
    active[0] = 1, val[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> val[i];
        if(val[i] < 0) {
            // find 
            int tmp = i;
            active[tmp] ^= 1;
            for(int j = tmp - 1; j >= 1; --j) {
                if(active[j] && val[j] > val[tmp]) {
                    pr[tmp] = j;
                    tmp = j;
                    active[j] ^= 1;
                    break;
                }
            }
            // kalo dia beda state, 
            while(val[tmp] < 0) {
                //cout << "TST" << endl;
                tmp = pr[tmp];
                active[tmp] ^= 1;
            }
        }
        else
            active[i] = 1;
        //cout << "SEPARATOR" << endl;
        for(int j = i; j >= 0; --j) {
            if(active[j] && val[j] >= 0) {
                cout << val[j] << endl;
                break;
            }
        }
    }
}