#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> horizontal_reflect(vector<vector<int>> a)
{
    int n = a.size();
    for(int i = 0; i < n / 2; ++i)
        for(int j = 0; j < n; ++j)
            swap(a[i][j], a[n - i - 1][j]);
    return a;
}
vector<vector<int>> vertical_reflect(vector<vector<int>> a)
{
    int n = a.size();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n / 2; ++j)
            swap(a[i][j], a[i][n - j - 1]);
    return a;
}
vector<vector<int>> left_diagonal_reflect(vector<vector<int>> a)
{
    int n = a.size();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n - i; ++j)
            swap(a[n - j - 1][n - i - 1], a[i][j]);
    /*
    (1, 0) swap (2, 1)
    (0, 0) swap (2, 2)
    (0, 1) swap (1, 2)
    */
    return a;
}
vector<vector<int>> right_diagonal_reflect(vector<vector<int>> a)
{
    int n = a.size();
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < i; ++j)
            swap(a[i][j], a[j][i]);
    }
    return a;
}
void print_array(vector<vector<int>> a)
{
    for(int i = 0; i < a.size(); ++i)
    {
        for(int j = 0; j < a[i].size(); ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n >> n;
    vector<vector<int>> a(n, vector<int>(n)), b = a;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    cin >> n >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> b[i][j];
    if(b == a)
        cout << "identik" << endl;
    else if(b == horizontal_reflect(a))
        cout << "horisontal" << endl;
    else if(b == vertical_reflect(a))
        cout << "vertikal" << endl;
    else if(b == left_diagonal_reflect(a))
        cout << "diagonal kiri bawah" << endl;
    else if(b == right_diagonal_reflect(a))
        cout << "diagonal kanan bawah" << endl;
    else
        cout << "tidak identik" << endl;
    return 0;
}