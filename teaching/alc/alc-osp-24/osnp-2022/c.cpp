#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, p, q;
    cin >> n >> p >> q;
    // first -> nilai e
    // kedua -> menyimpan indeks asli
    pair<int, int> e[n];
    for(int i = 0; i < n; ++i) {
        cin >> e[i].first;
        e[i].second = i;
    }
    sort(e, e + n);
    int r = -1;
    multiset<int> s;
    vector<int> masuk[n], hapus[n];
    for(int i = 0; i < n; ++i) {
        while(r < n - 1 && e[r + 1].first - e[i].first <= p) {
            ++r;
        }
        masuk[i].push_back(r - i + 1);
        if(r + 1 < n)
            hapus[r + 1].push_back(r - i + 1);
    }
    int ans[n];
    for(int i = 0; i < n; ++i) {
        for(auto x : masuk[i]) {
            s.insert(x);
        }
        for(auto x : hapus[i]) {
            s.erase(s.find(x));
        }
        ans[e[i].second] = *--s.end();
    }
    for(int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << ans[x - 1] << endl;
    }
}