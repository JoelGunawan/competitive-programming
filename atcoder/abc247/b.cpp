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
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    scanf("%d", &n);
    string s[n], t[n];
    for(int i = 0; i < n; ++i)
        cin >> s[i] >> t[i];
    bool ans = 1;
    for(int i = 0; i < n; ++i) {
        bool t_ans = 1, s_ans = 1;
        for(int j = 0; j < n; ++j) {
            if(j != i) {
                if(t[j] == t[i] || s[j] == t[i])
                    t_ans = 0;
                if(t[j] == s[i] || s[j] == s[i])
                    s_ans = 0;
            }
        }
        ans &= (t_ans | s_ans);
    }
    if(ans)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}