#include <bits/stdc++.h>
using namespace std;
struct segtree
{
    int a[1 << 18], arr_size = 1 << 17;
    segtree()
    {
        memset(a, 0, sizeof(a));
    }
    int merge(int a, int b)
    {
        return max(a, b);
    }
    void update(int index, int value)
    {
        a[arr_size + index] = merge(a[arr_size + index], value);
        private_update((arr_size + index) / 2);
    }
    void private_update(int index)
    {
        a[index] = merge(a[2 * index], a[2 * index + 1]);
        if(index != 1)
            private_update(index / 2);
    }
    int query(int cur, int cur_left, int cur_right, int left, int right)
    {
        if(cur_left > right || cur_right < left)
            return 0;
        else if(cur_left >= left && cur_right <= right)
            return a[cur];
        else
        {
            int mid = (cur_left + cur_right) / 2;
            return merge(query(2 * cur, cur_left, mid, left, right), query(2 * cur + 1, mid + 1, cur_right, left, right));
        }
    }
};
int main()
{
    // use an Range Max Query using 2 segtrees
    segtree coins, diamonds;
    int n, c, d;
    cin >> n >> c >> d;
    int max_res = 0;
    for(int i = 0; i < n; ++i)
    {
        int b, p; char type;
        cin >> b >> p >> type;
        if(type == 'C')
        {
            if(p <= c)
            {
                int res = diamonds.query(1, 0, diamonds.arr_size - 1, 1, d);
                if(c - p > 0)
                    res = max(res, coins.query(1, 0, coins.arr_size - 1, 1, c - p));
                if(res > 0)
                    max_res = max(max_res, res + b);
            }
            coins.update(p, b);
        }
        else
        {
            if(p <= d)
            {
                int res = coins.query(1, 0, coins.arr_size - 1, 1, c);
                if(d - p > 0)
                    res = max(res, diamonds.query(1, 0, diamonds.arr_size - 1, 1, d - p));
                if(res > 0)
                    max_res = max(max_res, res + b);
            }
            diamonds.update(p, b);
        }
    }
    cout << max_res << endl;
    return 0;
}