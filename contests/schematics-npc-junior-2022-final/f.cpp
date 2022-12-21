#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cross(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
    a.first -= c.first;
    b.first -= c.first;
    a.second -= c.second;
    b.second -= c.second;
    return a.first * b.second - a.second * b.first;
}
int main() {
    // convex hull
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    vector<pair<int, int>> ch;
    ch.push_back({a[0], a[1]});
    for(int i = 2; i < n; ++i) {
        while(ch.size() > 1 && cross(ch.back(), a[i], ch[ch.size() - 2]) > 0)
            ch.pop_back();
        ch.push_back(a[i]);
    }
    vector<pair<int, int>> ch2;
    ch2.push_back({a[n - 1], a[n - 2]});
    for(int i = n - 3; i >= 0; --i) {
        while(ch2.size() > 1 && cross(ch2.back(), a[i], ch2[ch2.size() - 2]) > 0)
            ch2.pop_back();
        ch2.push_back(a[i]);
    }
    for(int i = 1; i < ch2.size() - 1; ++i)
        ch.push_back(ch2[i]);
    ll res = 0;
    for(int i = 0; i < ch.size(); ++i) {
        res += ch[i].first * ch[(i + 1) % ch.size()].second - ch[i].second * ch[(i + 1) % ch.size()].first;
    }
    res = abs(res);
    int m;
    cin >> m;
    pair<int
}