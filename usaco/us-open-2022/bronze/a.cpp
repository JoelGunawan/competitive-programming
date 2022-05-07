// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // maintain out of position count
    // only reverse even length
    int n;
    cin >> n;
    string s;
    cin >> s;
    int vals[n / 2];
    for(int i = 0; i < n / 2; ++i) {
        // good
        if(s[2 * i] == 'G' && s[2 * i + 1] == 'H') {
            vals[i] = 1;
        }
        // normal
        else if(s[2 * i] == s[2 * i + 1]) {
            vals[i] = 0;
        }
        // bad
        else {
            vals[i] = -1;
        }
        // tinggal cek tiap pair, ideal untuk dibalik bukan
        // check longest segments with non bad
        // but for each segment, it has to have a pair that increases
    }
    // iterate through vals and check sequences of vals
    bool has_one = 0;
    int start = 0;
    vector<int> r;
    for(int i = 0; i < n / 2; ++i) {
        //cout << vals[i] << " ";
        if(vals[i] == 1) {
            has_one = 1;
        }
        else if(vals[i] == 0) {
            continue;
        }
        else {
            if(has_one)
                r.push_back(start);
            has_one = 0;
            start = i + 1;
        }
    }
    if(has_one)
        r.pb(start);
    int res = 0;
    for(auto i : r) {
        if(i == 0)
            ++res;
        else
            res += 2;
    }
    cout << res << endl;
    return 0;
}