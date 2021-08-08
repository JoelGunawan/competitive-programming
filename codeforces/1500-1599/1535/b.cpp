#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void test_case()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // multiples of 2 in the front, others in the back
    vector<int> b, c;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] & 1)
            b.push_back(a[i]);
        else
            c.push_back(a[i]);
    }
    // b is odd c is even
    for(int i = 0; i < c.size(); ++i)
        a[i] = c[i];
    for(int i = c.size(); i < n; ++i)
        a[i] = b[i - c.size()];
    
    int res = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(gcd(a[i], 2 * a[j]) > 1)
                ++res;
        }
    }
    cout << res << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}