// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
struct disjoint_set {
    int head[200005], size[200005];
    disjoint_set() {
        fill(size, size + 200005, 1);
        memset(head, -1, sizeof(head));
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int a, int b) {
        int x = find_head(a), y = find_head(b);
        if(x != y) {
            if(size[y] > size[x])
                swap(x, y);
            size[x] += size[y], head[y] = x;
        }
        return x != y;
    }
};
struct node {
    int l = -1, r = -1;
    vector<int> components = {};
};
struct trie {
	vector<node> a = {node()};
    disjoint_set dsu;
    int m, lsb;
    void update(int nd, int depth, int cur, int val) {
        a[nd].components.pb(cur);
        if(depth == -1)
            return;
        if((1 << depth) & val) {
            if(a[nd].r == -1)
                a[nd].r = a.size(), a.pb(node());
            update(a[nd].r, depth - 1, cur, val);
        }
        else {
            if(a[nd].l == -1)
                a[nd].l = a.size(), a.pb(node());
            update(a[nd].l, depth - 1, cur, val);
        }
    }
	void query(int nd, int depth, int cur, int val) {
        // we can merge since we've beeen following the line
		if(depth == -1) {
            for(auto i : a[nd].components) {
                dsu.merge(i, cur);
            }
            a[nd].components.clear();
            a[nd].components.pb(cur);
        }
		else {
			if((1 << depth) & m) {
                if((1 << depth) & val) {
                    // everything that is 1 << depth should be merged
                    if(a[nd].r != -1) {
                        for(auto i : a[a[nd].r].components) {
                            dsu.merge(i, cur);
                        }
                        a[a[nd].r].components.clear();
                        a[a[nd].r].components.pb(cur);
                    }
                    // for 0 continue traversing
                    if(a[nd].l != -1) {
                        query(a[nd].l, depth - 1, cur, val);
                    }
                }
                else {
                    if(a[nd].l != -1) {
                        for(auto i : a[a[nd].l].components) {
                            dsu.merge(i, cur);
                        }
                        a[a[nd].l].components.clear();
                        a[a[nd].l].components.pb(cur);
                    }
                    if(a[nd].r != -1)
                        query(a[nd].r, depth - 1, cur, val);
                }
            }
            else {
                // traverse to child
                if((1 << depth) & val) {
                    // go to 1
                    if(a[nd].r != -1)
                        query(a[nd].r, depth - 1, cur, val);
                }
                else {
                    // go to 0
                    if(a[nd].l != -1)
                        query(a[nd].l, depth - 1, cur, val);
                }
            }
		}
	}
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    trie trie;
    trie.m = m;
    for(int i = 30; i >= 0; --i) {
        if((1 << i) & m)
            trie.lsb = i;
    }
    int v[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for(int i = 1; i <= n; ++i) {
        trie.update(0, 30, i, v[i]);
        trie.query(0, 30, i, v[i]);
    }
    for(int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        if(trie.dsu.find_head(x) == trie.dsu.find_head(y))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}