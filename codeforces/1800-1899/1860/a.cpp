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
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        // if ((())) -> ()()()()
        // if ()()() -> (((())))
        int n = s.size();
        string a = "", b = "";
        if(s == "()") {
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < n; ++i) {
            a += '(';
        }
        for(int i = 0; i < n; ++i) {
            a += ')';
        }
        for(int i = 0; i < n; ++i) {
            b += '(';
            b += ')';
        }
        bool use_fi = 1;
        for(int i = 0; i + n <= a.size(); ++i) {
            if(a.substr(i, n) == s)
                use_fi = 0;
        }
        cout << "YES" << endl;
        if(use_fi) {
            cout << a << endl;
        }
        else
            cout << b << endl;
    }
    return 0;
}