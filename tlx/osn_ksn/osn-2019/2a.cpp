#include <bits/stdc++.h>
using namespace std;
struct segtree
{
    int a[1 << 19];

};
int main()
{
    int n, m;
    cin >> n >> m;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    // sparse segment tree bisa
    // anyways sort and use binser?
    // 2 people know each other if and only if there is an index where the start or the end index is inside of a node
    
    return 0;
}