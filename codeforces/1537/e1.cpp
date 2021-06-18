#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; string s;
    cin >> n >> k >> s;
    int gcdiv = gcd(n, k);
    // find the index of the first char that is higher than the first
    // if it is higher, check the substring and determine whether it is worth it to cut off
    int firstIndex = n;
    for(int i = 1; i < n; ++i)
    {
        if(s[i] > s[0])
        {
            firstIndex = i;
            break;
        }
        else if(s[i] == s[0])
        {
            if(s.substr(i, n - i) > s.substr(0, n - i))
            {
                firstIndex = i;
                break;
            }
            else if(s.substr(i, n - i) == s.substr(0, n - i))
            {
                string a = s, b = s.substr(i, n - i) + s.substr(0, n - i);
                if(a <= b)
                {
                    firstIndex = i;
                    break;
                }
            }
        }
    }
    string res = s.substr(0, firstIndex);
    for(int i = 0; i < k; ++i)
        cout << res[(i % firstIndex)];
    cout << endl;
    return 0;
}