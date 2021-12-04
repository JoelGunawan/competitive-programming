#include <bits/stdc++.h>
//#define endl "\n"
using namespace std;
struct sparse_table
{
    int a[17][100000], memo[100001];
    void build(vector<int> arr)
    {
        memo[1] = 0;
        for(int i = 2; i <= 1e5; ++i)
            memo[i] = memo[i >> 1] + 1;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < arr.size(); ++i)
            a[0][i] = arr[i];
        for(int i = 1; i < 17; ++i)
            for(int j = 0; j + (1 << (i - 1)) - 1 < 100000; ++j)
                a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);

    }
    int query(int left, int right)
    {
        int log = memo[right - left + 1];
        return min(a[log][left], a[log][right - (1 << log) + 1]);
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sparse_table sp;
    sp.build(a);
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << sp.query(l, r) << endl;
    }
    return 0;
}