#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; string s, subsoal;
    cin >> subsoal >> n >> s;
    ll one = 0, two = 0, res = 0;
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == '1')
            ++one;
        else if(s[i] == '2')
            two += one;
        else
            res += two;
    }
    cout << res << endl;
    return 0;
}