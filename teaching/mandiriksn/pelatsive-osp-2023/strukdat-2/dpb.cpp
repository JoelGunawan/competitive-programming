#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, p, q;
    cin >> n >> p >> q;
    int asli[n + 1], a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> asli[i], a[i] = asli[i];
    sort(a + 1, a + n + 1);
    int mxsize[n + 1];
    int idx = 1;
    for(int i = 1; i <= n; ++i) {
        while(a[i] - a[idx] > p)
            ++idx;
        mxsize[i] = i - idx + 1;
    }
    int ans[n + 1];
    idx = 0;
    // 1 buat isi, 1 buat delete
    priority_queue<int> isi, del;
    for(int i = 1; i <= n; ++i) {
        while(idx < n && a[idx + 1] <= a[i] + p) {
            ++idx;
            isi.push(mxsize[idx]);
        }
        ans[i] = isi.top();
        // geser dr i ke i + 1 L nya
        // delete i aja
        // masalah -> hny bs delete top aja
        del.push(mxsize[i]);
        while(del.size() && del.top() == isi.top()) {
            del.pop();
            isi.pop();
        }
    }
    while(q--) {
        int x;
        cin >> x;
        int val = asli[x];
        int l_idx = lower_bound(a + 1, a + n + 1, val) - a;
        cout << ans[l_idx] << endl;
    }
}