#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        int t_idx = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(t_idx < t.size() && s[i] == t[t_idx])
                ++t_idx;
        }
        if(t_idx == t.size())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}