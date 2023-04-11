#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        string target = "Yes";
        bool ans = 1;
        if(s[0] == 'Y') {
            for(int i = 0; i < s.size(); ++i) {
                if(s[i] != target[i % 3])
                    ans = 0;
            }   
        }
        else if(s[0] == 'e') {
            for(int i = 0; i < s.size(); ++i) {
                if(s[i] != target[(i + 1) % 3])
                    ans = 0;
            }
        }
        else if(s[0] == 's') {
            for(int i = 0; i < s.size(); ++i) {
                if(s[i] != target[(i + 2) % 3])
                    ans = 0;
            }
        }
        else {
            ans = 0;
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}