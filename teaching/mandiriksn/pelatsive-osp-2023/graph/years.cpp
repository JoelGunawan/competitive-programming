#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    // fi -> value
    // se -> start/end segment
    // (bisa jadi ada banyak state lain)
    vector<pair<int, bool>> v;
    for(int i = 0; i < n; ++i) {
        v.push_back(make_pair(a[i].second, 0));
        v.push_back(make_pair(a[i].first, 1));
    }
    sort(v.begin(), v.end());
    // fi -> max org
    // se -> year
    pair<int, int> mx;
    int cnt = 0;
    for(auto i : v) {
        if(i.second) {
            // start segment
            ++cnt;
            // cek maksimal atau bukan
            mx = max(mx, make_pair(cnt, -i.first));
        }
        else {
            // end segment
            --cnt;
        }
    }
    cout << -mx.second << " " << mx.first << endl;
}