#include "molecules.h"
#include <bits/stdc++.h>
using namespace std;

std::vector<int> find_subset(int l, int u, std::vector<int> w) {
    // between l and u
    vector<int> v = w;
    // pilih sum terkecil, terus nanti
    sort(w.begin(), w.end());
    // cari w sesuai buat antara u l
    // cari first bigger than u, berarti countnya itu satu kurang dr
    long long sum = 0;
    int cnt = w.size();
    for(int i = 0; i < w.size(); ++i) {
        sum += w[i];
        if(sum > u) {
            cnt = i;
            break;
        }
    }
    if(cnt == 0)
        return vector<int>(0);
    multiset<int> s;
    sum = 0;
    for(int i = 0; i < cnt; ++i) {
        sum += w[i];
        s.insert(w[i]);
    }
    for(int i = cnt; i < w.size(); ++i) {
        // try to 
        if(sum >= l)
            break;
        if(sum < l) {
            // coba increase to smallest above l
            s.insert(w[i]);
            sum += w[i];
            sum -= *s.begin();
            s.erase(s.begin());
        }
    }
    //cout << sum << endl;
    if(sum >= l && sum <= u) {
        vector<int> ans;
        for(int i = 0; i < w.size(); ++i) {
            if(s.find(v[i]) != s.end()) {
                ans.push_back(i);
                s.erase(s.find(v[i]));
            }
        }
        return ans;
    }
    else {
        return vector<int>(0);
    }
}
