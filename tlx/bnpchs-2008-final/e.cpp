#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, t, d, e;
        cin >> n;
        pair<int, int> a[n];
        for(int i = 0; i < n; ++i)
            cin >> t >> d >> e, a[i] = {t + d + e, t + d};
        sort(a, a + n);
        int time = 0, counter = 0;
        for(int i = 0; i < n; ++i)
        {
            if(a[i].second >= time)
                ++counter, time = a[i].first;
        }
        cout << counter << endl;
    }
    return 0;
}