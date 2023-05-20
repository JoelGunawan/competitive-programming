#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int cons = 22;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    // di tiap level ada 2 choices
    // terserah atau harus 0
    // determine yes/no pake sum of submask
    // jadi nanti nlog
    // find sum of submask
    // tiap sum of submask memo ada element apa yg bs
    // indicate salah satu elemen yg ada di submask
    // bs ambil dr child mask, just pick one aja
    // buat checking bs pake cara yg sama atau bs pake sos (klo gabut)
    // skalian latihan sos
    // 2^cons
    int a[1 << cons];
    memset(a, -1, sizeof(a));
    for(int i = 1; i <= n; ++i) {
        a[b[i]] = b[i];
    }
    for(int i = 1; i < (1 << cons); ++i) {
        // coba submasknya
        if(a[i] != -1)
            continue;
        else {
            for(int j = 0; j < cons; ++j) {
                if((1 << j) & i) {
                    a[i] = a[(1 << j) ^ i];
                }
                if(a[i] != -1) 
                    break;
            }
        }
    }
    int ans[n + 1];
    for(int i = 1; i <= n; ++i) {
        // find inverse mask
        int inv = ((1 << cons) - 1) ^ b[i];
        ans[i] = a[inv];
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
}