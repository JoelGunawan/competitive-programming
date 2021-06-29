#include <bits/stdc++.h>
#define ll long long
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll sum = 0;
    sort(a.begin(), a.end());
    int index = 0;
    while(index < n && a[index] <= sum + 1)
    {
        sum += a[index];
        ++index;
    }
    cout << sum << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        test_case();
}