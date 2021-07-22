#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s; int n;
    cin >> s >> s >> n;
    vector<int> a(n * (n + 1) / 2);
    for(int i = 0; i < n * (n + 1) / 2; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    // put the right as the maximum except on the first few n
    if(n == 1)
    {
        cout << a[0] << endl;
        return 0;
    }
    int pointer1 = 0, pointer2 = a.size() - 1;
    vector<vector<int>> ans(n);
    for(int i = 0; i < n; ++i)
        ans[i] = vector<int>(i + 1, -1);
    for(int i = 2; i < n; ++i)
    {
        ans[i][1] = a[pointer1++]; ans[i][0] = a[pointer1++];
        ans[i][2] = a[pointer2--];
    }
    int forbidden, mindiff = INT_MAX;
    for(int i = pointer1; i < pointer2; ++i)
    {
        if(a[i + 1] - a[i] < mindiff)
        {
            forbidden = i;
            mindiff = a[i + 1] - a[i];
        }
    }
    ans[1][0] = a[forbidden + 1]; ans[1][1] = a[forbidden];
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < i + 1; ++j)
            if(ans[i][j] == -1)
            {
                while(pointer1 == forbidden || pointer1 == forbidden + 1)
                    ++pointer1;
                ans[i][j] = a[pointer1++];
            }
    }
    for(int i = 0 ; i < n; ++i)
    {
        for(int j = 0; j < i + 1; ++j)
        {
            cout << ans[i][j];
            if(j != i)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}