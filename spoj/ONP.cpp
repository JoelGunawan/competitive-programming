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
void tc() {
    string s;
    cin >> s;
    stack<char> ops;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '(') {

        }
        else if(s[i] == ')') {
            cout << ops.top();
            ops.pop();
        }
        else if(s[i] >= 'a' && s[i] <= 'z')
            cout << s[i];
        else
            ops.push(s[i]);
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}