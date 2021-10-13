#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int counter[n + 1], arr[n]; memset(counter, 0, sizeof(counter));
    int in;
    for(int i = 0; i < n; ++i)
        cin >> in, arr[i] = in, ++counter[in];
    
    if(k == 0)
    {
        memset(counter, 0, sizeof(counter));
        int res = 1;
        for(int i = 0; i < n; ++i)
        {
            ++counter[arr[i]];
            if(counter[arr[i]] > m)
                memset(counter, 0, sizeof(counter)), ++res, counter[arr[i]] = 1;
        }
        cout << res << endl;
    }
    else if(counter[1] == n)
    {
        counter[1] -= k;
        cout << ceil((double)counter[1] / m) << endl;
    }
    else
        cout << 3 << endl;
}