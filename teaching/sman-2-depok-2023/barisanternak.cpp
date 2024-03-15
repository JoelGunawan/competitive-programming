#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int l[n + 1], r[n + 1];
    l[0] = r[0] = 0;
    for(int i = 1; i <= n; ++i)
        l[i] = r[i - 1] + 1, r[i] = r[i - 1] + a[i];
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        // cari ternak ke-x ke mana?
        int cl = 1, cr = n, ans;    
        while(cl <= cr) {
            int mid = (cl + cr) / 2;
            // mid ini tempatnya ternak ke-x
            // diantara L dan R
            if(x <= r[mid] && x >= l[mid]) {
                ans = mid;
                break;
            }
            // tempat ternak ke-x di kiri mid
            else if(x < l[mid]) {
                cr = mid - 1;
            }
            else {
                cl = mid + 1;
            }
        }
        cout << ans << endl;
    }
}