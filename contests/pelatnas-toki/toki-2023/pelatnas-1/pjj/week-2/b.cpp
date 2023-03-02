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
    string cur;
    getline(cin, cur);
    int t = stoi(cur);
    getline(cin, cur);
    for(int i = 0; i < t; ++i) {
        vector<int> nums;
        while(getline(cin, cur) && cur != "") {
            nums.pb(stoi(cur));
        }
        // find lis using set
        set<pair<int, int>> s;
        int pr[nums.size()];
        memset(pr, -1, sizeof(pr));
        for(int i = 0; i < nums.size(); ++i) {
            if(s.size() == 0 || s.ub(mp(nums[i], -1)) == s.end()) {
                if(s.size() && s.ub(mp(nums[i], -1)) != s.begin()) {
                    pr[i] = (*--s.ub(mp(nums[i], -1))).se;
                }
                s.ins(mp(nums[i], i));
            }
            else {
                if(s.ub(mp(nums[i], -1)) != s.begin()) {
                    pr[i] = (*--s.ub(mp(nums[i], -1))).se;
                }
                s.erase(s.ub(mp(nums[i], -1)));
                s.ins(mp(nums[i], i));
            }
        }
        /*
        for(auto i : s)
            cout << i.fi << " " << i.se << endl;
        for(int i = 0; i < nums.size(); ++i)
            cout << pr[i] << " ";
        cout << endl;
        */
        vector<int> output;
        int x = (*--s.end()).se;
        while(x != -1) {
            output.pb(x);
            x = pr[x];
        }
        cout << "Max hits: " << output.size() << endl;
        reverse(output.begin(), output.end());
        for(auto i : output)
            cout << nums[i] << endl;
        if(i != t - 1)
            cout << endl;
    }
    return 0;
}