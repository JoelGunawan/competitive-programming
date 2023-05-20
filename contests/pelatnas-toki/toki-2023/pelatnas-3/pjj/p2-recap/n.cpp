#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 3e5 + 5;
map<int, vector<pair<int, int>>> edges;
struct node {
    node *l, *r;
};
void add(node *old, node *cur, int depth, int val) {
    if(depth == -1)
        return;
    if(!old) {
        // just make normal trie
        if((1 << depth) & val) {
            cur->r = new node();
            add(old, cur->r, depth - 1, val);
        }
        else {
            cur->l = new node();
            add(old, cur->l, depth - 1, val);
        }
    }
    else {
        //cout << "TEST" << endl;
        if((1 << depth) & val) {
            cur->r = new node();
            add(old->r, cur->r, depth - 1, val);
            cur->l = old->l;
        }
        else {
            cur->l = new node();
            add(old->l, cur->l, depth - 1, val);
            cur->r = old->r;
        }
    }
}
int query(node *nd, int depth, int val) {
    if(depth == -1)
        return 0;
    //cout << depth << " " << val << endl;
    if(nd->l && nd->r) {
        //cout << "OPT1" << endl;
        if((1 << depth) & val)
            return query(nd->l, depth - 1, val) + (1 << depth);
        else
            return query(nd->r, depth - 1, val) + (1 << depth);
    }
    else if(nd->l) {
        //cout << "OPT2" << endl;
        return query(nd->l, depth - 1, val) + ((1 << depth) & val);
    }
    else {
        //cout << "OPT3" << endl;
        return query(nd->r, depth - 1, val) + (((1 << depth) & val) ^ (1 << depth));
    }
}
map<int, bool> vis;
map<int, node*> head;
void dfs(int nd) {
    vis[nd] = 1;
    //cout << nd << endl;
    for(auto i : edges[nd]) {
        //cout << nd << " " << i.first << endl;
        if(!vis[i.first]) {
            head[i.first] = new node();
            add(head[nd], head[i.first], 30, i.second);
            dfs(i.first);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, r, key;
    cin >> n >> q >> r >> key;
    for(int i = 1; i < n; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        edges[u].push_back({v, k});
        edges[v].push_back({u, k});
    }
    head[r] = new node();
    node *buang = new node();
    add(buang, head[r], 30, key);
    dfs(r);
    //cout << "TEST" << endl;
    int pr = 0;
    for(int qe = 0; qe < q; ++qe) {
        int op;
        cin >> op;
        op ^= pr;
        if(op == 0) {
            int v, u, k;
            cin >> v >> u >> k;
            v ^= pr;
            u ^= pr;
            k ^= pr;
            head[u] = new node();
            add(head[v], head[u], 30, k);
        }
        else {
            int v, k;
            cin >> v >> k;
            v ^= pr;
            k ^= pr;
            int r1 = query(head[v], 30, k), tmp = 0;
            for(int i = 0; i <= 30; ++i) {
                k ^= (1 << i);
            }
            tmp = k;
            int r2 = query(head[v], 30, k);
            for(int i = 0; i <= 30; ++i) 
                r2 ^= 1 << i;
            cout << r2 << " " << r1 << endl;
            pr = r2 ^ r1;
        }
    }
}