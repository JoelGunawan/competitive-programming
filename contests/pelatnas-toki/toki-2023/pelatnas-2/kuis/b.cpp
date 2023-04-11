#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main() {
    // do binser on prefix sum :D
    int n, x;
    cin >> n >> x;
    // sum harus at least x
    // berarti cari closest prefix sum so that 
    // semakin kanan semakin besar
    ll pref[n + 1];
    pref[0] = 0;
    for(int i = 1; i <= n; ++i) {
        int y;
        cin >> y;
        pref[i] = pref[i - 1] + y;
    }
    vector<int> st = {0};
    int ans = 1e9;
    for(int i = 1; i <= n; ++i) {
        // binser paling kanan yang memenuhi
        int l = 0, r = st.size() - 1, res = 1e9;
        while(l <= r) {
            int mb = (l + r) / 2;
            if(pref[i] - pref[st[mb]] >= x) {
                //cout << pref[i] << " " << pref[st[mb]] << " " << i << " " << st[mb] << endl;
                res = (i - st[mb]);
                l = mb + 1;
            }
            else
                r = mb - 1;
        }
        ans = min(ans, res);
        while(st.size() && pref[st.back()] >= pref[i])
            st.pop_back();
        st.pb(i);
    }
    if(ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
}