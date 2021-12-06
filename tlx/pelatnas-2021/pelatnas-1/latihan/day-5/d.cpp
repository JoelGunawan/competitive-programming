#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
using namespace std;
/*
struct merge_sort_tree
{
    vector<int> a[19];
    int arr_size = 1 << 18;
    void build(vector<int> arr)
    {
        for(int i = 0; i < 19; ++i)
            a[i] = vector<int>(1 << 18, 0);
        for(int i = 0; i < arr.size(); ++i)
            a[0][i] = arr[i];
        balance(0, 0, arr_size - 1);
    }
    void balance(int depth, int left, int right)
    {
        sort(a[depth].begin() + left, a[depth].begin() + right + 1);
        if(depth != 18)
        {
            int mid = (left + right) / 2;
            balance(depth + 1, left, mid);  
            balance(depth + 1, mid + 1, right);
        }
    }
    int query(int depth, int cur_left, int cur_right, int left, int right, int value)
    {
        if(cur_left > right || cur_right < left)
            return 0;
        else if(cur_left >= left && cur_right <= right)
            return a[depth].begin() + cur_right - --upper_bound(a[depth].begin() + cur_left, a[depth].begin() + cur_right + 1, value);
        else
        {
            int mid = (cur_left + cur_right) / 2;
            return query(depth + 1, cur_left, mid, left, right, value) + query(depth + 1, mid + 1, cur_right, left, right, value);
        }
    }
};
*/
int subtree[2 * (int)1e5 + 1];
vector<int> edges[2 * (int)1e5 + 1];
bool vis[2 * (int)1e5 + 1];
int euler_index[2 * (int)1e5 + 1];
int euler_tour[2 * (int)1e5 + 1];
int par[2 * (int)1e5 + 1];
int idx = 0;
int dfs(int node = 1)
{
    euler_index[node] = idx;
    euler_tour[idx++] = node;
    subtree[node] = 1;
    vis[node] = 1;
    for(int i = 0; i < edges[node].size(); ++i)
        if(!vis[edges[node][i]])
            par[edges[node][i]] = node, subtree[node] += dfs(edges[node][i]);
    return subtree[node];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // O(nlogn^2)
    // use euler tour
    // and brute force each subtree
    // and find the subtree size outside of that subtree
    // that is equal to some number that we use binary search to find
    // merge sort tree
    int n;
    cin >> n;
    int u, v;
    for(int i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs();
    int res = INT_MAX;
    for(int i = 1; i <= n; ++i)
    {
        int cur = subtree[i];
        int tmp = i;
        while(par[tmp] != 0)
            tmp = par[tmp], subtree[tmp] -= subtree[i];
        int l = euler_index[i], r = euler_index[i] + subtree[i] - 1;
        for(int j = 0; j < l; ++j)
        {
            int tmp_2 = subtree[euler_tour[j]];
            res = min(res, max(n - cur - tmp_2, max(cur, tmp_2)) - min(n - cur - tmp_2, min(cur, tmp_2)));
        }
        for(int j = r + 1; j < n; ++j)
        {
            int tmp_2 = subtree[euler_tour[j]];
            res = min(res, max(n - cur - tmp_2, max(cur, tmp_2)) - min(n - cur - tmp_2, min(cur, tmp_2)));
        }
        tmp = i;
        while(par[tmp] != 0)
            tmp = par[tmp], subtree[tmp] += subtree[i];
    }
    cout << res << endl;
    /*
    vector<int> x(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        x[i] = subtree[i];
    merge_sort_tree mst;
    mst.build(x);
    int res = 1e9;
    for(int i = 1; i <= n; ++i)
    {
        // choose the current node as a starting point
        // basically left and right is the disallowed area
        if(subtree[i] >= n - 1)
            continue;
        int left = euler_index[i], right = euler_index[i] + subtree[i] - 1;
        int target = (n - subtree[i]) / 2;
        int total = n - subtree[i];
        // use merge sort tree to find values closest to target
        // find lower and higher
        int closest = 1e9;
        if(right != n)
        {
            int l = right + 1, r = n;
            // find element closest to target
            // cek sama dengan
            if(mst.query(0, 0, mst.arr_size - 1, l, r, target - 1) != mst.query(0, 0, mst.arr_size - 1, l, r, target))
                closest = target;
            // cari kurang dari
            int le = 1, ri = target - 1, re = 1;
            while(le <= ri)
            {
                int mid = (le + ri) / 2;
                if(mst.query(0, 0, mst.arr_size - 1, l, r, target - 1) != mst.query(0, 0, mst.arr_size - 1, l, r, mid - 1))
                    re = mid, le = mid + 1;
                else
                    ri = mid - 1;
            }
            if(re < abs(closest - target)) 
                closest = re;
            // cari lebih dari
            le = target + 1, ri = n, re = n;
            while(le <= ri)
            {
                int mid = (le + ri) / 2;
                if(mst.query(0, 0, mst.arr_size - 1, l, r, target - 1) != mst.query(0, 0, mst.arr_size - 1, l, r, mid - 1))
                    re = mid, ri = mid - 1;
                else
                    le = mid + 1;
            }
            if(re < abs(closest - target))
                closest = re;
        }
        if(left != 1)
        {
            int l = 1, r = left - 1;
            // find element closest to target
            // cek sama dengan
            if(mst.query(0, 0, mst.arr_size - 1, l, r, target - 1) != mst.query(0, 0, mst.arr_size - 1, l, r, target))
                closest = target;
            // cari kurang dari
            int le = 1, ri = target - 1, re = 1;
            while(le <= ri)
            {
                int mid = (le + ri) / 2;
                if(mst.query(0, 0, mst.arr_size - 1, l, r, target - 1) != mst.query(0, 0, mst.arr_size - 1, l, r, mid - 1))
                    re = mid, le = mid + 1;
                else
                    ri = mid - 1;
            }
            if(re < abs(closest - target)) 
                closest = re;
            // cari lebih dari
            le = target + 1, ri = n, re = n;
            while(le <= ri)
            {
                int mid = (le + ri) / 2;
                if(mst.query(0, 0, mst.arr_size - 1, l, r, target - 1) != mst.query(0, 0, mst.arr_size - 1, l, r, mid - 1))
                    re = mid, ri = mid - 1;
                else
                    le = mid + 1;
            }
            if(re < abs(closest - target))
                closest = re;
        }
        res = min(max(abs(subtree[i] - closest), max(abs(total - closest), abs(total - closest - subtree[i]))), res);
        cout << i << " " << subtree[i] << " " << closest << " " << total - closest << endl;
    }
    cout << res << endl;
    */
    return 0;
}