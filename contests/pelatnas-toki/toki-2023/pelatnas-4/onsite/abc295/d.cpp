#include <bits/stdc++.h>
using namespace std;
int main() {
    // jumlah tiap karakter even/parity sama
    string s;
    cin >> s;
    // same parity, ada 10 data point
    // berarti simpan sebagai bitmask
    // maks 2^10
    int cnt[1 << 10];
    memset(cnt, 0, sizeof(cnt));
    ++cnt[0];
    bool par[10];
    memset(par, 0, sizeof(par));
    long long res = 0;
    for(int i = 0; i < s.size(); ++i) {
        par[s[i] - '0'] ^= 1;
        int cur = 0;
        for(int j = 0; j < 10; ++j) {
            cur += par[j] << j;
        }
        res += cnt[cur];
        ++cnt[cur];
    }
    cout << res << endl;
}