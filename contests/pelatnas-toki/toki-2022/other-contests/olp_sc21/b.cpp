#include <bits/stdc++.h>
#define ins insert
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
// use trie
// if delete, just delete every child 
// maintain a set of available nodes
map<int, vector<int>> child;
int res;
map<int, int> par;
map<int, char> color;
struct node {
    int val = 0;
    vector<int> c = vector<int>(26, -1);
};
struct trie_struct {
    vector<node> a = {node()};
    string cur = "";
    void update() {
        //cout << cur << " " << nd << " " << idx << endl;
        int nd = 0, idx = 0;
        while(idx < cur.size()) {
            int tmp = cur[idx] - 'a', &tmp2 = a[nd].c[tmp];
            if(tmp2 == -1) {
                tmp2 = a.size(), a.push_back(node());
            }
            ++a[tmp2].val;
            if(a[tmp2].val == 1)
                ++res;
            nd = tmp2;
            ++idx;
        }
    }
    void del() {
        int nd = 0, idx = 0;
        while(idx < cur.size()) {
            int tmp = cur[idx] - 'a', &tmp2 = a[nd].c[tmp];
            --a[tmp2].val;
            if(a[tmp2].val == 0)
                --res;
            nd = tmp2;
            ++idx;
        }
    }
};
set<int> available;
trie_struct trie;
void dfs(int nd) {
    for(auto i : child[nd])
        dfs(i);
    child[nd].clear();
    string tmp = "";
    while(nd != 1) {
        tmp += color[nd];
        nd = par[nd];
    }
    trie.cur = tmp;
    trie.del();
}
int main() {
    int q;
    scanf("%d" , &q);
    for(int i = 2; i <= q; ++i)
        available.ins(i);
    // pake binlift hashing?
    // each query -> q possible new paths
    // how to add those paths in O(1/logn)?
    // cari first different string dari semua lainnya
    // untuk tiap string addition kita bakal perlu memo sebanyak collision yang kita temuin
    // masalahnya length of stringnya ga sama semua
    // kalo cuma addition query?
    // cari longest common path
    // untuk tiap dimana ada string differing, simpen memo yang menyatakan jumlah 
    // O(n^2), use trie structure normally
    // simpen binlift hash
    for(int i = 0; i < q; ++i) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int u; char c;
            scanf("%d%c", &u, &c);
            int tmp = *available.begin();
            child[u].push_back(tmp);
            color[tmp] = c;
            par[tmp] = u;
            available.erase(available.begin());
            string cur = "";
            cur += c;
            while(u != 1) {
                cur += color[u];
                u = par[u];
            }
            trie.cur = cur;
            trie.update();
        }
        else {
            int nd;
            scanf("%d", &nd);
            // dfs from nd to every child
            // clear everything
            dfs(nd);
            int tmp = par[nd];
            for(int i = 0; i < child[tmp].size(); ++i) {
                if(child[tmp][i] == nd) {
                    child[tmp].erase(child[tmp].begin() + i);
                }
            }
        }
        printf("%d\n", res);
    }
}