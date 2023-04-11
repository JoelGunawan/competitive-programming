#include <bits/stdc++.h>
using namespace std;
int prefb[400005], prefw[400005];
vector<int> b, w;
int n;
long long memo[400005];
long long get_ans(int idx) {
    if(memo[idx] != -1)
        return memo[idx];
    idx += 4 * n;
    idx %= n;
    long long res = 0;
    for(int j = 0; j < n; ++j) {
        int l = b[j], r = w[(idx + j) % n];
        //cout << l << " " << r << endl;
        // cari antara l dan r
        // kalo misal r < l, maka + 2 * n
        if(r < l)
            swap(l, r);
        // pref[2 * n] - pref[r] + pref[l] buat seg 1
        // pref[r] - pref[l] buat seg 2
        int b1 = prefb[2 * n] - prefb[r] + prefb[l - 1], w1 = prefw[2 * n] - prefw[r] + prefw[l - 1];
        int b2 = prefb[r - 1] - prefb[l], w2 = prefw[r - 1] - prefw[l];
        //cout << b1 << " " << b2 << " " << w1 << " " << w2 << endl;
        res += min(b1, w2) + min(b2, w1);
    }
    //cout << idx << " " << res << endl;
    return memo[idx] = res;
}
int main() {
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < 2 * n; ++i) {
        if(s[i] == 'B')
            b.push_back(i + 1);
        else
            w.push_back(i + 1);
    }
    //cout << "TEST" << endl;
    for(int i = 1; i <= 2 * n; ++i) {
        prefb[i] = prefb[i - 1];
        prefw[i] = prefw[i - 1];
        if(binary_search(b.begin(), b.end(), i))
            prefb[i]++;
        else
            prefw[i]++;
    }
    //cout << "PREF BUILD DONE" << endl;
    //cout << b.size() << " " << w.size() << endl;
    // try circular ternary search
    // try shiftnya banyak
    // kalo 2 arah negatif -> binser pisah 2 arah
    // kalo 2 arah positif -> answer
    // pick arbitrary index then check whether it is 2 arah negatif, 2 arah positif, or 1 arah negatif 1 arah positif
    // 2 arah positif -> answer
    // 2 arah negatif -> ternary left and right segments
    // 1 arah negatif 1 arah positif -> pergi ke arah negatif sampe ketemu index pertama yang positif kanannya
    memset(memo, -1, sizeof(memo));
    // pick arbitrary index
    // cari first positive di kanan dan first positive di kiri
    // answer antara cur
    // coba get_ans n / 2, n / 2 - 1 dan n / 2 + 1
    // assume optimal placement cuma ada 1
    // find max antara 0...n - 1
    // find last index such that val[i] >= val[0] jika n - 1 ke 0 increasing
    // jika decreasing cari smallest index yg val[i] >= val[n - 1]
    // nanti dapet rangenya, bs di ternary
    int lb, rb;
    if(get_ans(0) >= get_ans(n - 1)) {
        // find last index where get_ans(i) >= get_ans(0)
        int l = 0, r = n - 1, idx;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(get_ans(mid) >= get_ans(0)) {
                l = mid + 1;
                idx = mid;
            }
            else {
                r = mid - 1;
            }
        }
        lb = 0, rb = idx;
    }
    else {
        // find smallest index where get_ans(i) >= get_ans(n - 1)
        int l = 0, r = n - 1, idx;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(get_ans(mid) >= get_ans(n - 1)) {
                r = mid - 1, idx = mid;
            }
            else {
                l = mid + 1;
            }
        }
        lb = idx, rb = n - 1;
    }
    while(lb < rb) {
        int m1 = lb + (rb - lb) / 3, m2 = lb + 2 * (rb - lb) / 3;
        if(m1 == m2)
            ++m2;
        if(get_ans(m1) >= get_ans(m2))
            rb = m2 - 1;
        else
            lb = m1 + 1;
    }
    //cout << lb << endl;
    cout << get_ans(lb) / 2 << endl;
}