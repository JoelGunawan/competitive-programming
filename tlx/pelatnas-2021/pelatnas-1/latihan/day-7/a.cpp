#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define lll __int128
using namespace std;
string s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    char res[s.size()];
    bool ans = 0;
    string x;
    if(s.size() % 2 == 1)
        cout << -1 << endl, exit(0);
    for(int mask = 0; mask < 1 << s.size(); ++mask) {
        int cnt = 0;
        for(int j = 0; j < s.size(); ++j)
            if((1 << j) & mask)
                ++cnt, res[j] = '(';
            else
                res[j] = ')';
        // check sequence
        // if valid break
        bool val = 1;
        for(int i = 0; i < s.size(); ++i)
            for(int j = i + 1; j < s.size(); ++j)
                if(res[i] == '(' && res[j] == ')' && s[i] == s[j]) {
                    // check the mid whether it is a valid seq
                    bool cor = 1;
                    int cnt1 = 0, cnt2 = 0;
                    for(int k = i + 1; k < j; ++k) {
                        if(res[k] == '(')
                            ++cnt1;
                        else
                            ++cnt2;
                        if(cnt1 < cnt2)
                            cor = 0;
                    }
                    if(cnt1 != cnt2)
                        cor = 0;
                    if(!cor)
                        val = 0;
                }
                else if(res[i] == '(' && res[j] == ')' && s[i] != s[j]) {
                    if(i == j - 1)
                        val = 0;
                    bool cor = 1;
                    int cnt1 = 0, cnt2 = 0;
                    for(int k = i + 1; k < j; ++k) {
                        if(res[k] == '(')
                            ++cnt1;
                        else
                            ++cnt2;
                        if(cnt1 < cnt2)
                            cor = 0;
                    }
                    if(cnt1 != cnt2)
                        cor = 0;
                    if(cor)
                        val = 0;
                }
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(res[i] == '(')
                ++cnt1;
            else
                ++cnt2;
            if(cnt1 < cnt2)
                val = 0;
        }
        if(cnt1 != cnt2)
            val = 0;
        if(val) {
            string tmp = "";
            for(int i = 0; i < s.size(); ++i)
                tmp += res[i];
            if(x.size() == 0 || tmp < x)
                x = tmp;
            ans = 1;
        }
    }
    if(ans)
        cout << x;
    else
        cout << -1;
    cout << endl;
    return 0;
}