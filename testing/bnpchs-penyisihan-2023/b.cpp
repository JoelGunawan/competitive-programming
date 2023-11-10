// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // kelipatan 3
    int n;
    string s;
    cin >> n >> s;
    int pos[3];
    bool used[3];
    memset(used, 0, sizeof(used));
    memset(pos, -1, sizeof(pos));
    bool ans = 1;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != '.') {
            if(pos[s[i] - 'a'] == -1) {
                //cout << s[i] - 'a' << " " << i << " " << used[i % 3] << endl;
                if(!used[i % 3])
                    pos[s[i] - 'a'] = i % 3, used[i % 3] = 1;
                else
                    ans = 0;
            }
            else if(pos[s[i] - 'a'] != i % 3)
                ans = 0;
        }
    }
    if(!ans)
        cout << -1 << endl, exit(0);
    for(int i = 0; i < s.size(); ++i) {
        if(!used[i % 3]) {
            for(int j = 0; j < 3; ++j) 
                if(pos[j] == -1 && !used[i % 3])
                    used[i % 3] = 1, pos[j] = i % 3;
        }
        for(int j = 0; j < 3; ++j)
            if(pos[j] == i % 3)
                s[i] = 'a' + j;
        //cout << s[i] << " ";
    }
    //cout << endl;
    cout << s << endl;
    return 0;
}