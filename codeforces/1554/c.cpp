#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        // find the smallest k such that k doesn't appear in the sequence
        // using the property n ^ k = z is equal to n ^ z = k, we can find
        // the smallest k such that n ^ k >= m + 1, this means that it is not in the sequence
        // we do this by matching for each index n with m, if n is 0 and m is 1, we need to increase n by 1
        // go from big to small
        ++m;
        int ans = 0;
        for(int i = 30; i >= 0 && n < m; --i)
        {
            if(!(n >> i & 1) && m >> i & 1) 
                ans |= 1 << i, n |= 1 << i;
        }
        cout << ans << endl;
    }
}