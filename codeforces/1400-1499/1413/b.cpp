#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr1(n, vector<int>(m)), arr2(m, vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            cin >> arr1[i][j];
        }
    }
 
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> arr2[i][j];
        }
    }
 
    vector<int> toprow(m);
    for(int i = 0; i < m; ++i)
    {
        toprow[i] = arr2[i][0];
    }
 
    int selectedcolumn;
 
    bool found = false;
 
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(toprow[j] == arr1[i][0])
            {
                selectedcolumn = j;
                found = true;
                break;
            }
        }
        if(found) break;
    }
 
    for(int i = 0; i < n; ++i)
    {
        int index;
        for(int j = 0; j < n; ++j)
        {
            if(arr1[j][0] == arr2[selectedcolumn][i])
            {
                index = j;
                break;
            }
        }
        for(int j = 0; j < m; ++j)
        {
            cout << arr1[index][j];
            if(j == m - 1) cout << endl;
            else cout << " ";
        }
    }
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}