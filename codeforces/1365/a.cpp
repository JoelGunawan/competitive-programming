#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<bool> rows(n, 0), columns(m, 0);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int input;
            cin >> input;
            if(input)
            {
                rows[i] = 1;
                columns[j] = 1;
            }
        }
    }
    int rowCount = 0, columnCount = 0;
    for(int i = 0; i < rows.size(); i++)
        rowCount += !rows[i];
    for(int i = 0; i < columns.size(); i++)
        columnCount += !columns[i];
    if(min(rowCount, columnCount) & 1)
        cout << "Ashish";
    else
        cout << "Vivek";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
