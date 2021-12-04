#include <bits/stdc++.h>
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
struct mst
{
    vector<int> a[14]; int a_size = 1 << 13;
    void build(vector<int> arr)
    {
        for(int i = 0; i < 14; ++i)
            a[i] = vector<int>(1 << 13, 0);
        for(int i = 0; i < 14; ++i)
            for(int j = 0; j < arr.size(); ++j)
                a[i][j] = arr[j];
        balance(0, 0, a_size - 1);
    }
    void balance(int depth, int left, int right)
    {
        sort(a[depth].begin() + left, a[depth].begin() + right + 1);
        if(depth != 13)
        {
            int mid = (left + right) / 2;
            balance(depth + 1, left, mid);
            balance(depth + 1, mid + 1, right);
        }
    }
    int query(int depth, int cur_left, int cur_right, int left, int right, int value)
    {
        if(left > right)
            return 0;
        else if(cur_left > right || cur_right < left)
            return 0;
        else if(cur_left >= left && cur_right <= right)
            return a[depth].begin() + cur_right + 1 - lower_bound(a[depth].begin() + cur_left, a[depth].begin() + cur_right + 1, value);
        else
        {
            int mid = (cur_left + cur_right) / 2;
            return query(depth + 1, cur_left, mid, left, right, value) + query(depth + 1, mid + 1, cur_right, left, right, value);
        }
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
    mst mst;
    mst.build(a);
    int total = 0;
    for(int i = 1; i < n; ++i)
        total += mst.query(0, 0, mst.a_size - 1, 0, i - 1, a[i]);
    int m = total, res = 0;
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
        {
            if(a[i] > a[j])
            {
                int x = mst.query(0, 0, mst.a_size - 1, i, j - 1, a[j]), y = mst.query(0, 0, mst.a_size - 1, i, j - 1, a[i]);
                if(total - 2 * (x - y) - 1 < m)
                    m = total - 2 * (x - y) - 1, res = 1;
                else if(total - 2 * (x - y) - 1 == m)
                    ++res;
            }
        }
    cout << m << " " << res << endl;
    return 0;
}