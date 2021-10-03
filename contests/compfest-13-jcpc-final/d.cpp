#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define lll __int128
#define pb push_back
#define ins insert
#define ull unsigned long long
#define ullll unsigned __int128
#define pointer(it) *it
#define lb lower_bound
#define ub upper_bound
using namespace std;
char a[2][300];
bool used[2][300];
vector<vector<int>> arr = {{1, 0, -1, 0}, {0, 1, 0, -1}};
bool valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 2 && y < 300 && a[x][y] == '.' && !used[x][y];
}
int dfs(int a, int b)
{
    used[a][b] = 1;
    int res = 1;
    for(int i = 0; i < arr.size(); ++i)
        if(valid(a + arr[i][0], b + arr[i][1]))
            res += dfs(a + arr[i][0], b + arr[i][1]);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    /*cout << fixed << setprecision(10);
    fstream tc9("./harta/harta_9.in");
    memset(used, 0, sizeof(used));
    int n, m, k;
    tc9 >> n >> m >> k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            tc9 >> a[i][j]; 
    vector<int> res;
    // do a "dfs" and find the segment sizes
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(valid(i, j))
                res.push_back(dfs(i, j));
    int sum = 0;
    for(int i = 12; i >= 1; --i)
    {
        int cur = 0;
        for(int j = 0; j < res.size(); ++j)
            cur += res[j] / i;
        if(cur >= k)
            cout << cur << " " << i << endl;
    }
    for(int i = 0; i < res.size(); ++i)
        if(res[i] > 2)
            sum += res[i], cout << res[i] << " ";
    cout << endl << sum << endl;
    */
    fstream tc5("./harta/harta_5.out");
    fstream tc5test("./harta/harta_5.in");
    int n, m, k;
    tc5test >> n >> m >> k;
    char arr[n][m], arr2[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            tc5test >> arr2[i][j];
    int counter[10];
    memset(counter, 0, sizeof(counter));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        {
            tc5 >> arr[i][j];
            if(arr[i][j] != arr2[i][j] && arr2[i][j] == '#')
                cout << i << " " << j << endl;
            else if(arr[i][j] == '#' && arr2[i][j] == '.')
                cout << i << " " << j << endl;
            if(arr[i][j] != '.' && arr[i][j] != '#')
                ++counter[arr[i][j] - '0'];
        }
    for(int i = 1; i <= 7; ++i)
        cout << counter[i] << " ";
    return 0;
}