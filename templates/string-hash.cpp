#include <bits/stdc++.h>
using namespace std;
const int lim = 1e6 + 5,  mod_sz = 2, key = 998244353;
int mod[2] = {(int)1e9 + 7, (int)1e9 + 9};
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