#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#pragma GCC optimize("Ofast")
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    // when we select a number, we are basically limiting how much we can choose as min(a, i) + min(b, n - i - 1)
    // we need to select a combination such that it maintains the largest number
    // we can probably greedy this?
    // or we can sort this
    // implement bitmask to find pattern
    // do a 2 way dp, where there is front and back, we find the max such that we 
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    vector<int> ans; int max_size = 0;
    for(int i = 0; i < (1 << n); ++i)
    {
        vector<int> cur;
        for(int j = 0; j < n; ++j)
            if(i & (1 << j))
                cur.pb(j);
        bool valid = 1;
        for(int j = 0; j < cur.size(); ++j)
        {
            if(a[cur[j]].fi < cur.size() - j - 1 || a[cur[j]].se < j)
                valid = 0;
        }
        if(valid && cur.size() > max_size)
            ans = cur, max_size = cur.size();
    }
    cout << "ANSWER" << endl;
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}