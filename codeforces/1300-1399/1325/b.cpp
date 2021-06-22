#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        set<int> a;
        for(int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            a.insert(num);
        }
        cout << a.size() << endl;
    }
    return 0;
}