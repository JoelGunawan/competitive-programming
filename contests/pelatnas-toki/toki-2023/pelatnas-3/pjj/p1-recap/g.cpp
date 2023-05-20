#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
int low[lim], disc[lim], ti = 0;
bool active[lim];
vector<int> edges[lim];
vector<vector<int>> component;
vector<int> st;
const int pad = 1e5;
void dfs(int nd = 1) {
    low[nd] = disc[nd] = ti++;
    st.push_back(nd);
    active[nd] = 1;
    for(auto i : edges[nd]) {
        if(disc[i] == -1) {
            dfs(i);
            low[nd] = min(low[nd], low[i]);
        }
        else if(active[i]) {
            low[nd] = min(low[nd], disc[i]);
        }
    }
    active[nd] = 0;
    if(low[nd] == disc[nd]) {
        // berarti scc rooted at this
        vector<int> tmp;
        while(st.size()) {
            tmp.push_back(st.back());
            st.pop_back();
            if(tmp.back() == nd)
                break;
        }
        component.push_back(tmp);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    // case 0
    // (a or b) and (not a or not b)
    // a or b becomes
    // not a -> b
    // not b -> a
    // case 1
    // (a or not b) and (not a or b)
    // so trie and you shall succeed :D
    // jk
    // 2 sat moment
    // later scc finding :D
    vector<int> switches[n + 1];
    bool state[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> state[i];
    }
    for(int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        for(int j = 0; j < x; ++j) {
            int idx;
            cin >> idx;
            switches[idx].push_back(i);
        }
    }
    for(int i = 1; i <= n; ++i) {
        // a or b
        // not a -> b
        // not b -> a
        // not set to n + 1e5
        int x = switches[i][0], y = switches[i][1];
        //cout << x << " " << y << endl;
        if(state[i]) {
            // edge dr
            // a -> b
            // not b -> not a
            // not a -> not b
            // b -> a
            edges[x].push_back(y);
            edges[y].push_back(x);
            edges[x + pad].push_back(y + pad);
            edges[y + pad].push_back(x + pad);
        }
        else {
            // edge dr
            // not a -> b
            // not b -> a
            // a -> not b
            // b -> not a
            edges[x].push_back(y + pad);
            edges[y].push_back(x + pad);
            edges[x + pad].push_back(y);
            edges[y + pad].push_back(x);
        }
    }
    memset(disc, -1, sizeof(disc));
    memset(low, -1, sizeof(low));
    for(int i = 1; i <= m; ++i) {
        if(disc[i] == -1)
            dfs(i);
    }
    for(int i = 1 + pad; i <= m + pad; ++i) {
        if(disc[i] == -1)
            dfs(i);
    }
    for(auto &i : component) {
        sort(i.begin(), i.end());
        for(auto j : i) {
            //cout << j << " ";
            if(binary_search(i.begin(), i.end(), j + pad) || binary_search(i.begin(), i.end(), j - pad)) {
                cout << "NO" << endl;
                return 0;
            }
        }
        //cout << endl;
    }
    cout << "YES" << endl;
    return 0;
}