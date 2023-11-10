#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); ++i) {
        for(int j = i; j < s.size(); ++j) {
            string cur = "";
            for(int k = i; k <= j; ++k)
                cur += s[k];
            string r = cur;
            reverse(r.begin(), r.end());
            if(cur == r)
                ++cnt;
        }
    }
    cout << cnt << endl;
}