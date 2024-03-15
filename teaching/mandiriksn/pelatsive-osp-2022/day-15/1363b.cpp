#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int zero_cnt = 0, one_cnt = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '0')
                ++zero_cnt;
            else
                ++one_cnt;
        }
        int pref[s.size() + 1];
        pref[0] = 0;
        for(int i = 1; i <= s.size(); ++i) {
            pref[i] = pref[i - 1] + (s[i - 1] == '1');
        }
        int res = min(zero_cnt, one_cnt);
        for(int i = 0; i < s.size() - 1; ++i) {
            // kiri ganti jadi 0, kanan ganti jadi 1
            res = min(res, pref[i + 1] + (((int)s.size() - i - 1) - (pref[s.size()] - pref[i + 1])));
            // kiri ganti jadi 1, kanan ganti jadi 0
            res = min(res, (i + 1) - pref[i + 1] + pref[s.size()] - pref[i + 1]);
        }
        cout << res << endl;
    }
}