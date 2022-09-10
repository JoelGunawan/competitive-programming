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
    string s;
    cin >> s;
    int a[s.size()];
    for(int i = 0; i < s.size(); ++i)
        a[i] = s[i] - '0';
    int n = s.size();
    // case tidak bisa -> sum == 4, only 2; sum < 3
    // jika ada 0 -> selalu bisa
    int cnt[3];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i)
        ++cnt[a[i] % 3];
    if(!cnt[0] && (cnt[1] + 2 * cnt[2] < 3 || (!cnt[1] && cnt[2] * 2 < 6))) {
        cout << -1 << endl;
        return 0;
    }
    else {
        int total = cnt[1] + 2 * cnt[2]; total %= 3;
        if(total == 1) {
            // delete 1 cnt[1] or 2 cnt[2]
            int last_one = -1;
            for(int i = n - 1; i >= 0; --i) {
                if(a[i] % 3 == 1) {
                    last_one = i;
                    break;
                }
            }
            if(cnt[1] && (last_one != 0 || s[1] != '0' || !cnt[2])) {
                for(int i = n - 1; i >= 0; --i) {
                    if(a[i] % 3 == 1) {
                        s.erase(i, 1);
                        break;
                    }
                }
            }
            else {
                for(int tmp = 0; tmp < 2; ++tmp) {
                    for(int i = s.size() - 1; i >= 0; --i) {
                        if((s[i] - '0') % 3 == 2) {
                            s.erase(i, 1);
                            break;
                        }
                    }
                }
            }
        }
        else if(total == 2) {
            // delete 1 cnt[2] or 2 cnt[1]
            int last_two = -1;
            for(int i = n - 1; i >= 0; --i) {
                if(a[i] % 3 == 2) {
                    last_two = i;
                    break;
                }
            }
            if(cnt[2] && (last_two != 0 || s[1] != '0' || !cnt[1])) {
                for(int i = s.size() - 1; i >= 0; --i) {
                    if(a[i] % 3 == 2) {
                        s.erase(i, 1);
                        break;
                    }
                }
            }
            else {
                for(int tmp = 0; tmp < 2; ++tmp) {
                    for(int i = s.size() - 1; i >= 0; --i) {
                        if((s[i] - '0') % 3 == 1) {
                            s.erase(i, 1);
                            break;
                        }
                    }
                }
            }
        }
    }
    bool lead = 1;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '0' && lead && i != s.size() - 1)
            continue;
        else
            lead = 0, cout << s[i];
    }
    cout << endl;
    return 0;
}