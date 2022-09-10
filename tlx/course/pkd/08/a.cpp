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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    deque<int> a;
    while(n--) {
        string o;
        cin >> o;
        if(o == "push_front") {
            int x;
            cin >> x;
            a.push_front(x);
        }
        else if(o == "push_back") {
            int x;
            cin >> x;
            a.push_back(x);
        }
        else if(o == "pop_back")
            a.pop_back();
        else
            a.pop_front();
    }
    for(auto i : a)
        cout << i << endl;
    return 0;
}