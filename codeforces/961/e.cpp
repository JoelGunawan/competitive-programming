#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
struct merge_sort_tree
{
    vector<int> a[19]; int arr_size = 1 << 18;
    merge_sort_tree()
    {
        for(int i = 0; i < 19; ++i)
            a[i] = vector<int>(1 << 19, 0);
    }
    void build(vector<int> arr)
    {
        for(int i = 0; i < arr.size(); ++i)
        {
            for(int j = 0; j < 19; ++j)
                a[j][i] = arr[i];
        }
        balance(0, 0, arr_size - 1);
        //for(int i = 0; i < 19; ++i)
        //{
        //    for(int j = 0; j < 10; ++j)
        //        cout << a[i][j] << " ";
        //    cout << endl;
        //}
    }
    void balance(int depth, int left, int right)
    {
        //cout << left << " " << right << endl;
        sort(a[depth].begin() + left, a[depth].begin() + right + 1);
        if(depth != 18)
        {
            ++depth;
            int mid = (left + right) / 2;
            balance(depth, left, mid);
            balance(depth, mid + 1, right);
        }
    }
    int query(int depth, int cur_left, int cur_right, int left, int right, int value)
    {
        if(cur_left > right || cur_right < left)
            return 0;
        else if(cur_left >= left && cur_right <= right)
            return a[depth].begin() + cur_right + 1 - lower_bound(a[depth].begin() + cur_left, a[depth].begin() + cur_right + 1, value);
        else
        {
            int mid = (cur_left + cur_right) / 2;
            ++depth;
            return query(depth, cur_left, mid, left, right, value) + query(depth, mid + 1, cur_right, left, right, value);
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    merge_sort_tree mst;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    mst.build(a);
    //cout << "TEST" << endl;
    ll res = 0;
    for(int i = 2; i <= n; ++i)
        res += mst.query(0, 0, mst.arr_size - 1, 1, min(a[i], i - 1), i);
    cout << res << endl;
    return 0;
}