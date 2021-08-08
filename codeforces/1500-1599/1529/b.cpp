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
    int minPositive = INT_MAX;
    multiset<int> b;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] > 0)
            minPositive = min(minPositive, a[i]);
        else
            b.insert(a[i]);
    }
    int minDiff = INT_MAX;
    if(b.size() > 1)
    {
        auto it = b.begin(), it2 = it;
        ++it2;
        do
        {
            minDiff = min(minDiff, *it2 - *it);
            ++it; ++it2;
        } while (it2 != b.end());
    }
    if(minPositive != INT_MAX && (minDiff >= minPositive || b.size() <= 1))
        cout << b.size() + 1;
    else
        cout << b.size();
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