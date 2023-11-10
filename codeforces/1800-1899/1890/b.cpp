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
void tc() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    bool one = 0, zero = 0;
    for(int i = 1; i < s.size(); ++i) {
        if(s[i] == s[i - 1] && s[i] == '1')
            one = 1;
        if(s[i] == s[i - 1] && s[i] == '0')
            zero = 1;
    }
    //cout << zero << " " << one << endl;
    if(zero && one) {
        cout << "No" << endl;
    }
    else if(zero) {
        // t has to be form 1010101
        bool validt = 1;
        for(int i = 1; i < t.size(); ++i) {
            if(t[i] == t[i - 1])
                validt = 0;
        }
        if(validt && t[0] == '1' & t[t.size() - 1] == '1')
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else if(one) {
        // t has to be form 0101010
        bool validt = 1;
        for(int i = 1; i < t.size(); ++i) {
            if(t[i] == t[i - 1])
                validt = 0;
        }
        //cout << validt << " " << t[0] << " " << t[t.size() - 1] << endl;
        if(validt && t[0] == '0' & t[t.size() - 1] == '0')
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
        cout << "Yes" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}