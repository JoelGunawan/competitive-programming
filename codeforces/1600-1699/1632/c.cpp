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
    int a, b;
    cin >> a >> b;
    int res = b - a;
    for(int i = b; i <= 4 * b; ++i) {
        // find first wrong bit in a
        int wrong_bit = -1, latest = -1, cur_sum = 0;
        for(int j = 30; j >= 0; --j) {
            if((1 << j) & a) {
                if(!((1 << j) & i)) {
                    wrong_bit = j;
                    // go to left
                    // check first bit that is occupied by only i
                    bool found = 0;
                    for(int k = j; k <= 30; ++k) {
                        //cout << (int)(bool)((1 << k) & i) << " " << (int)(bool)((1 << k) & a) << endl;
                        if(!found && (1 << k) & i && !((1 << k) & a)) {
                            cur_sum = 1 << k;
                            found = 1;
                        }
                        else if(found && (1 << k) & a)
                            cur_sum += 1 << k;
                    }
                    break;
                }
            }
        }
        //cout << i << " " << cur_sum << " " << wrong_bit << endl;
        if(wrong_bit == -1)
            res = min(res, i - b + 1);
        else
            res = min(res, i - b + cur_sum - a + 1);
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}