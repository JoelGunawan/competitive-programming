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
    vector<bool> invalid(n - 2, 0);    
    int res = 2 * n - 1;
    for(int i = 0; i < n - 2; ++i)
    {
        if((a[i] <= a[i + 1] && a[i + 1] <= a[i + 2]) || (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2]))
            invalid[i] = 1;
        else
            ++res;
    }
    for(int i = 0; i < n - 3; ++i)
    {
        if(invalid[i] || invalid[i + 1] 
        || (a[i] <= a[i + 1] && a[i + 1] <= a[i + 3]) || (a[i] <= a[i + 2] && a[i + 2] <= a[i + 3]) 
        || (a[i] >= a[i + 1] && a[i + 1] >= a[i + 3]) || (a[i] >= a[i + 2] && a[i + 2] >= a[i + 3]))
            continue;
        ++res;
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