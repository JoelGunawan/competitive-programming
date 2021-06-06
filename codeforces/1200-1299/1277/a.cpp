#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> beautifulNumbers)
{
    int n, result = 0;
    cin >> n;
    for(int a : beautifulNumbers)
    {
        if (a <= n) ++result;
    }
    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    vector<int> beautifulNumbers;
    for(int i = 1; i <= 9; ++i)
    {
        int tmp = 0;
        for(int j = 1; j <= 9; ++j)
        {
            tmp = tmp * 10 + i;
            beautifulNumbers.push_back(tmp);
        }
    }
    while(t--) solve(beautifulNumbers);
    return 0;
}
