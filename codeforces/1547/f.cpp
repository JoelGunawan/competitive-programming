#include <bits/stdc++.h>
#define endl "\n"
#define rll register int_fast64_t
#define rint register int_fast32_t
#define v vector
#define pb push_back
#define ins insert
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void test_case()
{
    rint n;
    cin >> n;
    vector<int> a(n);
    for(rint i = 0; i < n; ++i)
        cin >> a[i];
    int totalgcd = a[0];
    for(rint i = 1; i < n; ++i)
        totalgcd = gcd(totalgcd, a[i]);
    for(rint i = 0; i < n; ++i)
        a[i] /= totalgcd;
    vector<set<int>> factors(n, set<int>());
    for(int i = 0; i < n; ++i)
    {
        for(int j = 2; j <= sqrt(a[i]); ++j)
        {
            if(a[i] % j == 0)
            {
                while(a[i] % j == 0)
                    a[i] /= j;
                factors[i].insert(j);
            }
        }
        if(a[i] > 1)
            factors[i].insert(a[i]);
    }
    rint res = 0;
    for(int i = 0; i < n; ++i)
    {
        while(factors[i].size() > 0)
        {
            rint num = *factors[i].begin(), l = i, r = i, localres = 1;
            l = (l + n - 1) % n; r = (r + n + 1) % n;
            while(factors[l].find(num) != factors[l].end())
            {
                factors[l].erase(num);
                l = (l + n - 1) % n;
                ++localres;
            }
            while(factors[r].find(num) != factors[r].end())
            {
                factors[r].erase(num);
                r = (r + n + 1) % n;
                ++localres;
            }
            res = max(res, localres);
            factors[i].erase(factors[i].begin());
        }
    }
    cout << res << endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}