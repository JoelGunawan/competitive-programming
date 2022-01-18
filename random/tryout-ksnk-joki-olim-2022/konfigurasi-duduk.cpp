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
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> a = {1, 2, 3, 4, 5};
    int cnt = 0, n = 5;
    do {
        bool ans = 1;
        for(int i = 0; i < n; ++i) {
            if(a[i] == 1) {
                if((i == 0 || a[i - 1] != 2) && (i == n - 1 || a[i + 1] != 2))
                    ans = 0;
                if((i != 0 && a[i - 1] == 3) || (i != n - 1 && a[i + 1] == 3))
                    ans = 0;
            }
            else if(a[i] == 3) {
                if((i == 0 || a[i - 1] != 4) && (i == n - 1 || a[i + 1] != 4))
                    ans = 0;
            }
            else if(a[i] == 4) {
                if((i != 0 && a[i - 1] == 5) || (i != n - 1 && a[i + 1] == 5))
                    ans = 0;
            }
        }
        if(ans) {
            for(int i = 0; i < n; ++i)
                cout << a[i] << " ";
            cout << endl;
            ++cnt;
        }
    } while(next_permutation(a.begin(), a.end()));
    std::cout << cnt << endl;
    return 0;
}