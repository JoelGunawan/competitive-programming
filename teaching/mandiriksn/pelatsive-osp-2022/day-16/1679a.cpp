#include <bits/stdc++.h>
using namespace std;
void tc() {
    long long n;
    cin >> n;
    if(n % 2 == 1 || n < 4)
        cout << -1 << endl;
    else {
        // -1 -> hasil akhir setelah dikurangi antara 12-24
        long long minans = (n / 12 - 1) * 2, maxans = (n / 12 - 1) * 3;
        int mini[25], maxi[25];
        fill(mini, mini + 25, 1e9);
        fill(maxi, maxi + 25, 0);
        mini[0] = 0;
        for(int i = 0; i <= 24; ++i) {
            if(i >= 4) {
                mini[i] = min(mini[i], mini[i - 4] + 1);
                maxi[i] = max(maxi[i], maxi[i - 4] + 1);
            }
            if(i >= 6) {
                mini[i] = min(mini[i], mini[i - 6] + 1);
                maxi[i] = max(maxi[i], maxi[i - 6] + 1);
            }
        }
        if(n <= 24)
            cout << mini[n] << " " << maxi[n] << endl;
        else
            cout << minans + mini[n % 12 + 12] << " " << maxans + maxi[n % 12 + 12] << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--)
        tc();
}