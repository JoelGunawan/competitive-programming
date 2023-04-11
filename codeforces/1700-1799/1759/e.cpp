#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, h;
        cin >> n >> h;
        int a[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        vector<int> b = {2, 2, 3};
        sort(a + 1, a + n + 1);
        int res = 0;
        do {
            long long cursum = h;
            int idx = 0;
            int ans = n;
            for(int i = 1; i <= n; ++i) {
                while(cursum <= a[i] && idx < 3) {
                    cursum *= b[idx++];
                }
                if(cursum > a[i]) {
                    cursum += a[i] / 2;
                }
                else {
                    ans = i - 1;
                    break;
                }
            }
            res = max(res, ans);
        } while(next_permutation(b.begin(), b.end()));
        cout << res << endl;
    }
}