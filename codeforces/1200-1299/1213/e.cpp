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
string rev(string x) {
    reverse(x.begin(), x.end());
    return x;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s, t;
    cin >> n >> s >> t;
    // hypothesis -> always possible
    // transitions that are possible
    // both different char -> always possible
    // one different char, one same char
    // find transition
    // if both same char -> just abcabc...
    cout << "YES" << endl;
    if(s == rev(s) && t == rev(t)) {
        for(int i = 0; i < 3 * n; ++i) {
            if(i % 3 == 0)
                cout << 'a';
            else if(i % 3 == 1)
                cout << 'b';
            else
                cout << 'c';
        }
        cout << endl;
        return 0;
    }
    else if(s == rev(s) || t == rev(t)) {
        // the same char will alternate with another
        if(s == rev(s))
            swap(s, t);
        // t will be the same char
        if(s[0] == t[0] || s[1] == t[0]) {
            char c;
            for(int i = 0; i < 3; ++i)
                if('a' + i != s[0] && 'a' + i != s[1] && 'a' + i != t[0])  
                    c = 'a' + i;
            // alternate between c and same
            // put c last
            for(int i = 0; i < 2 * n; ++i) {
                if(i & 1)
                    cout << c;
                else
                    cout << t[0];
            }
            for(int i = 0; i < n; ++i) {
                if(s[0] == t[0] || s[0] == c)
                    cout << s[1];
                else
                    cout << s[0];
            }
            cout << endl;
        }
        else {
            for(int i = 0; i < 2 * n; ++i) {
                if(i & 1)
                    cout << t[0];
                else
                    cout << s[0];
            }
            for(int i = 0; i < n; ++i)
                cout << s[1];
            cout << endl;
        }
        return 0;
    }
    vector<string> a = {"a", "b", "c"};
    do {
        bool ans = 1;
        for(int i = 0; i < 2; ++i) {
            if(a[i] + a[i + 1] == s || a[i] + a[i + 1] == t) {
                ans = 0;
            }
        }
        if(ans) {
            for(int i = 0; i < 3; ++i)
                for(int j = 0; j < n; ++j)
                    cout << a[i];
            cout << endl;
            return 0;
        }
    } while(next_permutation(a.begin(), a.end()));
    return 0;
}