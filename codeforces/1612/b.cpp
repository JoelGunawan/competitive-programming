#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("Ofast")
using namespace std;
void test_case()
{
    int n, a, b;
    cin >> n >> a >> b;
    set<int> numbers;
    for(int i = 1; i <= n; ++i)
        numbers.insert(i);
    vector<int> left = {a}, right = {b};
    numbers.erase(a), numbers.erase(b);
    for(int i = 1; i < a; ++i)
        if(numbers.find(i) != numbers.end())
            right.pb(i), numbers.erase(i);
    for(int i = n; i > b; --i)
        if(numbers.find(i) != numbers.end())
            left.pb(i), numbers.erase(i);
    for(int i = 1; i <= n; ++i)
    {
        if(numbers.find(i) != numbers.end())
        {
            if(left.size() >= n / 2)
                right.pb(i);
            else    
                left.pb(i);
            numbers.erase(i);
        }
    }
    bool ans = (left.size() == n / 2) && (right.size() == n / 2);
    for(int i = 0; i < left.size(); ++i)
        if(left[i] < a)
            ans = 0;
    for(int i = 0; i < right.size(); ++i)
        if(right[i] > b)
            ans = 0;
    if(!ans)
    {
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < left.size(); ++i)
        cout << left[i] << " ";
    for(int i = 0; i < right.size(); ++i)
        cout << right[i] << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}