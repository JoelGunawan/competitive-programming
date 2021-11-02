#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, int> mp;
int get_len(ll number)
{
    if(mp[number] == 0)
    {
        if(number & 1)
            mp[number] = get_len(3 * number + 1) + 1;
        else
            mp[number] = get_len(number / 2) + 1;
    }
    return mp[number];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mp[1] = 1;
    int res = 0;
    for(int i = 1; i < 1e6; ++i)
        res = max(res, get_len(i));
    cout << res << endl;
    return 0;
}