#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // use dp and maintain a multiset
    multiset<int> negative;
    long long sum = 0; int res = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] >= 0)
        {
            sum += a[i];
            ++res;
        }
        else
        {
            if(sum + a[i] >= 0)
            {
                sum += a[i];
                ++res;
                negative.insert(a[i]);
            }
            else if(negative.size() > 0 && a[i] > *negative.begin())
            {
                sum += a[i] - *negative.begin();
                negative.erase(negative.begin());
                negative.insert(a[i]);
            }
        }
    }
    cout << res << endl;
    return 0;
}