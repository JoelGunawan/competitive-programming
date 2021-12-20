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
    int n;
    cin >> n;
    vector<int> one, two;
    for(int i = 0; i < n; ++i) {
        int type, val;
        cin >> type >> val;
        if(type == 1)
            one.pb(val);
        else
            two.pb(val);
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    int res = INT_MAX;
    for(int i = 0; i <= one.size(); ++i) {
        // make the first i ones horizontal
        int horizontal = 0, vertical = one.size() - i;
        for(int j = 0; j < i; ++j)
            horizontal += one[j];
        vertical += 2 * two.size();
        //cout << vertical << " " << horizontal << endl;
        for(int j = 0; j < two.size(); ++j) {
            if(vertical - 2 >= horizontal + two[j])
                vertical -= 2, horizontal += two[j];
        }
        //cout << i << " " << vertical << " " << horizontal << endl;
        if(vertical >= horizontal)
            res = min(vertical, res);
    }
    cout << res << endl;
    return 0;
}