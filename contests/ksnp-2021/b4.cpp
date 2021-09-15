#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, cur;
    cin >> n;
    multiset<int> a;
    for(int i = 0; i < n; ++i)
    {
        cin >> cur;
        if(lower_bound(a.begin(), a.end(), cur) != a.end())
        {
            a.erase(lower_bound(a.begin(), a.end(), cur));
            a.insert(cur);
        }
        else
            a.insert(cur);
    }
    cout << a.size() << endl;
    return 0;
}