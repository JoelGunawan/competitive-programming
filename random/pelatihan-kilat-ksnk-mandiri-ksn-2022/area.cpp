#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    // {first, second}
    // pair<long long, long long> x
    // x.first x.second
    // x = make_pair(first, second);
    pair<long long, long long> a[n];
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
    }
    long long result = 0;
    for(int i = 0; i < n; i++) {
        result = result + (a[i].first * a[(i + 1) % n].second - a[i].second * a[(i + 1) % n].first);
    }
    result = abs(result);
    cout << result << endl;
    return 0;
}