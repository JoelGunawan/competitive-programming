#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool compfunc(pair<int, int> a, pair<int, int> b)
{
    return a.first * b.second < a.second * b.first;
}
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    // solution subtask 1
    int n, m, a, b, q;
    cin >> n >> m >> a >> b >> q;
    pair<int, int> array[n * m];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            array[(i - 1) * m + (j - 1)] = {(b + j), (a + i)};
        }
    }
    sort(array, array + n * m, compfunc);
    for(int i = 0; i < q; ++i)
    {
        ll query;
        cin >> query;
        --query;
        int cur_gcd = gcd(array[query].first, array[query].second);
        cout << array[query].first / cur_gcd << "/" << array[query].second / cur_gcd << endl;
    }
}