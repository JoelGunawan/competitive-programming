#include <bits/stdc++.h>
#define pb push_back
#define ins isnert
#define fi first
#define se second
#define ll long long
#define ld long double
using namespace std;
struct node
{
    int lis = 0, lds = 0, one_count = 0, zero_count = 0;
};
struct segtree
{
    // the segtree maintains LIS, LDS, zero_count, one_count
    int arr_size = 1 << 20;
    node a[1 << 21];
    bool lazy[1 << 21];
    node empty;
    void build(vector<bool> arr)
    {
        empty.lis = 0, empty.lds = 0, empty.one_count = 0, empty.zero_count = 0;
        memset(lazy, 0, sizeof(lazy));
        for(int i = 0; i < arr.size(); ++i)
        {
            node cur;
            cur.lis = 1, cur.lds = 1;
            if(arr[i])
                 ++cur.one_count;
            else
                ++cur.zero_count;
            a[arr_size + i] = cur;
        }
        for(int i = arr.size(); i < arr_size - 1; ++i)
            a[arr_size + i] = empty;
        for(int i = arr_size - 1; i >= 1; --i)
            a[i] = merge(a[2 * i], a[2 * i + 1]);
    }
    node merge(node a, node b)
    {
        // assuming a is left and b is right
        node res;
        res.one_count = a.one_count + b.one_count;
        res.zero_count = a.zero_count + b.zero_count;
        res.lis = max(a.lis + b.one_count, a.zero_count + b.lis);
        res.lds = max(a.lds + b.zero_count, a.one_count + b.lds);
        return res;
    }
    // do lazy update
    void update(int cur, int cur_left, int cur_right, int left, int right)
    {
        if(cur_left > right || cur_right < left)
            return;
        // invert/update the current node
        else if(cur_left >= left && cur_right <= right)
        {
            // swap lds and lis, one_count and zero_count
            lazy[cur] = !lazy[cur];
            //cout << cur << " " << cur_left << " " << cur_right << endl;
            //cout << a[cur].lds << " " << a[cur].lis << " " << a[cur].zero_count << " " << a[cur].one_count << endl;
            swap(a[cur].lds, a[cur].lis);
            swap(a[cur].one_count, a[cur].zero_count);
            //cout << a[cur].lds << " " << a[cur].lis << " " << a[cur].zero_count << " " << a[cur].one_count << endl;
            return;
        }
        else
        {
            // propagate down
            int mid = (cur_left + cur_right) / 2;
            if(lazy[cur])
            {
                lazy[cur] = 0;
                update(2 * cur, cur_left, mid, cur_left, mid);
                update(2 * cur + 1, mid + 1, cur_right, mid + 1, cur_right);
            }
            update(2 * cur, cur_left, mid, left, right);
            update(2 * cur + 1, mid + 1, cur_right, left, right);
            a[cur] = merge(query(2 * cur, cur_left, mid, cur_left, mid), query(2 * cur + 1, mid + 1, cur_right, mid + 1, cur_right));
            //cout << cur_left << " " << cur_right << endl;
            //cout << a[cur].lds << " " << a[cur].lis << " " << a[cur].zero_count << " " << a[cur].one_count << endl;
        }
    }
    node query(int cur, int cur_left, int cur_right, int left, int right)
    {
        if(cur_left > right || cur_right < left)
            return empty;
        else if(cur_left >= left && cur_right <= right)
            return a[cur];
        else
        {
            int mid = (cur_left + cur_right) / 2;
            if(lazy[cur])
            {
                lazy[cur] = 0;
                update(2 * cur, cur_left, mid, cur_left, mid);
                update(2 * cur + 1, mid + 1, cur_right, mid + 1, cur_right);
            }
            return merge(query(2 * cur, cur_left, mid, left, right), query(2 * cur + 1, mid + 1, cur_right, left, right));
        }
    }

};
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; string s;
    cin >> n >> q >> s;
    vector<bool> a(n);
    for(int i = 0; i < n; ++i)
        a[i] = (s[i] == '1');
    segtree seg;
    seg.build(a);
    //cout << seg.a[1].lis << " " << seg.a[1].lds << " " << seg.a[1].one_count << " " << seg.a[1].zero_count << endl;
    for(int i = 0; i < q; ++i)
    {
        //for(int i = 0; i < 1 << 4; ++i)
        //    cout << seg.a[i].lds << " " << seg.a[i].lis 
        //    << " " << seg.a[i].zero_count << " " << seg.a[i].one_count << endl;
        int type;
        cin >> type;
        if(type == 1)
        {
            int l, r;
            cin >> l >> r;
            --l, --r;
            seg.update(1, 0, seg.arr_size - 1, l, r);
            node tmp = seg.query(1, 0, seg.arr_size - 1, 0, n - 1);
            //cout << tmp.lds << " " << tmp.lis << " " << tmp.zero_count << " " << tmp.one_count << endl;
        }
        else
            cout << seg.query(1, 0, seg.arr_size - 1, 0, n - 1).lis << endl;
    }
    return 0;
}