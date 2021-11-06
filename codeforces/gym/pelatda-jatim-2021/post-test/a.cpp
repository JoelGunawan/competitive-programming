#include <bits/stdc++.h>
#define ll long long
#define pb push_bck
using namespace std;
struct max_segtree
{
    int a[(1 << 20) + 1]; int arr_size = (1 << 19);
    void build()
    {
        memset(a, 0, sizeof(a));
    }
    void update(int index, int value)
    {
        a[index + arr_size] = value;
        private_update((index + arr_size) / 2);
    }
    void private_update(int index)
    {
        a[index] = max(a[2 * index], a[2 * index + 1]);
        if(index != 1)
            private_update(index / 2);
    }
    int query(int left, int right)
    {
        return private_query(1, 1, arr_size, left, right);
    }
    int private_query(int index, int cur_left, int cur_right, int left, int right)
    {
        if(cur_right < left || cur_left > right)
            return 0;
        else if(cur_left <= left && cur_right >= right)
            return a[index];
        else
        {
            int mid = (cur_left + cur_right) / 2;
            return max(private_query(2 * index, cur_left, mid, left, right)
            , private_query(2 * index + 1, mid + 1, cur_right, left, right));
        }
    }
};
int main()
{
    // sort into a pair of int, first is value, second is index
    int n, input;
    cin >> n;
    max_segtree a, b;
    for(int i = 0; i < n; ++i)
        cin >> input, a.update(i, input), b.update(i, -input);
    // binary search the possible segments
    int last_index = -1, segment = 0;
    cout << "TEST" << endl;
    while(last_index < n)
    {
        int left = last_index + 1, right = n - 1, highest = last_index + 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(a.query(last_index + 1, mid) == a.query(mid, mid) 
            && b.query(last_index + 1, mid) == b.query(last_index + 1, last_index + 1))
                left = mid + 1, highest = mid;
            else
                right = mid - 1;
        }
        last_index = highest;
        ++segment;
    }
    cout << segment << endl;
    return 0;
}