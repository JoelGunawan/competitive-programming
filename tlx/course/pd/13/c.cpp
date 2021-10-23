#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        a[i] = i + 1;
    vector<vector<int>> res;
    do
    {
        // check zig zag
        bool ans = 1;
        for(int i = 1; i < n - 1; ++i)
        {
            if((a[i - 1] < a[i] && a[i] < a[i + 1]) || (a[i - 1] > a[i] && a[i] > a[i + 1]))
                ans = 0;
        }
        if(ans)
            res.push_back(a);
    } while(next_permutation(a.begin(), a.end()));
    for(int i = 0; i < res.size(); ++i)
    {
        for(int j = 0; j < res[i].size(); ++j)
            cout << res[i][j];
        cout << endl;
    }
    return 0;
}