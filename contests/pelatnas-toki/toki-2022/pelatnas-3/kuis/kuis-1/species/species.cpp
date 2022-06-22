#include "species.h"
#include <bits/stdc++.h>
using namespace std;
// bfs order
// left to right
// by depth
const int lim = 1e6 + 5;
vector<pair<int, bool>> child[lim];
int N;
struct node {
    vector<int> idx;
    node *child[2];
};
node *head = new node();
void dfs(int nd, node *nd2) {
    nd2->idx.push_back(nd);
    for(auto i : child[nd]) {
        if(nd2 == head && !i.second) {
            dfs(i.first, head);
        }
        else {
            if(!nd2->child[i.second])
                nd2->child[i.second] = new node();
            dfs(i.first, nd2->child[i.second]);
        }
    }
}
int pr[lim], act[lim];
void init(std::string G, std::vector<int> P) {
    N = G.size();
    for(int i = 1; i < N; ++i)
        child[P[i]].push_back({i, G[i] == 'B'});
    dfs(0, head);    
    queue<node*> q;
    q.push(head);
    int cur_cnt = 0;
    while(q.size()) {
        node *cur = q.front();
        q.pop();
        for(auto i : cur->idx) {
            pr[i] = cur_cnt;
            act[i] = cur_cnt + cur->idx.size();
        }
        cur_cnt += cur->idx.size();
        if(cur->child[0])
            q.push(cur->child[0]);
        if(cur->child[1])
            q.push(cur->child[1]);
    }
}

int count_species(int S, int T) {
    return max(act[S], act[T]) - min(pr[S], pr[T]);
}
