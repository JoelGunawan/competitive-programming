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
    long long sum = 0;
    for(int i = 0; i < n; ++i)
        sum += a[i];
    if(sum % n)
    {
        cout << -1 << endl;
        return;
    }
    // we need to change all the numbers above the average
    int avg = sum / n;
    sort(a.begin(), a.end(), greater<int>());
    int res;
    for(int i = 0; i < n; ++i)
        if(a[i] <= avg)
        {
            res = i;
             break;
        }
    cout << res << endl;
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