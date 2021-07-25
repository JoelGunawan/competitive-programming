#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr(5, vector<int>(n));
        for(int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            vector<int> counter(5, 0);
            for(int j = 0; j < s.size(); ++j)
                ++counter[s[j] - 'a'];
            for(int j = 0; j < 5; ++j)
                arr[j][i] = 2 * counter[j] - s.size();   
        }
        for(int i = 0; i < 5; ++i)
            sort(arr[i].begin(), arr[i].end());
        int ans = 0;
        for(int i = 0; i < 5; ++i)
        {
            int res = 0, last = n;
            for(int j = n - 1; j >= 0; --j)
            {
                if(res + arr[i][j] <= 0)
                    break;
                else
                {
                    res += arr[i][j];
                    --last;
                }
            }
            ans = max(ans, n - last);
        }
        cout << ans << endl;
    }
    return 0;
}