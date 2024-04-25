#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    // first, second
    // first -> nilai
    // second -> posisi
    set<pair<int, int>> s;
    // 2 7 5 1
    // s = {make_pair(1, 4), make_pair(2, 1), make_pair(5, 3), make_pair(7, 2)}
    bool ans = 0;
    for(int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        // a + ... = x
        // ... = x - a
        // apakah ada elemen di set yg nilainya x - a?
        auto it = s.lower_bound(make_pair(x - a, 0));
        if(it != s.end() && (*it).first == x - a) {
            // udah ketemu nilainya
            int pos = (*it).second;
            ans = true;
            cout << i << " " << pos << endl;
            break;
        }
        s.insert(make_pair(a, i));
    }
    if(!ans) {
        cout << "IMPOSSIBLE" << endl;
    }
}