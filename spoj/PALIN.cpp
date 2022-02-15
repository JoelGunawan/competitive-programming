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
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        string t;
        t = s;
        sort(t.begin(), t.end());
        if(t[0] == '9' && t[t.size() - 1] == '9') {
            // extend the count
            cout << '1';
            for(int i = 0; i < t.size() - 1; ++i)
                cout << '0';
            cout << '1';
            cout << endl;
        }
        else {
            int carry = 1, idx = s.size() - 1;
            while(carry > 0) {
                if(s[idx] == '9')
                    s[idx] = '0', carry = 1;
                else
                    ++s[idx], carry = 0;
                --idx;
            }
            // find closest bigger than or equal to palindrome
            
        }
    }
    return 0;
}