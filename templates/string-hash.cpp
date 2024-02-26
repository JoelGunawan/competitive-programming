#include <bits/stdc++.h>
using namespace std;
struct string_hash {
    int lim, mod_sz, key;
    long long power[mod_sz][lim];
    vector<int> val[mod_sz];
    vector<int> mod;
    string str;
    void build(int Lim, int Mod_sz, int Key, vector<int> Mod) {
        lim = Lim, mod_sz = Mod_sz, key = Key, mod = Mod;
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