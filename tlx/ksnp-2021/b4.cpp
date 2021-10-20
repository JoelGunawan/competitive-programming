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
        if(a.lower_bound(cur) != a.end())
        {
            a.erase(a.lower_bound(cur));
            a.insert(cur);
        }
        else
            a.insert(cur);
    }
    cout << a.size() << endl;
    return 0;
}