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
    int a[1 << 19], lazy[1 << 19], arr_size = 1 << 18;
    segtree()
    {
        memset(a, 0, sizeof(a));
        memset(lazy, 0, sizeof(lazy));
    }
    int merge(int a, int b)
    {
        return a + b;
    }
    void update(int cur, int cur_left, int cur_right, int left, int right, int value)
    {
        if(cur_left > right || cur_right < left)
            return;
        else if(cur_left >= left && cur_right <= right)
        {
            if(value)
            {
                a[cur] = (cur_right - cur_left + 1) - a[cur];
                lazy[cur] = 1 - lazy[cur];
            }
        }
        else
        {
            int mid = (cur_left + cur_right) / 2;
            if(lazy[cur])
            {
                // propagate down
                lazy[cur] = 0;
                update(2 * cur, cur_left, mid, cur_left, mid, 1);
                update(2 * cur + 1, mid + 1, cur_right, mid + 1, cur_right, 1);
            } 
            update(2 * cur, cur_left, mid, left, right, value);
            update(2 * cur + 1, mid + 1, cur_right, left, right, value);
            a[cur] = query(2 * cur, cur_left, mid, cur_left, mid) + query(2 * cur + 1, mid + 1, cur_right, mid + 1, cur_right);
        }
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
            if(lazy[cur])
            {
                // propagate down
                lazy[cur] = 0;
                update(2 * cur, cur_left, mid, cur_left, mid, 1);
                update(2 * cur + 1, mid + 1, cur_right, mid + 1, cur_right, 1);
            }
            return query(2 * cur, cur_left, mid, left, right) + query(2 * cur + 1, mid + 1, cur_right, left, right);
        }
    }
};
vector<int> edges[200001];
int order[200001], subtree_size[200001], idx = 0;
int dfs(int node)
{
    order[node] = idx++;
    subtree_size[node] = 1;
    for(int i = 0; i < edges[node].size(); ++i)
        subtree_size[node] += dfs(edges[node][i]);
    return subtree_size[node];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // use euler tour to sort the indices
    // and use lazy to update
    int n;
    cin >> n;
    segtree seg;
    int p[n - 1], t[n];
    for(int i = 0; i < n - 1; ++i)
    {
        int x;
        cin >> x;
        //cout << x << " " << i + 2 << endl;
        edges[x].pb(i + 2);
    }
    dfs(1);
    for(int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        seg.update(1, 0, seg.arr_size - 1, order[i + 1], order[i + 1], t);
        //cout << seg.query(1, 0, seg.arr_size - 1, order[i + 1], order[i + 1]) << " ";
    }
    //cout << endl;
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        string query; int num;
        cin >> query >> num;
        //cout << order[num] << " " << subtree_size[num] << endl;
        //for(int i = 0; i < n; ++i)
        //    cout << seg.query(1, 0, seg.arr_size - 1, order[i + 1], order[i + 1]) << " ";
        //cout << endl;
        if(query == "get")
            cout << seg.query(1, 0, seg.arr_size - 1, order[num], order[num] + subtree_size[num] - 1) << endl;
        else
        {
            seg.update(1, 0, seg.arr_size - 1, order[num], order[num] + subtree_size[num] - 1, 1);
            //cout << "UPDATE" << endl;
            //cout << seg.query(1, 0, seg.arr_size - 1, order[num], order[num] + subtree_size[num] - 1) << endl;
        }
    }
    return 0;
}