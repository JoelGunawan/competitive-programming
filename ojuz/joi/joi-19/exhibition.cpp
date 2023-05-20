#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair<int, int> a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);
    int b[m + 1];
    for(int i = 1; i <= m; ++i)
        cin >> b[i];
    sort(b + 1, b + m + 1);
    // coba minimum value yg bs masuk ke frame
    int l = 0, r = m, res = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        int idx = 1;
        multiset<int> s;
        int pr = 0;
        bool ans = 1;
        //cout << "MID " << mid << endl;
        for(int i = m - mid + 1; i <= m; ++i) {
            while(idx <= n && a[idx].first <= b[i]) {
                s.insert(a[idx].second);
                //cout << "DEBUG " << i << " " << a[idx].second << endl;
                ++idx;
            }
            // ambil 1
            //cout << pr << endl;
            if(s.lower_bound(pr) == s.end()) {
                ans = 0;
                break;
            }
            else {
                pr = *s.lower_bound(pr);
                s.erase(s.lower_bound(pr));
            }
        }
        if(ans)
            l = mid + 1, res = mid;
        else
            r = mid - 1;
    }
    cout << res << endl;
    return 0;
}