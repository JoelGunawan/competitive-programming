#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
int low[lim], disc[lim], ti;
bool active[lim];
vector<int> edges[lim];
vector<int> st;
vector<vector<int>> ccs;
void dfs(int nd, int pr) {
    low[nd] = disc[nd] = ti++;
    active[nd] = 1;
    st.push_back(nd);
    for(auto i : edges[nd]) {
        if(i == pr)
            continue;
        if(disc[i] == -1) {
            dfs(i, nd);
            low[nd] = min(low[nd], low[i]);
        }
        else if(active[i]) {
            // berarti ini merupakan back edge
            low[nd] = min(low[nd], disc[i]);
        }
    }   
    if(low[nd] == disc[nd]) {
        // berarti tinggal pop sampai nd 
        vector<int> v;
        do {
            v.push_back(st.back())
            st.pop_back();
        } while(v.back() != nd);
        ccs.push_back(v);
    }
}
int main() {
    int n;
    cin >> n;
    
}