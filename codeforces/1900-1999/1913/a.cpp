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
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if(s[0] == '0') {
            cout << -1 << endl;
            continue;
        }
        int idx = -1;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] != '0') {
                idx = i;
                break;
            }
        }
        if(idx == -1 || idx > s.size() / 2) {
            cout << -1 << endl;
            continue;
        }
        int a = stoi(s.substr(0, idx));
        int b = stoi(s.substr(idx, s.size() - idx));
        if(a < b) {
            cout << a << " " << b << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}