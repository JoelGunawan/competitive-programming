// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
ll sum(int l, int r) {
    return 1ll * (l - 1) * (r - l + 1) + 1ll * (r - l + 1) * (r - l + 2) / 2;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        int pref[n + 1];
        memset(pref, 0, sizeof(pref));
        for(int i = 1; i <= n; ++i)
            pref[i] = pref[i - 1] + a[i];
        int q;
        cin >> q;
        while(q--) {
            int l, u;
            cin >> l >> u;
            int cl = l, cr = n, ans1 = -1, ans2 = -1;
            while(cl <= cr) {
                int mid = (cl + cr) / 2;
                if(pref[mid] - pref[l - 1] >= u) {
                    ans1 = mid;
                    cr = mid - 1;
                }
                else
                    cl = mid + 1;
            }
            cl = l, cr = n;
            while(cl <= cr) {
                int mid = (cl + cr) / 2;
                if(pref[mid] - pref[l - 1] <= u) {
                    ans2 = mid;
                    cl = mid + 1;
                }
                else
                    cr = mid - 1;
            }
            if(ans1 == -1)
                cout << ans2 << " ";
            else if(ans2 == -1)
                cout << ans1 << " ";
            else {
                ll res1 = sum(u - (pref[ans1] - pref[l - 1]) + 1, u), res2 = sum(u - (pref[ans2] - pref[l - 1]) + 1, u);
                if(res1 == res2)
                    cout << min(ans1, ans2) << " ";
                else if(res1 < res2)
                    cout << ans2 << " ";
                else
                    cout << ans1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}