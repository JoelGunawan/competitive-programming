#include <bits/stdc++.h>
using namespace std;
struct segtree
{
    vector<int> arr;
    segtree(int input_size, int default_value)
    {
        // convert input_size to closest power of 2
        arr = vector<int>(2 * input_size, default_value);
    }
    void update(int cur, int val, bool type)
    {
        if(cur >= arr.size() / 2)
            arr[cur] = val;
        else if(type)
            arr[cur] = arr[cur << 1] ^ arr[cur << 1 | 1];
        else
            arr[cur] = arr[cur << 1] | arr[cur << 1 | 1];
        if(cur != 1)
            update(cur / 2, val, !type);
    }
    void update_point(int index, int val)
    {
        update(index + arr.size() / 2, val, 1);
    }
};
int main()
{
    int n, m, idx, in;
    cin >> n >> m;
    n = 1 << n;
    segtree tree(n, 0);
    for(int i = 0; i < n; ++i)
    {
        cin >> in;
        tree.update_point(i, in);
    }
    for(int i = 0; i < m; ++i)
    {
        cin >> idx >> in;
        tree.update_point(idx - 1, in);
        cout << tree.arr[1] << endl;
    }
}