#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<long long> lengths;
long long solve(int a)
{
    string s = to_string(a);
    reverse(s.begin(), s.end());
    long long res = 0;
    for(int i = 0; i < s.size(); ++i)
        res += (s[i] - '0') * lengths[i];
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // init lengths 
    lengths.push_back(1);
    for(int i = 0; i < 10; ++i)
        lengths.push_back(lengths[i] * 10 + 1);
    int t;
    cin >> t;
    while(t--)
    {
        int l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l) << endl;
    }
    return 0;
}