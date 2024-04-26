#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    // median -> elemen tengah
    int median = a[n / 2];
    long long sum = 0;
    for(auto x : a) {
        sum += abs(x - median);
        // abs(x) -> absolut, jadikan x positif
    }
    cout << sum << endl;
}