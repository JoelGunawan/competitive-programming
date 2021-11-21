#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> segment_size = {0, 1};
    while(segment_size.back() < 1e6)
        segment_size.pb(segment_size.size() + segment_size.back());
    int n;
    cin >> n;
    string res = "";
    vector<int> indexes;
    while(n > 0)
    {
        int cur = --upper_bound(segment_size.begin(), segment_size.end(), n) - segment_size.begin();
        for(int i = 0; i < cur; ++i)
            res += '0';
        res += "1";
        n -= segment_size[cur];
    }
    //reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}