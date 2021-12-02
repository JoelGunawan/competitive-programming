#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
struct segtree
{
    vector<int> a[16]; int arr_size = (1 << 15);
    void build()
    {
        for(int i = 0; i < 16; ++i)
            a[i] = vector<int>(arr_size , 0);
    }
    void insert(int value, int index)
    {
        for(int i = 0; i < 16; ++i)
            a[i][index] = value;
    }
    void balance(int depth, int left, int right)
    {
        // sort the entire tree
        sort(a[depth].begin() + left, a[depth].begin() + right + 1);
        if(left != right)
        {
            int mid = (left + right) / 2;
            balance(depth + 1, left, mid), balance(depth + 1, mid + 1, right);
        }
    }
    int query(int depth, int left, int right, int cur_left, int cur_right, int value)
    {
        if(cur_right < left || cur_left > right)
            return 0;
        else if(cur_right <= right && cur_left >= left)
        {
            // return binser
            //cout << depth << " " << cur_left << " " << cur_right << " " << --upper_bound(a[depth].begin() + left, a[depth].begin() + right + 1, value) - a[depth].begin() + left endl;
            //for(int i = cur_left; i <= cur_right; ++i)
            //    cout << a[depth][i] << " ";
            //cout << endl;
            return a[depth].begin() + cur_right - --upper_bound(a[depth].begin() + cur_left, a[depth].begin() + cur_right + 1, value);
        }
        else
        {
            int mid = (cur_left + cur_right) / 2;
            ++depth;
            return query(depth, left, right, cur_left, mid, value) + query(depth, left, right, mid + 1, cur_right, value);
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    segtree seg;
    seg.build();
    // use a segment tree where each node has an array and we can binary search the array to find the counter
    for(int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        seg.insert(a, i);
    }
    seg.balance(0, 0, seg.arr_size - 1);
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        cout << seg.query(0, a, b, 0, seg.arr_size - 1, c) << endl;
    }
    return 0;
}