#include <bits/stdc++.h>
using namespace std;
int main() {
    long long res = 0;
    int k;
    cin >> k;
    // fi -> cost, se -> kapasitas
    pair<int, int> kandang[k];
    for(int i = 0; i < k; ++i)
        cin >> kandang[i].second;
    for(int i = 0; i < k; ++i)
        cin >> kandang[i].first;
    int n;
    cin >> n;
    int b[n];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    sort(kandang, kandang + k);
    sort(b, b + n);
    reverse(b, b + n);
    // idx -> index kandang paling kecil yg masih ada kapasitas
    int idx = 0;
    for(int i = 0; i < n; ++i) {
        res += 1ll * kandang[idx].first * b[i];
        kandang[idx].second--;
        if(kandang[idx].second == 0)
            ++idx;
    }
    cout << res << endl;
}