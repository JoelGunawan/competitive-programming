#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int x = 1;
    while(t--)
    {
        cout << "Kasus " << x++ << ":";
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < m; ++i)
            cin >> b[i];
        int mindiff = INT_MAX;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                mindiff = min(mindiff, abs(a[i] - b[j]));
        cout << mindiff << endl;
    }
    return 0;
}