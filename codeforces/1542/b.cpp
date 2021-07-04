#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
void test_case()
{
    ll n, a, b;
    cin >> n >> a >> b;
    // what happens if we are in a junction, we can divide and subtract
    // if it is a power of a, divide, else subtract
    // get all powers of a in an array
    vector<ll> powers = {1};
    while(a != 1 && powers[powers.size() - 1] < n)
        powers.push_back(powers[powers.size() - 1] * a);
    string ans = "No";
    for(int i = 0; i < powers.size(); ++i)
    {
        if(n >= powers[i] && (n - powers[i]) % b == 0)
            ans = "Yes";
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}