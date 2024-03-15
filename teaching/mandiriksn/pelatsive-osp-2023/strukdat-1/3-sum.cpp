#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    pair<long long, int> a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i].first, a[i].second = i;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) {
        int j = i + 1, k = n;
        for(;j < k;) {
            // sesuaikan k supaya bisa membuat sum x
            for(;k > j + 1 && a[i].first + a[j].first + a[k].first > x;)
                --k;
            if(a[i].first + a[j].first + a[k].first == x) {
                // triplet yang memenuhi
                cout << a[i].second << " " << a[j].second << " " << a[k].second << endl;
                return 0;
            }
            ++j;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}