#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, p, q;
    cin >> n >> p >> q;
    int a[n + 1];
    vector<int> b;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], b.push_back(a[i]);
    sort(b.begin(), b.end());
    int ans[n];
    for(int i = 0; i < n; ++i) {
        // cari elemen b[i] ini ke belakang paling jauh bs berapa yang selisihnya maksimum p
        ans[i] = i - (lower_bound(b.begin(), b.end(), b[i] - p) - b.begin()) + 1;
    }
    // dia cari di kanan yang jaraknya maks segitu berapa
    // nanti pake set buat maintain
    // maintain sliding maximum :D pake multiset aja (technically bs pake deque trus mono stack algo tp mager)
    int r = n - 1;
    int fin[n];
    multiset<int> s;
    for(int i = n - 1; i >= 0; --i) {
        while(b[r] - b[i] > p)
            s.erase(s.find(ans[r])), --r;
        s.insert(ans[i]);
        fin[i] = *--s.end();
    }
    for(int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << fin[lower_bound(b.begin(), b.end(), a[x]) - b.begin()] << endl;
    }
}