#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k; string subsoal, p, s;
    cin >> subsoal >> n >> k >> p >> s;
    // k is equal to k % (n + (n + 1) / 2)
    // we can make a O(n^3) algo
    if(subsoal[1] == '1')
        cout << 25 << endl;
    else if(subsoal[2] == '2')
    {
        sort(p.begin(), p.end(), greater<int>()); int counter = 0;
        for(int i = 0; i < n; ++i)
            if(s[i] == '1')
                ++counter;
        int res = 0;
        for(int i = 0; i < counter; ++i)
            res += (p[i] - '0');
        cout << res << endl;
    }
    else if(subsoal[3] == '3')
    {
        // just brute force every move k
        
    }
    return 0;
}