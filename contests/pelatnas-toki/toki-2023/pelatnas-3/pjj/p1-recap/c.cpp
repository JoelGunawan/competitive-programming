#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> l, r;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(i < n / 2) {
            l.push_back(x % m);
        }
        else
            r.push_back(x % m);
    }
    vector<int> lsum = {0}, rsum = {0};
    for(int i = 0; i < (1 << l.size()); ++i) {
        long long sum = 0;
        for(int j = 0; j < l.size(); ++j) {
            if((1 << j) & i)
                sum += l[j];
        }
        lsum.push_back(sum % m);
    }
    sort(lsum.begin(), lsum.end());
    for(int i = 0; i < (1 << r.size()); ++i) {
        long long sum = 0;
        for(int j = 0; j < r.size(); ++j) {
            if((1 << j) & i)
                sum += r[j];
        }
        rsum.push_back(sum % m);
    }
    sort(rsum.begin(), rsum.end());
    int res = 0;
    for(int i = 0; i < lsum.size(); ++i) {
        if(m - lsum[i] != 0)
            res = max(res, lsum[i] + *--lower_bound(rsum.begin(), rsum.end(), m - lsum[i]));
        res = max(lsum[i], res);
    }
    for(auto i : rsum)
        res = max(res, i);
    cout << res << endl;
}