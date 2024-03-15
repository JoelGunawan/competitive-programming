#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    pair<long long, long long> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    long long res = 0;
    for(int i = 0; i < n; ++i)
        res += a[i].first * a[(i + 1) % n].second - a[(i + 1) % n].first * a[i].second;
    // abs -> tanda mutlak di C++
    res = abs(res);
    cout << res << endl;
}