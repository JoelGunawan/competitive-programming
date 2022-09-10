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
int to_dec(string tmp) {
    int x = 1, ret = 0;
    for(int i = tmp.size() - 1; i >= 0; --i) {
        ret += (tmp[i] - '0') * x;
        x *= 3;
    }   
    return ret;
}
int lim = 1e5;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    string a[t];
    for(int i = 0; i < t; ++i)
        cin >> a[i];
    ll res = 0;
    for(int i = 0; i < t; ++i) {
        string tmp = a[i];
        bool fi = 0;
        if(tmp[0] == '2')
            fi = 1;
        int get_sum = 0;
        for(int j = 0; j < 11; ++j)
            get_sum += tmp[j] - '0';
        bool valid = 1;
        if(i % 3 == 0) {
            if(fi) {
                get_sum -= 2;
                if(get_sum % 3 == 0)
                    tmp[0] = '0';
                else if(get_sum % 3 == 2)
                    tmp[0] = '1';
                else
                    valid = 0;
            }
            else if(get_sum % 3 == 0)
                valid = 0;
            int tmp2 = to_dec(tmp);
            if(valid && tmp2 < lim)
                res += tmp2;
        }
        else if(i % 3 == 1) {
            if(fi) {
                get_sum -= 2;
                if(get_sum % 3 == 1)
                    tmp[0] = '0';
                else if(get_sum % 3 == 0)
                    tmp[0] = '1';
                else
                    valid = 0;
            }
            else if(get_sum % 3 == 1)
                valid = 0;
            int tmp2 = to_dec(tmp);
            if(valid && tmp2 < lim)
                res += tmp2;
        }
        else {
            if(fi) {
                get_sum -= 2;
                if(get_sum % 3 == 2)
                    tmp[0] = '0';
                else if(get_sum % 3 == 1)
                    tmp[0] = '1';
            }
            else if(get_sum % 3 == 2)
                valid = 0;
            int tmp2 = to_dec(tmp);
            if(valid && tmp2 < lim)
                res += tmp2;
        }
    }
    cout << res << endl;
    return 0;
}