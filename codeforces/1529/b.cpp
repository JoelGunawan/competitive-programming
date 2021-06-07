#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

void test_case()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int minPositive = INT_MAX, minNegative = 1, maxNegative = INT_MIN, b = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] > 0)
            minPositive = min(minPositive, a[i]);
        else
        {
            minNegative = min(minNegative, a[i]);
            maxNegative = max(maxNegative, a[i]);
            ++b;
        }
    }
    if(minPositive != INT_MAX && (maxNegative - minNegative >= minPositive || b <= 1))
        cout << b + 1;
    else
        cout << b;
    cout << endl;
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