#include <bits/stdc++.h>
#define ll long long
//#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("Ofast")
using namespace std;
const int n = 1 << 20;
int head[n], next_node[n], dsu_size[n];
ll a[n];
struct dsu
{
    int find_head(int node)
    {
        if(head[node] == -1)
            return node;
        else
            return find_head(head[node]);
    }
    void merge(int a, int b)
    {
        int x = find_head(a), y = find_head(b);
        if(x != y)
        {
            if(dsu_size[x] < dsu_size[y])
                dsu_size[y] += dsu_size[x], head[x] = y;
            else
                dsu_size[x] += dsu_size[y], head[y] = x;
        }
    }
};
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    memset(head, -1, sizeof(head));
    memset(a, -1, sizeof(a));
    for(int i = 0; i < n; ++i)
        next_node[i] = (i + 1) % n, dsu_size[i] = 1;
    dsu ds;
    while(q--)
    {
        ll t, x;
        cin >> t >> x;
        if(t == 1)
        {
            // dsu it?
            // basically create a structure to find the head
            // find the head
            int h = ds.find_head(x % n);
            //cout << "START" << endl;
            //cout << h << endl;
            int prev = h;
            while(a[prev] != -1)
            {
                prev = next_node[h];
                ds.merge(next_node[h], h);
                next_node[ds.find_head(h)] = next_node[next_node[h]];
                h = ds.find_head(h);
                //cout << prev << " " << h << endl;
            } 
            //cout << "END" << endl;
            a[prev] = x;
        }
        else
            cout << a[x % n] << endl;
    }
    return 0;
}