#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> t[i][j];
    vector<int> a(n - 1);
    for(int i = 1; i < n; ++i) 
        a[i - 1] = i;
    int res = 0;
    do
    {
        int sum = t[0][a[0]];
        for(int i = 0; i < a.size() - 1; ++i)
            sum += t[a[i]][a[i + 1]];
        sum += t[a[a.size() - 1]][0];
        if(sum == k)
            ++res;
    } while (next_permutation(a.begin(), a.end()));
    cout << res << endl;
}