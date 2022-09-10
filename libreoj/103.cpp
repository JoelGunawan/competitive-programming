// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const int lim = 1e6 + 5;
int mod[2] = {(int)1e9 + 7, (int)1e9 + 9};
const int mod_sz = 2;
const int key = 42069;
long long power[mod_sz][lim];
struct string_hash {
    vector<int> val[mod_sz];
    string str;
    void build() {
        long long tmp[mod_sz];
        memset(tmp, 0, sizeof(tmp));
        for(int i = 0; i < str.size(); ++i) {
            for(int j = 0; j < mod_sz; ++j) {
                tmp[j] = tmp[j] * key + str[i];
                tmp[j] %= mod[j];
                val[j].push_back(tmp[j]);
            }
        }
    }
    vector<int> q(int l, int r) {
        vector<int> ret;
        if(l == 0) {
            for(int i = 0; i < mod_sz; ++i)
                ret.push_back(val[i][r]);
        }
        else {
            for(int i = 0; i < mod_sz; ++i) {
                ret.push_back(val[i][r] - ((1ll * val[i][l - 1] * power[i][r - l + 1]) % mod[i]));
                if(ret.back() < 0)
                    ret.back() += mod[i];
            }
        }
        return ret;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string_hash s, t;
    string a, b;
    cin >> a >> b;
    s.str = a, t.str = b;
    for(int i = 0; i < lim; ++i) {
        for(int j = 0; j < mod_sz; ++j) {
            if(i == 0)
                power[j][i] = 1;
            else
                power[j][i] = (1ll * power[j][i - 1] * key) % mod[j];
        }
    }
    s.build();
    t.build();
    vector<int> target = t.q(0, b.size() - 1);
    int res = 0;
    for(int i = 0; i <= (ll)a.size() - (ll)b.size(); ++i) {
        vector<int> tmp = s.q(i, i + b.size() - 1);
        if(s.q(i, i + b.size() - 1) == target)
            ++res;
    }
    cout << res << endl;
    return 0;
}