#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, x;
    cin >> a >> b >> x;
    int jeta = a, jetb = b;
    bool used[10001]; long long res = 0;
    memset(used, 0, sizeof(used));
    while(jeta < x || jetb < x)
    {
        if(jeta < x && !used[jeta])
        {
            used[jeta] = 1;
            res += jeta;
        }
        if(jetb < x && !used[jetb])
        {
            used[jetb] = 1;
            res += jetb;
        }
        jeta += a, jetb += b;
    }
    cout << res << endl;
    return 0;
}