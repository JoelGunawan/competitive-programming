// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        bool a_all_zero = 1, b_all_zero = 1, a_all_one = 1, b_all_one = 1;
        int invert = 0, a_cnt = 0, b_cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] == '1')
                a_all_zero = 0;
            else
                a_all_one = 0, ++a_cnt;
            if(b[i] == '1')
                b_all_zero = 0;
            else
                b_all_one = 0, ++b_cnt;
            if(a[i] != b[i]) 
                ++invert;
        }
        if((a_all_zero || b_all_zero) && a != b) {
            cout << -1 << endl;
            continue;
        }
        int a_one_cnt = n - a_cnt, a_zero_cnt = a_cnt;
        if(a_zero_cnt != b_cnt && a_one_cnt - 1 != b_cnt) {
            cout << -1 << endl;
            continue;
        }
        // find count of inverted zero to one and one to zero
        int invert_zero = 0, invert_one = 0, zero = 0, one = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] != b[i]) {
                if(a[i] == '0')
                    ++invert_zero;
                else
                    ++invert_one;
            }
            else {
                if(a[i] == '0')
                    ++zero;
                else
                    ++one;
            }
        }
        int cnt = 0;
        if(a_zero_cnt == b_cnt) {
            // even amount of final moves
            while(invert_zero > 0 || invert_one > 0) {
                int tmp1 = zero, tmp2 = one, tmp3, ivnert_zero, tmp4 = invert_one;
                if(cnt % 2 == 0) {
                    // do invert_one
                    // transisi
                    zero = inv_one 

                }
                else {
                    --invert_zero;
                    if(invert_zero < 0)
                        invert_zero = 1;
                }
                ++cnt;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}