#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
long long sqr(int a) {
    return 1ll * a * a;
}
int main() {
    int n;
    cin >> n;
    int a[n + 1], pref[n + 1];
    pref[0] = 0;
    long long closest = 2e18;
    for(int i = 1; i <= n; ++i) 
        cin >> a[i], pref[i] = pref[i - 1] + a[i];
    // (i - j)^2 + (pref[i] - pref[j])^2
    // i^2 + j^2 - 2ij + pref[i]^2 + pref[j]^2 - 2pref[i]pref[j]
    // n 1e5
    // a[i] 1e4
    // find closest pair
    // 2 algo dnc and greedy 6 point thing algo
    // dnc algo: find the left most and the right most
    // with only 3 options on the right
    // greedy sorting algo maintain set vertical increasing on the left
    // find distance to each pair
    // if distance is more than minimum than just discard it :D
    set<pair<int, int>> s;
    for(int i = 1; i <= n; ++i) {
        // iterate s
        auto it = s.lower_bound({pref[i] - (int)sqrt(closest) - 1, 0});
        while(it != s.end()) {
            pair<int, int> tmp = *it;
            if(sqr(i - tmp.second) >= closest) {
                ++it;
                //cout << closest << " " << i << " " << tmp.second << endl;
                s.erase(tmp);
            }
            else if(sqr(pref[i] - tmp.first) >= closest) {
                break;
            }
            else {
                //cout << i << " " << tmp.second << " " << pref[i] << " " << tmp.first << endl;
                closest = min(closest, sqr(i - tmp.second) + sqr(pref[i] - tmp.first));
                ++it;
            }
        }
        s.insert({pref[i], i});
    }
    cout << closest << endl;
}