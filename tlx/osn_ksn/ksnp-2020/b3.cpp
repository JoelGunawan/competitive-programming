#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin >> m;
    tuple<int, int, int> a[m];
    int t, s, p;
    for(int i = 0; i < m; ++i)
        cin >> t >> s >> p, a[i] = {t, s, p};
    sort(a, a + m);
    int dp[10001], currentindex = 0;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= 10000; ++i)
    {
        dp[i] = max(dp[i], dp[i - 1]);
        while(get<0>(a[currentindex]) == i)
            dp[get<1>(a[currentindex])] = max(dp[i] + get<2>(a[currentindex]), dp[get<1>(a[currentindex])]), ++currentindex;    
    }
    cout << dp[10000] << endl;
    return 0;
}