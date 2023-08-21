#include <bits/stdc++.h>
#define endl "\n"
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    int t[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> t[i];
    }
    // find prefix lis/suffix lis, nanti cari yg max di mana
    // suffix lis -> lds dr belakang
    // prefix lis -> lis dr depan
    int pref[n + 1], suff[n + 1];
    vector<int> lis, lds;
    for(int i = 1; i <= n; ++i) {
        if(lower_bound(lis.begin(), lis.end(), t[i]) != lis.end()) {
            lis[lower_bound(lis.begin(), lis.end(), t[i]) - lis.begin()] = t[i];
        }
        else {
            lis.push_back(t[i]);
        }
        pref[i] = lb(lis.begin(), lis.end(), t[i]) - lis.begin() + 1;
    }
    for(int i = n; i >= 1; --i) {
        if(lower_bound(lds.begin(), lds.end(), -t[i]) != lds.end()) {
            lds[lb(lds.begin(), lds.end(), -t[i]) - lds.begin()] = -t[i];
        }
        else
            lds.push_back(-t[i]);
        suff[i] = lb(lds.begin(), lds.end(), -t[i]) - lds.begin() + 1;
    }
    // fi -> t
    // se -> lis
    set<pair<int, int>> s;
    int ret = pref[n];
    for(int i = n; i >= 1; --i) {
        if(s.lb(mp(t[i] - x + 1, 0)) != s.end()) {
            //cout << pref[i] << " " << (*s.lb(mp(t[i] - x + 1, 0))).se << endl;
            //cout << "DEB " << i << " " << t[i] << " " << (*s.lb(mp(t[i] - x + 1, 0))).fi << " " << (*s.lb(mp(t[i] - x + 1, 0))).se << endl;
            ret = max(ret, (*s.lb(mp(t[i] - x + 1, 0))).se + pref[i]);
        }
        while(s.lb(mp(t[i], 1e9)) != s.begin()) {
            pair<int, int> pr = *--s.lb(mp(t[i], 1e9));
            if(pr.se <= suff[i])
                s.erase(s.find(pr));
            else   
                break;
        }
        if(s.lb(mp(t[i], 0)) != s.end() && (*s.lb(mp(t[i], 0))).se >= suff[i]) {
            
        }
        else
            s.insert(mp(t[i], suff[i]));
    }
    cout << ret << endl;
}