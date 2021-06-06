#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> counter(26, 0);
    for(char a : s)
        ++counter[a - 'a'];
    while(true)
    {
        int low = gcd(n, k), div = n / low, sum = 0;
        for(int i = 0; i < counter.size(); ++i)
            sum += counter[i] / div;
        if(sum >= low)
        {
            cout << n << endl;
            return;
        }
        --n;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
